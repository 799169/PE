	const int N=1e6;
	int a[N+1];

	bool solve(int testNumber) {
		fr(i, 2, N+1)a[i]=i;
		fr(i, 2, N+1)if(a[i]==i)for (int j = i; j <= N; j+=i) {
			a[j] -= a[j]/i;
		}
		Long ans=0;fr(i, 2, N+1)ans+=a[i];return println(ans);
	}

// 303963552391
// Time taken: 0.03128s

