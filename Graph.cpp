#include <algorithm>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef LOCAL
	#include "DebugUtils.h"
#endif




struct Graph {

	static const int N = 10;
	vector <int> adj[N];
	bool visited[N];
	int ancestor[N];

	Graph() {

	}

	void addEdge(int i, int j) {
		addDirectedEdge(i, j);
		addDirectedEdge(j, i);
	}

	void addDirectedEdge(int i, int j) {
		adj[i].push_back(j);
	}

	void dfs() {
		for (int k = 0; k < N; ++k) {
			visited[k] = false;
		}
		for (int k = 0; k < N; ++k) {
			if (!visited[k]) {
				ancestor[k] = k;
				dfs(k);
			}
		}
	}

	void dfs(int i) {
		visited[i] = true;
		for (auto e : adj[i]) {
			if (!visited[e]) {
				ancestor[e] = i;
				dfs(e);
			}
		}
	}

	bool hasPath(int i, int j) {
		for (int k = 0; k < N; ++k) {
			visited[k] = false;
		}
		dfs(i);
		return visited[j];
	}

	void printPath(int i, int j) {
		ancestor[i] = i;
		while (ancestor[j] != i) {
			cout << j << " <- ";
			j = ancestor[j];
		}
	}

	void print() {
		for (int i = 0; i < N; ++i) {
			if (!adj[i].empty()) {
				cout << i << " : ";
				for (int j = 0; j < adj[i].size(); ++j) {
					cout << adj[i][j] << ' ';
				}
				cout << '\n';
			}
		}
	}

	void bfs() {
		for (int i = 0; i < N; ++i) {
			visited[i] = false;
			ancestor[i] = i;
		}
		for (int i = 0; i < N; ++i) {
			bfs(i);
		}
	}

	void bfs(int i) {

	}

} solver;


int main() {
	#ifdef LOCAL
		freopen("output.txt", "w+", stdout);
		freopen("input.txt", "r", stdin);
	#endif
	Graph g;
	return 0;
}
