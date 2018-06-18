#include <algorithm>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>


using namespace std;
using namespace chrono;



namespace PrimeUtils {

	const int MAXN = 1e7;

	const int MAXS = MAXN / 3;
	bool sieve[MAXS];

	const int MAXP = MAXN / 10;
	int primes[MAXP];
	int primesCount;

	inline int getNumber(int i) {
		return (i % 2 == 0) ? (6 * (i / 2) + 5) : (6 * (i / 2) + 7);
	}

	inline int getIndex(int n) {
		return ((n - 1) % 6 == 0) ? ((n - 4) / 3) : ((n - 5) / 3);
	}

	void generatePrimes() {
		int j, k;
		for (int i = 0; i < MAXS; ++i) {
			sieve[i] = true;
		}
		for (int i = 0; i < MAXS; ++i) {
			if (sieve[i]) {
				j = getNumber(i);
				if (j * j > MAXN) {
					break;
				}
				if (j % 6 == 1) {
					for (k = j * j; k <= MAXN; k += 6 * j) {
						sieve[getIndex(k)] = false;
						sieve[getIndex(k + 4 * j)] = false;
					}
				} else if (j % 6 == 5) {
					for (k = j * j; k <= MAXN; k += 6 * j) {
						sieve[getIndex(k)] = false;
						sieve[getIndex(k + 2 * j)] = false;
					}
				}
			}
		}
		primes[0] = 2;
		primes[1] = 3;
		primesCount = 2;
		for (int i = 0; i < MAXS; ++i) {
			if (sieve[i]) {
				primes[primesCount] = getNumber(i);
				++primesCount;
			}
		}
		while (primes[primesCount - 1] > MAXN) {
			--primesCount;
		}
	}

}

struct Problem37 {


	static const int MXPW = 7;
	int ten[MXPW];

	auto solve() {
		ten[0] = 1;
		for (int i = 1; i < MXPW; ++i) {
			ten[i] = ten[i - 1] * 10;
		}
		PrimeUtils::generatePrimes();
		vector <int> d1 =  {2, 3, 5, 7};
		vector <int> d2 =  {3, 7, 9};
		vector <int> d3 =  {1, 3, 7, 9};
		int x, s = 0;
		for (auto e1 : d1) {
			for (auto e2 : d2) {
				x = 10 * e1 + e2;
				if (ok(x)) {
					s += x;
				}
				for (auto e3 : d3) {
					x = 100 * e1 + 10 * e3 + e2;
					if (ok(x)) {
						s += x;
					}
					for (auto e4 : d3) {
						x = 1000 * e1 + 100 * e3 + 10 * e4 + e2;
						if (ok(x)) {
							s += x;
						}
						for (auto e5 : d3) {
							x = 10000 * e1 + 1000 * e3 + 100 * e4 + 10 * e5 + e2;
							if (ok(x)) {
								s += x;
							}
							for (auto e6 : d3) {
								x = 100000 * e1 + 10000 * e3 + 1000 * e4 + 100 * e5 + 10 * e6 + e2;
								if (ok(x)) {
									s += x;
								}
							}
						}
					}
				}
			}
		}
		return s;
	}

	bool ok(int n) {
		int t = n, g = 0;
		if (t % 3 == 0) {
			return false;
		}
		if (!PrimeUtils::sieve[PrimeUtils::getIndex(t)]) {
			return false;
		}
		while (t > 0) {
			++g;
			if (t % 3 == 0 && t != 3) {
				return false;
			}
			if (t > 5 && !PrimeUtils::sieve[PrimeUtils::getIndex(t)]) {
				return false;
			}
			t /= 10;
		}
		t = n;
		while (t > 0) {
			if (t % 3 == 0 && t != 3) {
				return false;
			}
			if (!PrimeUtils::sieve[PrimeUtils::getIndex(t)]) {
				return false;
			}
			t = t - (t / ten[g - 1]) * ten[g - 1];
			--g;
		}
		return true;
	}

} solver;


int main() {
	freopen("output.txt", "w+", stdout);
	auto start = high_resolution_clock::now();
	auto ans = solver.solve();
	auto end = high_resolution_clock::now();
	duration <double> diff = end - start;
	cout << setw(12) << " Answer: " << setw(10) << ans;
	cout << "\n Time taken: " << setw(9) << fixed;
	cout << setprecision(5) << diff.count() << "s\n\n";
	return 0;
}

/***********************
    Answer:     748317
 Time taken:   0.05900s
 ************************/
