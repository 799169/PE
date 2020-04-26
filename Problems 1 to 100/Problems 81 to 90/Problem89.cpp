
namespace Solver {

	const int N=2e5+10, M=510;
	string s = "IVXLCDM";
	int n=sz(s);
	IntVector v={1, 5, 10, 50, 100, 500, 1000};
	map<char, int> mm;

	int eval(string t) {
		int m=sz(t), ans=0;
		frr(i, 0, m-1) {
			if(t[i]=='M' or t[i]=='D' or t[i]=='L' or t[i]=='V'){ans+=mm[t[i]];continue;}
			if(t[i]=='C') {
				if(i<=m-2 and t[i+1]=='D'){ans+=400;++i;continue;};
				if(i<=m-2 and t[i+1]=='M'){ans+=900;++i;continue;};
				ans+=100;continue;
			}
			if(t[i]=='X') {
				if(i<=m-2 and t[i+1]=='L'){ans+=40;++i;continue;};
				if(i<=m-2 and t[i+1]=='C'){ans+=90;++i;continue;};
				ans+=10;continue;
			}
			if(t[i]=='I') {
				if(i<=m-2 and t[i+1]=='V'){ans+=4;++i;continue;};
				if(i<=m-2 and t[i+1]=='X'){ans+=9;++i;continue;};
				ans+=1;continue;
			}
		}
		return ans;
	}

	int minway(int x) {
		IntVector v2={0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
		int ans=v2[x%10]+v2[(x/10)%10]+v2[(x/100)%10]+(x/1000);
		return ans;
	}

	bool solve(int testNumber) {
		fr(i, n)mm[s[i]]=v[i];
		freopen("p089_roman.txt", "r", stdin);
		ios_base::sync_with_stdio(1);int ans=0;
		string ss;while (cin>>ss) {
			ans+=sz(ss)-minway(eval(ss));
		}
		tr(ans);
		return 1;
	}
