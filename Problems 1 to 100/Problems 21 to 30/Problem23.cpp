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


struct Problem23 {

	auto solve() {
		const int N = 28123 + 1;
		int a[N], b[N], c[N], d = 0;
		auto s = 0LL;
		a[0] = 0;
		a[1] = 0;
		for (int i = 2; i < N; ++i) {
			a[i] = 1;
		}
		for (int i = 2; i < N / 2; ++i) {
			for (int j = 2 * i; j < N; j += i) {
				a[j] += i;
			}
		}
		for (int i = 2; i < N; ++i) {
			if (a[i] > i) {
				b[d] = i;
				++d;
			}
		}
		for (int i = 1; i < N; ++i) {
			c[i] = false;
		}
		for (int i = 0; i < d; ++i) {
			for (int j = 0; j < d; ++j) {
				if (b[i] + b[j] < N) {
					c[b[i] + b[j]] = true;
				}
			}
		}
		for (int i = 1; i < N; ++i) {
			if (!c[i]) {
				s += i;
			}
		}
		return s;
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
    Answer:    4179871
 Time taken:   0.07300s
***********************/
