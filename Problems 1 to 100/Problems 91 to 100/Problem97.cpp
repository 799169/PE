const Long MOD = 1e10L, M = 1e5;

Long N = 1e9;

Long powMul(Long a, Long b) {
	Long a2 = a % M, b2 = b % M;
	Long a1 = (a - a2) / M, b1 = (b - b2) / M;
	Long s1 = a1 * b2 * M, s2 = a2 * b1 * M, s3 = a2 * b2;
	return (s1 + s2 + s3) % MOD;
}

Long powMod(Long x, int y) {
	Long ans = 1;
	while (y > 0) {
		if (y & 1) {
			--y;
			ans = powMul(ans, x);
			ans %= MOD;
		}
		y >>= 1;
		x = powMul(x, x);
	}
	return ans;
}


void solve() {
	Long z = powMod(2, 7830457);
	Long ans = (powMul(z, 28433) + 1) % MOD;
	tr(ans);
	return;
}
