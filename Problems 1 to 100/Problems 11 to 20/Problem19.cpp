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


struct Problem19 {

	auto solve() {
		vector <int> v =  {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};
		int day = 0, c = 0;
		for (int y = 1900; y <= 2000; ++y) {
			for (int m = 0; m < 12; ++m) {
				day += v[m];
				if (m == 1 && isLeapYear(y)) {
					++day;
				}
				day %= 7;
				if (y >= 1901 && day == 6) {
					++c;
				}
			}
		}
		return c;
	}

	inline bool isLeapYear(int y) {
		return (y % 400 == 0) ? true : (y % 100 == 0) ? false : (y % 4 == 0) ? true : false;
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
    Answer:        171
 Time taken:   0.00000s
 ***********************/
