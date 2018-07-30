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

    const int MAXN = 1e4 + 10;

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

    bool isPrime(Long n) {
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
using PrimeUtils::primes;

namespace IntegerUtils {

    const int MAXTEN = 18;
    Long ten[MAXTEN + 1];

    void generateTen() {
        ten[0] = 1;
        for (int i = 1; i <= MAXTEN; ++i) {
            ten[i] = ten[i - 1] * 10;
        }
    }

    int length(Long n) {
        if (n == 0) {
            return 1;
        }
        int r = 0;
        while (n > 0) {
            ++r;
            n /= 10;
        }
        return r;
    }

    Long concatenate(Long x, Long y) {
        return x * ten[length(y)] + y;
    }

}

using IntegerUtils::concatenate;

struct Problem60 {

    auto solve() {
        PrimeUtils::generatePrimes();
        IntegerUtils::generateTen();
        int a, b, c, d, e, i, g, n = PrimeUtils::primesCount;
        for (a = 1; a < n; ++a) {
            for (b = a + 1; b < n; ++b) {
                if (!ok(primes[a], primes[b])) {
                    continue;
                }
                for (c = b + 1; c < n; ++c) {
                    if (!ok(primes[c], primes[a])) {
                        continue;
                    }
                    if (!ok(primes[c], primes[b])) {
                        continue;
                    }
                    for (d = c + 1; d < n; ++d) {
                        if (!ok(primes[d], primes[a])) {
                            continue;
                        }
                        if (!ok(primes[d], primes[b])) {
                            continue;
                        }
                        if (!ok(primes[d], primes[c])) {
                            continue;
                        }
                        for (e = d + 1; e < n; ++e) {
                            if (!ok(primes[e], primes[a])) {
                                continue;
                            }
                            if (!ok(primes[e], primes[b])) {
                                continue;
                            }
                            if (!ok(primes[e], primes[c])) {
                                continue;
                            }
                            if (!ok(primes[e], primes[d])) {
                                continue;
                            }
                            return primes[a] + primes[b] + primes[c] + primes[d] + primes[e];
                        }
                    }
                }
            }
        }
        return -1;
    }

    bool ok(Long x, Long y) {
        return isPrime(concatenate(x, y)) and isPrime(concatenate(y, x));
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
    Answer:      26033
 Time taken:   0.40702s
************************/
