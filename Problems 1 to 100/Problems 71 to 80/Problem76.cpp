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
		for (int j = 2; j <= i; ++j) {
			dp[i][j] = dp[i][j - 1];
			int k;
			for (k = 1; i - k * j >= 2; ++k) {
				dp[i][j] += dp[i - k * j][min(i - k * j, j - 1)];
			}
			if (i - k * j >= 0) {
				++dp[i][j];
			}
		}
		dp[i][i] = dp[i][i - 1] + 1;
	}
	tr(dp[N][N] - 1);
	return;
}
