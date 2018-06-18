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


namespace IntegerUtils  {

	int lengthInt(auto n) {
		if (n == 0) {
			return 1;
		}
		int r = 0;
		while (n > 0) {
			++r;
			n /= 10;
		}
		return r;
	}

}

namespace PrimeUtils {

	const int MAXN = 1e6;

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

struct Problem35 {

	bool checked[PrimeUtils::MAXS];
	static const int MXPW = 7;
	int ten[MXPW];

	auto solve() {
		const int N = 1e6;
		PrimeUtils::generatePrimes();
		int p, t, s, r;
		set <int> cp;
		ten[0] = 1;
		for (int i = 1; i < MXPW; ++i) {
			ten[i] = ten[i - 1] * 10;
		}
		for (int i = 0; i < PrimeUtils::MAXS; ++i) {
			checked[i] = false;
		}
		for (int i = 0; i < PrimeUtils::primesCount; ++i) {
			p = PrimeUtils::primes[i];
			if (p > 100 && !checked[PrimeUtils::getIndex(p)] && ok(p)) {
				cp.insert(p);
			}
		}
		for (int e : cp) {
			r = IntegerUtils::lengthInt(e);
			t = e;
			for (int q = 1; q < r; ++q) {
				s = t / ten[r - 1];
				t = (t - ten[r - 1] * s) * 10 + s;
				cp.insert(t);
			}
		}
		return cp.size() + 13;
	}


	bool ok(int n) {
		int r = 0, d, t = n, s;
		checked[PrimeUtils::getIndex(n)] = true;
		while (t > 0) {
			d = t % 10;
			if (d % 2 == 0 || d == 5) {
				return false;
			}
			++r;
			t /= 10;
		}
		t = n;
		for (int i = 1; i < r; ++i) {
			s = t / ten[r - 1];
			t = (t - ten[r - 1] * s) * 10 + s;
			if (!PrimeUtils::sieve[PrimeUtils::getIndex(t)]) {
				return false;
			}
			checked[PrimeUtils::getIndex(t)] = true;
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
    Answer:         55
 Time taken:   0.00800s
 ***********************/
