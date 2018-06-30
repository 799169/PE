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


struct Problem45 {

	static const int MAXN = 30000;
	IntL x;

	auto solve() {
		for (int a = 144; a < MAXN; ++a) {
			x = a * (2 * a - 1LL);
			if (ok(x)) {
				return x;
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
    Answer: 1533776805
 Time taken:   0.00200s
************************/
