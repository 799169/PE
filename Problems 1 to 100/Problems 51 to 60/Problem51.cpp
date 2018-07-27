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

typedef long long Long;
typedef vector <int> IntVector;


namespace PrimeUtils {

	const int MAXN = 1e4;

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

	int p;

	bool isPrime(int n) {
		if (n % 2 == 0 or n % 3 == 0 or n < 5) {
			return n == 2 or n == 3;
		}
		for (int i = 0; i < primesCount; ++i) {
			p = primes[i];
			if (p * p > n) {
				return true;
			}
			if (n % p == 0) {
				return false;
			}
		}
		return true;
	}

}

using PrimeUtils::isPrime;



struct Problem51 {


	IntVector a1 =  {1, 3, 7, 9};

	int p4[10] = {
		1110, 10110, 11010, 11100, 100110,
		101010, 101100, 110010, 110100, 111000
	};

	double p3[10] =  {
		1e5, 1e5, 1e5, 1e5, 1e4, 1e4, 1e4, 1e3, 1e3, 1e2
	};

	double p2[10] =  {
		1e4, 1e3, 1e2, 1e1, 1e3, 1e2, 1e1, 1e2, 1e1, 1e1
	};

	int d2, d3, d4, i, c, b, x;

	auto solve() {
		PrimeUtils::generatePrimes();
		for (int d1 : a1) {
			for (d2 = 0; d2 <= 9; ++d2) {
				for (d3 = 0; d3 <= 9; ++d3) {
					for (i = 0; i < 10; ++i) {
						c = 2;
						b = 1;
						for (d4 = 0; d4 <= 9; ++d4) {
							x = d1 + d2 * p2[i] + d3 * p3[i] + d4 * p4[i];
							if (x < 1e5 or !isPrime(x)) {
								--c;
								if (c < 0) {
									b = 0;
									break;
								}
							}
						}
						if (b == 1) {
							for (d4 = 0; d4 <= 9; ++d4) {
								x = d1 + d2 * p2[i] + d3 * p3[i] + d4 * p4[i];
								if (isPrime(x)) {
									return x;
								}
							}
						}
					}
				}
			}
		}
		return -1;
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

/************************
    Answer:     121313
 Time taken:   0.00000s
************************/
