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
#include <sstream>
#include <string>
#include <tuple>
#include <vector>


using namespace std;
using namespace chrono;


struct Problem26 {

	static const int N = 1000;
	bool b[N];

	auto solve() {
		int mxn = 7, mxc = 6, c;
		for (int i = 8; i < N; ++i) {
			c = cycleLength(i);
			if (c > mxc) {
				mxc = c;
				mxn = i;
			}
		}
		return mxn;
	}

	int cycleLength(int n) {
		int x = 1, c = 0;
		while (x < n) {
			x *= 10;
		}
		for (int i = 0; i < n; ++i) {
			b[i] = false;
		}
		for (int i = 0; i < n; ++i) {
			if (b[x % n]) {
				return c;
			}
			b[x % n] = true;
			x = (x % n) * 10;
			++c;
		}
		return -1;
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

/***********************
    Answer:        983
 Time taken:   0.00100s
 ***********************/
