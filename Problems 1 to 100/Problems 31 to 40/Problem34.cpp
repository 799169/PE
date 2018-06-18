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



struct Problem34 {

	static const int D = 9;
	int f[D + 1];

	auto solve() {
		int s = 0;
		f[0] = 1;
		for (int i = 1; i <= D; ++i) {
			f[i] = f[i - 1] * i;
		}
		int MXN = f[D] * 7;
		for (int n = 11; n <= MXN; ++n) {
			if (ok(n)) {
				s += n;
			}
		}
		return s;
	}

	bool ok(int n) {
		int s = 0, t = n;
		while (t > 0) {
			s += f[t % 10];
			if (s > n) {
				return false;
			}
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
    Answer:      40730
 Time taken:   0.07401s
***********************/
