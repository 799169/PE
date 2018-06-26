#include <algorithm>
#include <chrono>
#include <cmath>
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


// [5, 6, 11, 13, 17, 19, 23, 25, ...]

namespace PrimeUtils {

	const int MAXN = 1e5;

	const int MAXS = MAXN / 3;
	bool sieve[MAXS];

	const int MAXP = MAXN / 10;
	int primes[MAXP];
	int primesCount;

	inline int getNumber(int i) {
		return 6 * (i >> 1) + 2 * (i & 1) + 5;
	}

	inline int getIndex(int n) {
		return ((n - 1) % 6 == 0) ? ((n - 4) / 3) : ((n - 5) / 3);
	}

	void generatePrimes() {
		int i, j, k;
		for (i = 0; i < MAXS; ++i) {
			sieve[i] = true;
		}
		for (i = 0; i < MAXS; ++i) {
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
		if (n % 2 == 0 || n % 3 == 0) {
			return n == 2 || n == 3;
		}
		for (int i = 1; i < n; ++i) {
			int j = 6 * i - 1;
			int k = 6 * i + 1;
			if (j * j > n) {
				return true;
			}
			if (n % j == 0 || n % k == 0) {
				return false;
			}
		}
		return true;
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

		for (int i = 0; i < primeFactorCount; ++i) {
			printf("%d:%d \n", primeFactors[i], powers[i]);
		}
		printf("\n");
	}

	int totalFactorCount(int n) {
		int r = 1;
		for (int i = 0; i < primeFactorCount; ++i) {
			r *= (powers[i] + 1);
		}
		return r;
	}

	int a[MAXP];

	void iterateThroughFactors(int n) {
		int z = PrimeUtils::totalFactorCount(n);
		int y = PrimeUtils::primeFactorCount;
		printf("z=%d y=%d\n", z, y);
		int m = 1, j;
		for (int x = 0; x < PrimeUtils::primeFactorCount; ++x) {
			a[x] = 0;
		}
		for (int x = 0; x < z / 2; ++x) {
			printf("%d  ", m);
			j = y - 1;
			++a[j];
			m *= PrimeUtils::primeFactors[j];
			while (a[j] > PrimeUtils::powers[j] && j >= 0) {
				a[j] = 0;
				for (int w = 0; w <= PrimeUtils::powers[j]; ++w) {
					m /= PrimeUtils::primeFactors[j];
				}
				--j;
				++a[j];
				m *= PrimeUtils::primeFactors[j];
			}
		}
		if (z % 2 == 1) {
			printf("%d", (int) sqrt(n));
		}
		printf("\n");
	}

};


using namespace PrimeUtils;

int main() {
	freopen("output.txt", "w+", stdout);
	generatePrimes();
	auto N = 49;
	primeFactorize(N);
	iterateThroughFactors(N);
	return 0;
}
