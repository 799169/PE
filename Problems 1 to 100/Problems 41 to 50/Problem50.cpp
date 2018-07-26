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

#ifdef LOCAL
	#include "DebugUtils.h"
#endif

using namespace std;
using namespace chrono;

typedef long long Long;


namespace PrimeUtils {

	const int MAXN = 6e4;

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

using PrimeUtils::primes;

struct Problem50 {

	static const int N = 1e6;
	int n, i, j, p;
	Long a[N], s;

	auto solve() {
		PrimeUtils::generatePrimes();
		n = PrimeUtils::primesCount;
		a[0] = 0;
		for (i = 1; i <= n; ++i) {
			a[i] = a[i - 1] + primes[i - 1];
		}
		for (i = n; i >= 21; --i) {
			for (j = 1; j + i <= n; ++j) {
				s = a[j + i] - a[j - 1];
				if (s < 1e6 and PrimeUtils::isPrime(s)) {
					return s;
				}
			}
		}
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
    Answer:     997651
 Time taken:   0.19401s
************************/
