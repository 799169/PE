namespace Solver {

	const int N=80, D=1e6;
	priority_queue<tuple<int, int, int>> pq;
	int a[80][80];
	bool visited[80][80];

	bool ok(int x, int y) {
		return (x>=0)and(y>=0)and(x<N)and(y<N);
	}

	bool solve(int testNumber) {
		ifstream ff("p082_matrix.txt");
		rp(i, 80) {
			string s;ff>>s;
			for(char& c:s)if(c==',')c=' ';
			stringstream ss(s);
			rp(j, 80)ss>>a[i][j];
		}
		int ans=INF;
		pq.emplace(-a[0][0], 0, 0);
		rp(_, 100000) {
			if(pq.empty())break;
			auto [d, x, y]=pq.top();pq.pop();d=-d;visited[x][y]=1;
			if(mp(x, y)==mp(N-1, N-1))return prl(d);
			if(ok(x, y+1) and !visited[x][y+1])pq.emplace(-(d+a[x][y+1]), x, y+1);
			if(ok(x-1, y) and !visited[x-1][y])pq.emplace(-(d+a[x-1][y]), x-1, y);
			if(ok(x+1, y) and !visited[x+1][y])pq.emplace(-(d+a[x+1][y]), x+1, y);
			if(ok(x, y-1) and !visited[x][y-1])pq.emplace(-(d+a[x][y-1]), x, y-1);
		}
		return prl();
	}

