namespace Solver {

	Long countR(int a, int b) {
		int c=0;
		// fr(m, 1, a+1)fr(n, 1, b+1)c+=(a-m+1)*(b-n+1);
		// return c;
		return a*b*(a+1LL)*(b+1)/4;
	}

	IntPair closest(int n) {
		int low=1, high=3000, mn=INF, area=0;
		while (low<=high) {nil
			int mid=(low+high)/2;Long c=countR(n, mid);
			if(c>2e6) {
				high=mid-1;
				if(minimize(mn, c-2e6))area=n*mid;
			}else {
				low=mid+1;
				if(minimize(mn, 2e6-c))area=n*mid;
			}
		}
		return mp(mn, area);
	}

	bool solve(int testNumber) {
		auto ans=mp(INF, 0);
		rf(i, 53, 1)minimize(ans, closest(i));
		return prl(ans.second);
	}

