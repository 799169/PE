namespace Solver {

	Long sqr(Long n) {
		return n*n;
	}
	Long pow4(Long n) {
		return sqr(sqr(n));
	}
	Long pow3(Long n) {
		return n*sqr(n);
	}

	const int N=50e6;
	bitset<N> a;
	int aaa=100;

	bool solve(int testNumber) {
		generatePrimes();
		rp(i, numOfPrimes) {
			Long s=pow4(primes[i]);
			if(s>=N)break;
			rp(j, numOfPrimes) {
				Long ss=s+pow3(primes[j]);
				if(ss>=N)break;
				rp(k, numOfPrimes) {
					Long sss=ss+sqr(primes[k]);
					if(sss>=N)break;
					// if(s<50)tr(s, primes[i], primes[j], primes[k]);
					// if(primes[i]==2 and primes[j]==2 and primes[k]==5)tr(s)
					a[sss]=1;
				}

			}
		}
		return prl(a.count());
	}
