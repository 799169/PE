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


namespace IntegerUtils {

	int lengthInt(int n) {
		if (n == 0) {
			return 1;
		}
		int r = 0;
		while (n > 0) {
			++r;
			n /= 10;
		}
		return r;
	}

}

struct Problem17 {

	const int N  = 1000;
	vector <string> a =  {
		"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
		"NINE", "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN",
		"FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"
	};
	vector <string> b = {
		"TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"
	};
	map <int, int> m;
	int h = string("HUNDREDAND").size();

	auto solve() {
		for (int i = 0; i < a.size(); ++i) {
			m[i + 1] = a[i].size();
		}
		for (int i = 0; i < b.size(); ++i) {
			m[(i + 2) * 10] = b[i].size();
		}
		int s = string("ONETHOUSAND").size();
		for (int i = 1; i < N; ++i) {
			s += letters(i);
		}
		return s;
	}

	int letters(int n) {
		if (m[n] > 0) {
			return m[n];
		}
		int x = IntegerUtils::lengthInt(n);
		if (x == 3) {
			if (n % 100 == 0) {
				return m[n / 100] + string("HUNDRED").size();
			}
			return letters(n % 100) + m[n / 100] + h;
		}
		return m[(n / 10) * 10] + m[n % 10];
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
    Answer:      21124
 Time taken:   0.00000s
 ************************/
