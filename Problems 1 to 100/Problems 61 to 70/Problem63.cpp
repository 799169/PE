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


struct Problem63 {

    LongDouble a, n, c, ans;

    auto solve() {
        ans = 9;
        for (a = 2; a <= 9; ++a) {
            c = 1 / log10(10 / a);
            for (n = 2; n <= c + 1; ++n) {
                if (floor(n * log10(a)) + 1 == n) {
                    ++ans;
                }
            }
        }
        return ans;
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
    Answer:         49
 Time taken:   0.00000s
************************/
