namespace Solver {

	const int L=1500000;
	bitset<L+1> can, multiple;

	bool solve(int testNumber) {
		fr(n, 1, 900)fr(m, n+1, 900) {
			int a=m*m-n*n, b=2*m*n, c=m*m+n*n;int s=a+b+c;
			if(s>L)break;
			if(gcd(a, b)==1) {
				fr(i, 1, L){
					if(i*s>L)break;
					if(can[i*s])multiple[i*s]=1;
					can[i*s]=1;
				}
			}
		}
		int ans=0;
		fr(i, 12, L+1)if(can[i] and !multiple[i]) {
			++ans;
		}
		return prl(ans);
	}

// 161667

// Time taken: 0.04686s

