#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;


namespace IntegerUtils {

	auto APsum(auto a, auto d, auto n) {
		return n * (2 * a + n * d - d) / 2;
	}

};

struct Problem1 {

	auto solve() {
		auto N = 1000LL;
		auto n3 = (N - 1) / 3;
		auto n5 = (N - 1) / 5;
		auto n15 = (N - 1) / 15;
		auto s3 = IntegerUtils::APsum(3LL, 3LL, n3);
		auto s5 = IntegerUtils::APsum(5LL, 5LL, n5);
		auto s15 = IntegerUtils::APsum(15LL, 15LL, n15);
		return s3 + s5 - s15;
	}

} solver;

int main() {
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
    Answer:     233168
 Time taken:   0.00000s
***********************/
