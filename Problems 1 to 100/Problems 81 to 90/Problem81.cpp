const int N = 80;
Long a[N][N], dp[N][N];


void solve() {
	ifstream in("p081_matrix.txt");
	char c;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			in >> a[i][j];
			if (j < N - 1) {
				in >> c;
			}
		}
	}
	dp[0][0] = a[0][0];
	for (int j = 1; j < N; ++j) {
		dp[0][j] = a[0][j] + dp[0][j - 1];
	}
	for (int i = 1; i < N; ++i) {
		dp[i][0] = dp[i - 1][0] + a[i][0];
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			// tr(i, j, dp[i][j]);
		}
	}
	tr(dp[N - 1][N - 1]);
	cout << endl;
	return;
}
