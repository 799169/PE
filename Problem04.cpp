#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>

using namespace std;
using namespace chrono;


namespace IntegerUtils {

	int reverseInt(int n) {
		int r = n;
		r = 0;
		while (n > 0) {
			r = (r * 10) + (n % 10);
			n /= 10;
		}
		return r;
	}

	int lengthInt(int n) {
		if (n == 0) {
			return 1;
		}
		int r = 0;
		while (n > 0) {
			n /= 10;
			++r;
		}
		return r;
	}

};


namespace PrimeUtils {

	const int MAXN = 1e3;

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

	void primeFactorize(int n) {
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

	int totalFactorCount() {
		int r = 1;
		for (int i = 0; i < primeFactorCount; ++i) {
			r *= (powers[i] + 1);
		}
		return r;
	}

};


struct Problem4 {

	auto solve() {
		PrimeUtils::generatePrimes();
		int x;
		for (int i = 999; i >= 900; --i) {
			x = (i * 1000) + IntegerUtils::reverseInt(i);
			if (has3DigitFactors(x)) {
				return x;
			}
		}
		return -1;
	}

	int a[PrimeUtils::MAXP];

	bool has3DigitFactors(int n) {
		PrimeUtils::primeFactorize(n);
		int z = PrimeUtils::totalFactorCount();
		int y = PrimeUtils::primeFactorCount;
		int m = 1, j, b1, b2;
		for (int x = 0; x < PrimeUtils::primeFactorCount; ++x) {
			a[x] = 0;
		}
		for (int x = 0; x < z / 2; ++x) {
			b1 = IntegerUtils::lengthInt(m);
			b2 = IntegerUtils::lengthInt(n / m);
			if (b1 == 3 && b2 == 3) {
				return true;
			}
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
		if (z % 2 == 1 && IntegerUtils::lengthInt(sqrt(n)) == 3) {
			return true;
		}
		return false;
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

/**********************
    Answer:     906609
 Time taken:   0.00000s
***********************/
