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

	const int MAXTEN = 10, MAXDIGIT = 9;
	IntL ten[MAXTEN + 1];
	bool pandigital[MAXDIGIT + 1];

	void generateTen() {
		ten[0] = 1LL;
		for (int i = 1; i <= MAXTEN; ++i) {
			ten[i] = ten[i - 1] * 10LL;
		}
	}

	int length(IntL n) {
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

	bool isPandigital(IntL n) {
		int d;
		for (int i = 1; i <= MAXDIGIT; ++i) {
			pandigital[i] = false;
		}
		while (n > 0) {
			d = n % 10;
			if (d == 0 or pandigital[d]) {
				return false;
			}
			pandigital[d] = true;
			n /= 10;
		}
		for (int i = 1; i <= MAXDIGIT; ++i) {
			if (!pandigital[i]) {
				return false;
			}
		}
		return true;
	}

	inline IntL concatenate(IntL x, IntL y) {
		return x * ten[length(y)] + y;
	}


}
struct Problem38 {

	auto solve() {
		IntL mx = 918273645L, x;
		IntegerUtils::generateTen();
		for (IntL i = 91; i < 100; ++i) {
			x = IntegerUtils::concatenate(i, 2 * i);
			x = IntegerUtils::concatenate(x, 3 * i);
			x = IntegerUtils::concatenate(x, 4 * i);
			if (IntegerUtils::isPandigital(x)) {
				mx  = max(x, mx);
			}
		}
		for (IntL i = 921; i < 1000; ++i) {
			x = IntegerUtils::concatenate(i, 2 * i);
			x = IntegerUtils::concatenate(x, 3 * i);
			if (IntegerUtils::isPandigital(x)) {
				mx  = max(x, mx);
			}
		}
		for (IntL i = 9213; i < 10000; ++i) {
			x = IntegerUtils::concatenate(i, 2 * i);
			if (IntegerUtils::isPandigital(x)) {
				mx  = max(x, mx);
			}
		}
		return mx;
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
    Answer:  932718654
 Time taken:   0.00100s
************************/
