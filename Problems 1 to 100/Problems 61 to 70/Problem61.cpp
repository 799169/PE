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
typedef vector <IntPair> IntPairVector;


struct Problem61 {

    static const int N = 1e4;
    int i, j, n, ans[6], s = 0;
    bool c[N], u[6];
    IntVector v[6];
    map <IntPair, IntPairVector> m;

    auto solve() {
        fill(u, u + 6, false);
        fill(c, c + N, false);
        for (i = 0; i < 6; ++i) {
            for (j = 1; j < 150; ++j) {
                n = j * ((i + 1) * j - i + 1) / 2;
                if (n >= 1e4) {
                    break;
                }
                if (n >= 1e3) {
                    v[i].push_back(n);
                }
            }
        }
        for (i = 0; i < 6; ++i) {
            for (j = 0; j < 6; ++j) {
                if (i == j) {
                    continue;
                }
                for (int x : v[i]) {
                    for (int y : v[j]) {
                        if (x == y) {
                            continue;
                        }
                        if (ok(x, y)) {
                            m[make_pair(x, i)].push_back(make_pair(y, j));
                        }
                        if (ok(y, x)) {
                            m[make_pair(y, j)].push_back(make_pair(x, j));
                        }
                    }
                }
            }
        }
        for (const auto &e : m) {
            if (!u[e.first.second] and !c[e.first.first]) {
                if (dfs(e.first, 0)) {
                    for (i = 0; i < 6; ++i) {
                        s += ans[i];
                    }
                    return s;
                }
            }
        }
        return 1;
    }

    bool ok(const int x, const int y) {
        return (x % 100) == (y / 100);
    }

    bool dfs(const IntPair &x, int d) {
        c[x.first] = true;
        u[x.second] = true;
        ans[d] = x.first;
        if (d == 5) {
            if (ok(x.first, ans[0])) {
                return true;
            }
            c[x.first] = false;
            u[x.second] = false;
            return false;
        }
        for (const auto &e : m[x]) {
            if (u[e.second] or c[e.first]) {
                continue;
            }
            if (dfs(e, d + 1)) {
                return true;
            }
        }
        c[x.first] = false;
        u[x.second] = false;
        return false;
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
    Answer:      28684
 Time taken:   0.00100s
************************/
