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

using namespace std;
using namespace chrono;

#define all(x) begin(x), end(x)

typedef long long Long;
typedef long double LongDouble;
typedef vector <int> IntVector;


struct Problem55 {

    static const int N = 100;
    int a[N], b[N], z, n, nn, i, ii, j, p, c = 0;

    auto solve() {
        for (n = 1; n < 10000; ++n) {
            for (i = 0; i < N; ++i) {
                a[i] = 0;
                b[i] = 0;
            }
            i = N - 1, nn = n;
            while (nn > 0) {
                a[i] = nn % 10;
                nn /= 10;
                --i;
            }
            z = 1;
            for (ii = 0; ii < 50; ++ii) {
                j = 0;
                while (a[j] == 0) {
                    ++j;
                }
                i = N - 1;
                while (j < N) {
                    b[i] = a[j];
                    ++j;
                    --i;
                }
                for (i = N - 1; i > 0; --i) {
                    a[i] += b[i];
                    if (a[i] >= 10) {
                        a[i] -= 10;
                        ++a[i - 1];
                    }
                }
                i = 0;
                while (a[i] == 0) {
                    ++i;
                }
                j = N - 1;
                p = 1;
                while (i < j) {
                    if (a[i] != a[j]) {
                        p = 0;
                        break;
                    }
                    ++i;
                    --j;
                }
                if (p == 1) {
                    z = 0;
                    break;
                }
            }
            if (z == 1) {
                ++c;
            }
        }
        return c;
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
    Answer:        249
 Time taken:   0.01600s
************************/
