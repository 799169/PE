#include <algorithm>
#include <chrono>
#include <cmath>
#include <cassert>
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
#include <tuple>
#include <vector>

#ifdef LOCAL
	#include "DebugUtils.h"
#endif

using namespace std;
using namespace chrono;

typedef long long IntL;
typedef vector <int> IntV;
typedef vector <bool> BoolV;


struct Problem44 {

	static const int MAXN = 2000;
	IntL x, y, z;

	auto solve() {
		for (int a = 1; a < MAXN; ++a) {
			for (int b = 1; b < MAXN; ++b) {
				x = a * (3 * a - 1LL) / 2;
				y = b * (3 * b - 1LL) / 2;
				if (ok(x + y) && ok(x + 2 * y)) {
					return x;
				}
			}
		}
		return -1LL;
	}

	bool ok(IntL n) {
		IntL m  = (sqrt(24 * n + 1) + 1) / 6;
		return m * (3 * m - 1) / 2 == n;
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
    Answer:    5482660
 Time taken:   0.22001s
************************/
