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


struct Problem29 {

	auto solve() {
		const int B = 100, A = 2;
		bool x[B + 1], y[B + 1];
		for (int i = 0; i <= B; ++i) {
			y[i] = false;
		}
		int c = (B - A + 1) * (B - A + 1), p, t, s, z;
		for (int i = 2; i * i <= B; ++i) {
			p = 1;
			for (int j = i * i; j <= B; j *= i) {
				++p;
				if (y[i]) {
					continue;
				}
				y[j] = true;
				for (int k = A; k <= B; ++k) {
					x[k] = false;
				}
				for (int k = 1; k < p; ++k) {
					for (int h = A; h <= B; h += 1) {
						if ((k * h) % p == 0) {
							x[k * h / p] = true;
						}
					}
				}
				for (int k = A; k <= B; ++k) {
					if (x[k]) {
						--c;
					}
				}
			}
		}
		return c;
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
    Answer:       9183
 Time taken:   0.00000s
 ***********************/
