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
#include <vector>


using namespace std;
using namespace chrono;


namespace PrimeUtils {

	const int MAXN = 1e3;

	const int MAXS = MAXN / 3;
	bool sieve[MAXS];

	const int MAXP = MAXN / 5;
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

struct Problem27 {

	const int N = 1000;
	int mxa = 1, mxb = 41, mxc = 40, c, p;

	auto solve() {
		PrimeUtils::generatePrimes();
		for (int i = 0; i < PrimeUtils::primesCount; ++i) {
			p = PrimeUtils::primes[i];
			if (p < mxc) {
				continue;
			}
			for (int a = -1 * N + 1; a < N; a += 2) {
				c = countPrimes(a, p);
				if (c > mxc) {
					mxc = c;
					mxa = a;
					mxb = p;
				}
				c = countPrimes(a, -p);
				if (c > mxc) {
					mxc = c;
					mxa = a;
					mxb = -p;
				}
			}
		}
		return mxa * mxb;
	}


	int countPrimes(int a, int b) {
		int x;
		for (int i = 1; i < N; ++i) {
			x = i * i + a * i + b;
			if (!PrimeUtils::sieve[PrimeUtils::getIndex(x)]) {
				return i;
			}
		}
		return N;
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
    Answer:     -59231
 Time taken:   0.00300s
***********************/
