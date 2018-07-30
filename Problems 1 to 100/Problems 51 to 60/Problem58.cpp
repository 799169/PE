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
#include <vector>

#ifdef LOCAL
    #include "DebugUtils.h"
#endif

using namespace std;
using namespace chrono;

#define all(x) begin(x), end(x)

typedef long long Long;
typedef long double LongDouble;
typedef vector <int> IntVector;


namespace PrimeUtils {

    const int MAXN = 1e5 + 10;

    const int MAXS = MAXN / 3;
    bool sieve[MAXS];

    const int MAXP = MAXN / 10;
    int primes[MAXP];
    int primesCount;

    int i, j, k, p;

    inline int getNumber(int i) {
        return (i % 2 == 0) ? (6 * (i / 2) + 5) : (6 * (i / 2) + 7);
    }

    inline int getIndex(int n) {
        return ((n - 1) % 6 == 0) ? ((n - 4) / 3) : ((n - 5) / 3);
    }

    void generatePrimes() {
        fill(sieve, sieve + MAXS, true);
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

struct Problem58 {

    auto solve() {
        PrimeUtils::generatePrimes();
        LongDouble p = 0, n = 1;
        Long i, j;
        for (i = 3; i < 1e6; i += 2) {
            for (j = 0; j < 4; ++j) {
                if (isPrime(i * (i - j) + j)) {
                    ++p;
                }
                ++n;
            }
            if (p / n < 0.10L) {
                return i;
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
    Answer:      26241
 Time taken:   0.11901s
************************/
