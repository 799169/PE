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


struct Problem59 {

    auto solve() {
        IntVector v;
        char c, key[3], ans[3];
        int x = 0, e = 0, i, mxe = 0, j, k, y, w = 0;
        ifstream in("cipher.txt", ios::in);
        while (in >> c) {
            if (c == ',') {
                v.push_back(x);
                x = 0;
            } else {
                x = (x * 10) + (c - '0');
            }
        }
        v.push_back(x);
        for (i = 0; i < 26; ++i) {
            for (j = 0; j < 26; ++j) {
                for (k = 0; k < 26; ++k) {
                    key[0] = i + 'a';
                    key[1] = j + 'a';
                    key[2] = k + 'a';
                    y = 0;
                    e = 0;
                    for (int z : v) {
                        if ((key[y] ^ z) == ' ') {
                            ++e;
                        }
                        ++y;
                        if (y == 3) {
                            y = 0;
                        }
                    }
                    if (e > mxe) {
                        mxe = e;
                        ans[0] = key[0];
                        ans[1] = key[1];
                        ans[2] = key[2];
                    }
                }
            }
        }
        y = 0;
        for (int z : v) {
            w += z ^ ans[y];
            ++y;
            if (y == 3) {
                y = 0;
            }
        }
        return w;
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
    Answer:     107359
 Time taken:   0.04200s
************************/
