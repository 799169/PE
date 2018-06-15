#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <map>

using namespace std;
using namespace chrono;


struct Problem6 {

	auto solve() {
		auto N = 100LL;
		return N * (N + 1) * (N * (3 * N - 1) - 2) / 12;
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
    Answer:   25164150
 Time taken:   0.00000s
***********************/
