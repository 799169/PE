#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;
using namespace chrono;

namespace PrimeUtils {

	const int MAXN = 2e6 - 1;

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
    }

};


struct Problem10 {

	auto solve() {
		PrimeUtils::generatePrimes();
		const int N = 2e6;
		auto s = 5LL, x = 0LL;
		for (int i = 0; i < PrimeUtils::MAXS; ++i) {
			if (PrimeUtils::sieve[i]) {
				x = PrimeUtils::getNumber(i);
				if (x >= N) {
					break;
				}
				s += x;
			}
		}
		return s;
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
    Answer: 142913828922
 Time taken:    0.00600s
************************/
