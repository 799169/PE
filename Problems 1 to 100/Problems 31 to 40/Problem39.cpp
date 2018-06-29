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


namespace IntegerUtils {

	int gcd(int a, int b) {
		int c = a;
		while (b > 0) {
			c = a;
			a = b;
			b = c % b;
		}
		return a;
	}

}


struct Problem39 {

	static const int MAXP = 1e3;
	static const int MAXM = sqrt(MAXP / 3);
	int z[MAXP + 1];

	auto solve() {
		for (int i = 0; i <= MAXP; ++i) {
			z[i] = 0;
		}
		int mxp = 120, mxc = 3, a, b, c, p;
		for (int m = 2; m <= MAXM; ++m) {
			for (int n = 1; n < m; ++n) {
				a = m * m - n * n;
				b = 2 * m * n;
				c = m * m + n * n;
				if (IntegerUtils::gcd(a, b) == 1) {
					p = a + b + c;
					for (int k = 1; k * p <= MAXP; ++k) {
						++z[k * p];
						if (z[k * p] > mxc) {
							mxc = z[k * p];
							mxp = k * p;
						}
					}
				}
			}
		}
		return mxp;
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
    Answer:        840
 Time taken:   0.00000s
************************/
