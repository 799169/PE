#include <bits/stdc++.h>

#ifdef LOCAL_DEFINE
	#include "DebugUtils.h"
#endif	


using namespace std;

using Long = long long;
using LD = long double;




struct Solver {

	void solve() {
		int t = 1;
		// cin >> t;
		for (int i = 1; i <= t; ++i) {
			solve(t);
		}
	}



	void solve(int testNumber) {

		return;
	}

} solver;


int main() {
	#ifdef LOCAL_DEFINE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w+", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
	#endif	
	auto t1 = chrono::high_resolution_clock::now();
	solver.solve();
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> t = t2 - t1;
	#ifdef LOCAL_DEFINE
		cout << "\nTime taken: " << fixed;
		cout << setprecision(5) << t.count() << "s\n\n";
	#endif
	return 0;
}

