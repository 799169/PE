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


struct Problem22 {

	auto solve() {
		ifstream f("names.txt");
		string s;
		f >> s;
		stringstream ss;
		vector <string> v;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				ss << s[i];
			} else if (s[i] == ',') {
				v.push_back(ss.str());
				ss.str("");
				ss.clear();
			}
		}
		v.push_back(ss.str());
		sort(begin(v), end(v));
		auto x = 0LL, sm = 0LL;
		for (int i = 0; i < v.size(); ++i) {
			sm = 0;
			for (auto &e : v[i]) {
				sm += (e - 'A' + 1);
			}
			x += (i + 1) * sm;
		}
		return x;
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
    Answer:  871198282
 Time taken:   0.01100s
***********************/
