#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <string>

using namespace std;
using namespace chrono;


namespace PrimeUtils {

	const int MAXN = 2e4;

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

};

struct Problem12 {

	const int D = 500;
	map <int, int> a[PrimeUtils::MAXN], m;

	auto solve() {
		PrimeUtils::generatePrimes();
		int X = PrimeUtils::MAXN;
		int C = PrimeUtils::primesCount;
		int p, q, r, d;
		for (int i = 0; i < C; ++i) {
			p = PrimeUtils::primes[i];
			q = p;
			r = 1;
			while (q < X) {
				for (int j = q; j < X; j += q) {
					a[j][p] = r;
				}
				q *= p;
				++r;
			}
		}
		auto Y = 10000LL;
		for (auto &e : a[Y - 1]) {
			m.insert(e);
		}
		for (auto n = Y; n < X; ++n) {
			for (auto &e : a[n])  {
				m[e.first] += e.second;
			}
			--m[2];
			d = 1;
			for (auto &e : m) {
				d *= (e.second + 1);
			}
			++m[2];
			if (d > 500) {
				return n * (n - 1) / 2;
			}
			for (auto e : a[n - 1]) {
				m[e.first] -= e.second;
				if (m[e.first] == 0) {
					m.erase(e.first);
				}
			}
		}
		return -1LL;
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
    Answer:   76576500
 Time taken:   0.00900s
************************/
