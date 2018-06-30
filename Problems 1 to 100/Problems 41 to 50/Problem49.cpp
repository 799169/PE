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
typedef vector <int> IntV;
typedef vector <bool> BoolV;


namespace IntegerUtils {

	const int D = 9;
	int f[D + 1];

	bool isPermutation(int x, int y) {
		for (int i = 0; i <= D; ++i) {
			f[i] = 0;
		}
		while (x > 0) {
			++f[x % 10];
			x /= 10;
		}
		while (y > 0) {
			--f[y % 10];
			y /= 10;
		}
		for (int i = 0; i <= D; ++i) {
			if (f[i] != 0) {
				return false;
			}
		}
		return true;
	}

}

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

}

struct Problem49 {

	static const int D = 9;
	bool b[D];
	stringstream ss;

	auto solve() {
		int p, q;
		PrimeUtils::generatePrimes();
		for (int i = 0; i < PrimeUtils::primesCount; ++i) {
			p = PrimeUtils::primes[i];
			if (p < 1000 || p == 1487) {
				continue;
			}
			for (int j = i + 1; j < PrimeUtils::primesCount; ++j) {
				q = PrimeUtils::primes[j];
				if (2 * q - p >= 10000) {
					break;
				}
				if (PrimeUtils::sieve[PrimeUtils::getIndex(2 * q - p)]) {
					if (IntegerUtils::isPermutation(p, 2 * q - p)) {
						if (IntegerUtils::isPermutation(p, q)) {
							ss << p << q << (2 * q - p);
							return ss.str();
						}
					}
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
    Answer: 296962999629
 Time taken:   0.00900s
************************/
