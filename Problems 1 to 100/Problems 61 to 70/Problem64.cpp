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
typedef set <int> IntSet;
typedef set <Long> LongSet;
typedef vector <IntPair> IntPairVector;


namespace IntegerUtils {

    Long c;

    Long gcd(Long a, Long b) {
        a = abs(a);
        b = abs(b);
        c = a;
        while (b > 0) {
            c = a;
            a = b;
            b = c % b;
        }
        return a;
    }

    Long gcd(Long a, Long b, Long c) {
        return gcd(a, gcd(b, c));
    }

}

using IntegerUtils::gcd;


struct Problem64 {

    Long a, b, c, d, g, i, aa, bb, cc, dd, x, ans = 0;
    IntVector v;
    map < tuple <int, int, int>, bool > m;

    auto solve() {
        for (x = 1; x <= 1e4; ++x) {
            a = 0;
            b = 1;
            c = 1;
            m.clear();
            m[make_tuple(a, b, c)] = true;
            dd = d = floor((b * sqrt(x) + a) / c);
            if (dd * dd == x) {
                continue;
            }
            v.clear();
            for (i = 0; i < 1e6; ++i) {
                aa = a;
                bb = b;
                cc = c;
                dd = d;
                a = cc * (aa - cc * d);
                b = -bb * cc;
                c = sqr(aa - cc * d) - bb * bb * x;
                g = gcd(a, b, c);
                d = floor((b * sqrt(x) + a) / c);
                a /= g;
                b /= g;
                c /= g;
                if (m[make_tuple(a, b, c)]) {
                    break;
                } else {
                    m[make_tuple(a, b, c)] = true;
                }
                v.push_back(d);
            }
            if (v.size() % 2 == 1) {
                ++ans;
            }
        }
        return ans;
    }

    Long sqr(Long x) {
        return x * x;
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
    Answer:       1322
 Time taken:   0.18301s
************************/
