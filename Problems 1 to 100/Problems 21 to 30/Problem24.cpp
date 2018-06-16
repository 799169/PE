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


struct Problem24 {

	auto solve() {
		const int N = 1e6;
		int n = N;
		string s = "0123456789";
		string ans = "", t;
		int x, y, p;
		while (n > 1) {
			x = 1;
			y = 2;
			while (x * y < n) {
				x *= y;
				++y;
			}
			p = n / x;
			if (n % x == 0) {
				--p;
				n -= x;
			} else {
				n -= x * (n / x);
			}
			ans += s[p];
			t = s.substr(0, p) + s.substr(p + 1);
			s = t;
		}
		return ans + s;
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
    Answer:  2783915460
 Time taken:   0.00000s
***********************/
