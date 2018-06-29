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

typedef long long IntL;


namespace PrimeUtils {

	const int MAXN = 1e5;

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

	bool isPrime(int n) {
		int p;
		for (int i = 0; i < primesCount; ++i) {
			p = primes[i];
			if (p * p > n) {
				return true;
			}
			if (n % p == 0) {
				ff=p;
				return false;
			}
		}
		return true;
	}


}

namespace IntegerUtils {

	const int MAXTEN = 10;
	IntL ten[MAXTEN + 1];
	void generateTen() {
		ten[0] = 1LL;
		for (int i = 1; i <= MAXTEN; ++i) {
			ten[i] = ten[i - 1] * 10LL;
		}
	}

	const int MAXFACTORIAL = 10;
	IntL factorial[MAXFACTORIAL + 1];
	void generateFactorial() {
		factorial[0] = 1LL;
		for (int i = 1; i <= MAXFACTORIAL; ++i) {
			factorial[i] = factorial[i - 1] * i;
		}
	}

}


struct Problem41 {

	static const int MAXN = 7;
	int a[MAXN];

	auto solve() {
		for (int i = 0; i < MAXN; ++i) {
			a[i] = MAXN - i;
		}
		IntegerUtils::generateFactorial();
		IntegerUtils::generateTen();
		PrimeUtils::generatePrimes();
		for (int f = 1; f < IntegerUtils::factorial[MAXN]; ++f) {
			int x = makeNumber();
			if (PrimeUtils::isPrime(x)) {
				return x;
			}
			int i = MAXN - 1;
			while (i > 0 && a[i - 1] < a[i]) {
				--i;
			}
			int c = a[i - 1];
			int k = i;
			for (int j = i + 1; j < MAXN; ++j) {
				if (a[j] < c && c - a[j] < c - a[k]) {
					k = j;
				}
			}
			a[i - 1] = a[k];
			a[k] = c;
			reverse(a + i, a + MAXN);
		}
		return -1;
	}

	int makeNumber() {
		int x = 0;
		for (int i = 0; i < MAXN; ++i) {
			x += a[i] * IntegerUtils::ten[MAXN - i - 1];
		}
		return x;
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
    Answer:    7652413
 Time taken:   0.00000s
************************/
