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


struct Problem32 {


	auto solve() {
		int s = 0;
		set <int> x;
		for (int b = 1234; b <= 9876; ++b) {
			int a = 1;
			while (b * a <= 9876) {
				if (ok(a, b, a * b)) {
					x.insert(a * b);
				}
				++a;
			}
		}
		for (int b = 123; b <= 987; ++b) {
			int a = 12;
			while (b * a <= 9876) {
				if (ok(a, b, a * b)) {
					x.insert(a * b);
				}
				++a;
			}
		}
		for (auto e : x) {
			s += e;
		}
		return s;
	}

	static const int N = 9;
	int x[N + 1];

	bool ok(int a, int b, int c) {
		for (int i = 1; i <= N; ++i) {
			x[i] = false;
		}
		while (a > 0) {
			if (x[a % 10]) {
				return false;
			}
			x[a % 10] = true;
			a /= 10;
		}
		while (b > 0) {
			if (x[b % 10]) {
				return false;
			}
			x[b % 10] = true;
			b /= 10;
		}
		while (c > 0) {
			if (x[c % 10]) {
				return false;
			}
			x[c % 10] = true;
			c /= 10;
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
    Answer:      45228
 Time taken:   0.00100s
 ***********************/
