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


struct Problem30 {

	auto solve() {
		const int P = 5, MXD = 6;
		int MXN = pow(9, P) * MXD, s = 0;
		for (int i = 10; i < MXN; ++i) {
			if (satisfies(i)) {
				s += i;
			}
		}
		return s;
	}

	bool satisfies(int n) {
		int s = 0, t = n;
		while (t > 0) {
			s += pow(t % 10, 5);
			t /= 10;
		}
		return s == n;
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
    Answer:     443839
 Time taken:   0.32202s
***********************/
