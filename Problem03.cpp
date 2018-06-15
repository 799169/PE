#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;


struct Problem3 {

	auto solve() {
		auto n = 600851475143LL;
		auto x = 1LL, j = 0LL, k = 0LL;
		if (n % 3 == 0) {
			x = 3;
			while (n % 3 == 0) {
				n /= 3;
			}
		}
		for (auto i = 1LL; i < n; ++i) {
			j = 6 * i - 1;
			k = 6 * i + 1;
			if (j * j > n) {
				break;
			}
			if (n % j == 0) {
				x = j;
				while (n % j == 0)  {
					n /= j;
				}
			}
			if (n % k == 0) {
				x = k;
				while (n % k == 0)  {
					n /= k;
				}
			}
		}
		return (n > 1) ? n : x;
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
    Answer:       6857
 Time taken:   0.00000s
***********************/
