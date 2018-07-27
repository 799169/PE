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

using namespace std;
using namespace chrono;

typedef long long Long;
typedef vector <int> IntVector;

namespace IntegerUtils {

	const int D = 9;
	int f[D + 1], i;

	bool isPermutation(int x, int y) {
		for (i = 0; i <= D; ++i) {
			f[i] = 0;
		}
		while (x > 0) {
			++f[x % 10];
			x /= 10;
		}
		while (y > 0) {
			--f[y % 10];
			if (f[y % 10] < 0) {
				return false;
			}
			y /= 10;
		}
		for (i = 0; i <= D; ++i) {
			if (f[i] != 0) {
				return false;
			}
		}
		return true;
	}

}


using IntegerUtils::isPermutation;


struct Problem52 {

	int i, j;

	auto solve() {
		for (i = 1e1; i * 6 < 1e2; ++i) {
			if (ok(i)) {
				return i;
			}
		}
		for (i = 1e2; i * 6 < 1e3; ++i) {
			if (ok(i)) {
				return i;
			}
		}
		for (i = 1e3; i * 6 < 1e4; ++i) {
			if (ok(i)) {
				return i;
			}
		}
		for (i = 1e4; i * 6 < 1e5; ++i) {
			if (ok(i)) {
				return i;
			}
		}
		for (i = 1e5; i * 6 < 1e6; ++i) {
			if (ok(i)) {
				return i;
			}
		}

	}

	bool ok(int x) {
		for (j = 2; j <= 6; ++j) {
			if (!isPermutation(x, j * x)) {
				return false;
			}
		}
		return true;
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
    Answer:     142857
 Time taken:   0.00200s
************************/
