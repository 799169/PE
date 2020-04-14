namespace Solver {

	const int N=100000, D=1e6;
	int a[N]={1};

	int g(int k) { return k*(3*k-1LL)/2;}

	int p(int n) {nil
		int s=0;
		fr(k, 1, n+1){
			if(g(k)>n)break;
			int t=a[n-g(k)];
			if(g(-k)<=n)t+=a[n-g(-k)];
			if(k&1)	s+=t; else s-=t;
			if(s<0)s+=D;
			if(s<0)s+=D;
			if(s>D)s-=D;
			if(s>D)s-=D;
		}
		if(s<0)s+=D;
		if(s<0)s+=D;
		if(s>D)s-=D;
		if(s>D)s-=D;
		return a[n]=s;
	}

	bool solve(int testNumber) {
		fr(i, 1, N)if(p(i)==0)return prl(i);
		// fr(i, 1, 100)prl(p(i));
		return prl();
	}
