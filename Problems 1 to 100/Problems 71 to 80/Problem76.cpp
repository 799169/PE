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



/*
Other good solutions from the forum:
 int[][] a = new int[n+1][n+1];
        int i, j, k;
        for (i = 0; i < a.length; i++) {
            a[i][0] = 0; a[0][i] = 1;
        }
        for (i = 1; i<a.length; i++){
            a[i][1] = 1;
            for (j = 2; j<a[0].length; j++){
                k = i - j;
                if (k<0) a[i][j] = a[i][j-1];
                else a[i][j] = a[i][j-1] + a[k][j];
            }
        }
        answer = a[i][i-1];

///////////////

public static void main(String args[])
{
		long i, j;
		long[] way = new long [101];

		way[0] = 1;
		for(i = 99; i >= 1; i--)
			for(j = i; j <= 100; j++)
				way[j] += way[j - i];

		System.out.println(way[100]);
}

*/
