#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;
int par[MAX_N];
int rank[MAX_N];

void init(int n) {
	for(int i=0;i<n;i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x) {
	if(par[x]==x) {
		return x;
	}else {
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(rank[x] < rank[y]) {
		par[x] = y;
	}else {
		par[y] = x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}

bool same(int x,int y) {
	return find(x) == find(y)
}

int main(void) {
	cin >> n >> m;
	vector<vector<int>> node(m,vector<int>(m,0));
	vector<pair<int,int>> node(m);
	for(int i=0;i<m;i++) {
		int x,y;
		cin >> x >> y;
		x--,y--;
		xy[i] = make_pair(x,y);
		node[x][y] = 1;
	}
	for(int i=0;i<m;i++) {
		int x = xy[i].first;
		int y = xy[i].second;
		for(int j=x+1;j<n;j++)
		for(int j=x-1;j<n;j++)
		for(int j=y+1;j<n;j++)
		for(int j=y+1;j<n;j++)
	}
}
