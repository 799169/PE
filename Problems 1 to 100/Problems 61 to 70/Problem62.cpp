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
typedef pair <int, int> IntPair;
typedef vector <int> IntVector;
typedef vector <Long> LongVector;
typedef vector <IntPair> IntPairVector;


namespace IntegerUtils {

    int i, r;
    const int D = 9;
    int f[D + 1];

    int length(Long n) {
        if (n == 0) {
            return 1;
        }
        r = 0;
        while (n > 0) {
            ++r;
            n /= 10;
        }
        return r;
    }

    bool isPermutation(Long x, Long y) {
        for (i = 0; i <= D; ++i) {
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
        for (i = 0; i < D; ++i) {
            if (f[i] != 0) {
                return false;
            }
        }
        return true;
    }

}

using IntegerUtils::length;
using IntegerUtils::isPermutation;

struct Problem62 {

    static const int N = 1e4;
    LongVector v[18];
    Long i, j, n;
    int x1, x2, x3, x4, x5;

    auto solve() {
        for (i = 1; i < N; ++i) {
            n = i * i * i;
            v[length(n)].push_back(n);
        }
        for (i = 3; i < 18; ++i) {
            j = v[i].size();
            for (x1 = 0; x1 < j; ++x1) {
                for (x2 = x1 + 1; x2 < j; ++x2) {
                    if (!isPermutation(v[i][x1], v[i][x2])) {
                        continue;
                    }
                    for (x3 = x2 + 1; x3 < j; ++x3) {
                        if (!isPermutation(v[i][x1], v[i][x3])) {
                            continue;
                        }
                        for (x4 = x3 + 1; x4 < j; ++x4) {
                            if (!isPermutation(v[i][x1], v[i][x4])) {
                                continue;
                            }
                            for (x5 = x4 + 1; x5 < j; ++x5) {
                                if (isPermutation(v[i][x1], v[i][x5])) {
                                    return v[i][x1];
                                }
                            }
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
    Answer: 127035954683
 Time taken:   3.77222s
************************/

// Better way is to use map with sorted digits of cube as key, and count 5 occurrences
