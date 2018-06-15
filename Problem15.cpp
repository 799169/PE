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
#include <sstream>
#include <string>
#include <tuple>


using namespace std;
using namespace chrono;


namespace PrimeUtils {

	const int MAXN = 1e2;

	const int MAXS = MAXN / 3;
	bool sieve[MAXS];

	const int MAXP = MAXN / 4;
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

	int powers[MAXP];
	int primeFactors[MAXP];
	int primeFactorCount;

	void primeFactorize(auto n) {
		primeFactorCount = 0;
		for (int i = 0; i < MAXP; ++i) {
			powers[i] = 0;
		}
		int p;
		for (int i = 0; i < primesCount; ++i) {
			p = primes[i];
			if (p * p > n) {
				break;
			}
			if (n % p == 0) {
				primeFactors[primeFactorCount] = p;
				++powers[primeFactorCount];
				n /= p;
				while (n % p == 0) {
					n /= p;
					++powers[primeFactorCount];
				}
				++primeFactorCount;
			}
		}
		if (n > 1) {
			primeFactors[primeFactorCount] = n;
			++powers[primeFactorCount];
			++primeFactorCount;
		}
	}

};

namespace CombinatoricsUtils {

	auto nCk(int n, int k) {
		int p;
		map <int, int> m;
		for (int i = n; i > k; --i) {
			PrimeUtils::primeFactorize(i);
			for (int j = 0; j < PrimeUtils::primeFactorCount; ++j) {
				p = PrimeUtils::primeFactors[j];
				m[p] += PrimeUtils::powers[j];
			}
		}
		for (int i = 2; i <= n - k; ++i) {
			PrimeUtils::primeFactorize(i);
			for (int j = 0; j < PrimeUtils::primeFactorCount; ++j) {
				p = PrimeUtils::primeFactors[j];
				m[p] -= PrimeUtils::powers[j];
			}
		}

		auto x = 1LL;
		for (auto &e : m) {
			for (int k = 0; k < e.second; ++k) {
				x *= e.first;
			}
		}
		return x;
	}

}


struct Problem15 {

	auto solve() {
		const int N = 20;
		PrimeUtils::generatePrimes();
		return CombinatoricsUtils::nCk(2 * N, N);
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
    Answer: 137846528820
 Time taken:   0.00000s
************************/
