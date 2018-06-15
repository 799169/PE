#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;
using namespace chrono;


struct Problem9 {

	auto solve() {
		const int X = 1000;
		int SQRTX = sqrt(X);
		auto a = 1LL, b = 1LL, c = 1LL;
		auto s = 1LL, n = 1LL, z = 1LL;
		for (auto m = 2LL; m < SQRTX; ++m) {
			n = 1 + (m % 2);
			while (n < m) {
				a = m * m - n * n;
				b = 2 * m * n;
				c = m * m + n * n;
				s = a + b + c;
				if (X % s == 0) {
					z = X / s;
					return z * z * z * a * b * c;
				}
				n += 2;
			}
		}
		return -1LL;
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

/**********************
    Answer:   31875000
 Time taken:   0.00000s
***********************/
