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


namespace IntegerUtils {

	auto gcd(auto a, auto b) {
		auto c = a;
		while (b > 0) {
			c = a;
			a = b;
			b = c % b;
		}
		return a;
	}

}

struct Problem33 {

	auto solve() {
		const int N = 9;
		int y = 1, z = 1;
		for (int a = 1; a <= N; ++a) {
			for (int b = 1; b <= N; ++b) {
				if (a == b) {
					continue;
				}
				for (int x = 1; x <= N; ++x) {
					if (x * (10 * a - b) == 9 * a * b) {
						y *= a;
						z *= b;
					}
				}
			}
		}
		return z / IntegerUtils::gcd(y, z);
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
    Answer:        100
 Time taken:   0.00000s
 ***********************/
