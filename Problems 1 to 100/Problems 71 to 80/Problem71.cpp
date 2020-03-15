#include "DebugUtils.cpp"


void solve() {
	int N = 1e6;
	LD best = 0;
	int ans;
	for (int d = 2; d <= N; ++d) {
		if (d % 7 == 0) {
			continue;
		}
		LD cur = ((3 * d) / 7)  / (d + 0.0L);
		if (cur > best) {
			best = cur;
			ans = d;
		}
	}
	ans = ((3 * ans) / 7);
	tr(ans);
	return;
}

int main() {
	#ifdef LOCAL_DEFINE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w+", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
	auto t1 = chrono::high_resolution_clock::now();
	solve();
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> t = t2 - t1;
	#ifdef LOCAL_DEFINE
		cout << "\nTime taken: " << fixed;
		cout << setprecision(5) << t.count() << "s\n\n" << endl;
	#endif
	return 0;
}


ans=428570 

Time taken: 0.00000s
