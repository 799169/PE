
struct UnionFind {

	static const int N = 10;
	int id[N], rank[N];

	UnionFind() {
		for (int i = 0; i < N; ++i) {
			id[i] = i;
			rank[i] = 0;
		}
	}

	int root(int i) {
		while (id[i] != i) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}

	void connect(int i, int j) {
		int x = root(i);
		int y = root(j);
		if (rank[x] < rank[y]) {
			id[x] = y;
		} else if (rank[x] > rank[y]) {
			id[y] = x;
		} else {
			++rank[x];
			id[y] = x;
		}
	}

	bool connected(int i, int j) {
		return root(i) == root(j);
	}

	vector <int> a[N];

	void print() {
		for (int i = 0; i < N; ++i) {
			a[i].clear();
		}
		for (int i = 0; i < N; ++i) {
			a[root(i)].push_back(i);
		}
		for (int i = 0; i < N; ++i) {
			if (!a[i].empty()) {
				cout << i << " : ";
				for (int j = 0; j < a[i].size(); ++j) {
					cout << a[i][j] << ' ';
				}
				cout << '\n';
			}
		}
	}

};




int main() {
	#ifdef LOCAL
		freopen("output.txt", "w+", stdout);
		freopen("input.txt", "r", stdin);
	#endif
	UnionFind uf;
	uf.connect(4, 3);
	uf.connect(3, 8);
	uf.connect(6, 5);
	uf.connect(9, 4);
	uf.connect(2, 1);
	printf("%d\n", uf.connected(0, 7));
	printf("%d\n", uf.connected(8, 9));
	uf.connect(5, 0);
	uf.connect(7, 2);
	uf.connect(6, 1);
	uf.connect(1, 0);
	printf("%d\n", uf.connected(0, 7));
	uf.print();
	return 0;
}
