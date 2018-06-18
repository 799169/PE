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


struct Problem36 {

	static const int MXL = 100;
	int binary[MXL];

	auto solve() {
		const int N = 1e6;
		auto s = 0LL, x = 0LL;
		for (int i = 1; i <= 9; i += 2) {
			if (ok(i)) {
				s += i;
			}
			x = i * 10 + i;
			if (ok(x)) {
				s += x;
			}
			for (int j = 0; j <= 9; ++j) {
				x = i * 100 + j * 10 + i;
				if (ok(x)) {
					s += x;
				}
				x = i * 1000 + j * 100 + j * 10 + i;
				if (ok(x)) {
					s += x;
				}
				for (int k = 0; k <= 9; ++k) {
					x = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
					if (ok(x)) {
						s += x;
					}
					x = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i;
					if (ok(x)) {
						s += x;
					}
				}
			}
		}
		return s;
	}

	bool ok(int n) {
		int t = n;
		for (int i = 0; i < MXL; ++i) {
			binary[i] = 0;
		}
		int i = 0;
		while (n > 0) {
			if (n & 1) {
				binary[i] = 1;
			}
			n >>= 1;
			++i;
		}
		for (int j = 0; j < i / 2; ++j) {
			if (binary[j] != binary[i - j - 1]) {
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

/***********************
    Answer:     872187
 Time taken:   0.00100s
************************/
