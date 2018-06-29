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

	int length(int n) {
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

	int getDigit(int n, int d) {
		while (d > 1) {
			n /= 10;
			--d;
		}
		return n % 10;
	}

}


struct Problem39 {

	static const int MAXN = 1e6;

	auto solve() {
		int x = 1;
		for (int t = 1; t <= MAXN; t *= 10) {
			x *= digit(t);
		}
		return x;
	}

	int digit(int n) {
		int i = 1, m = 9;
		while (i * m < n) {
			n -= i * m;
			++i;
			m *= 10;
		}
		int x = (n - 1) / i;
		int y = m / 9 + x;
		int z = (n - 1) % i;
		return IntegerUtils::getDigit(y, IntegerUtils::length(y) - z);
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
    Answer:        210
 Time taken:   0.00000s
 ************************/
