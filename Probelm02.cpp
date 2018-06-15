#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;


struct Problem2 {

	auto solve() {
		auto N = 4000000LL;
		auto a = 0LL, b = 2LL, c = 8LL;
		auto s = 0LL;
		while (a <= N) {
			s += a;
			a = b;
			b = c;
			c = 4 * b + a;
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

/**********************
    Answer:    4613732
 Time taken:   0.00000s
***********************/
