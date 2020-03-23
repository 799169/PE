const int N = 100;

Long dp[N + 1][N + 1];

/*
dp[i][j] = number of ways to represent i as a sum of integers, 
			with all integers in the sum <= j
			Allow 5 = 5 as a sum, and then subtract 1 from answer
*/

void solve() {
	for (int i = 2; i <= N; ++i) {
		dp[i][1] = 1;
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 2; j <= N; ++j) {
			dp[i][j] = dp[i][j - 1];
			if (j == i) {
				++dp[i][j];
			}
			if (j >= i) {
				continue;
			}
			int k = 1;
			while (i - k * j >= 2) {
				dp[i][j] += dp[i - k * j][j - 1];
				++k;
			}
			if (i - k * j >= 0) {
				// tr(i, j, k);
				++dp[i][j];
			}
		}
	}
	for (int i = 2; i < 6; ++i) {
		prl(i, ts(dp[i], 1, 5));
	}
	tr(dp[N][N] - 1);
	return;
}
