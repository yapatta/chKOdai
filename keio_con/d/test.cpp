#include <bits/stdc++.h>

#define ll long long

using namespace std;

int par[10001];
int rank_aa[10001];

void init(int n)
{
	for(int i=0;i<n;i++){
		par[i] = i;
		rank_aa[i] = 0;
	}
}

int find(int x)
{
	if (par[x]==x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rank_aa[x] < rank_aa[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if (rank_aa[x] == rank_aa[y]) rank_aa[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

struct edge{ll u, v, cost;};

bool comp(const edge& x, const edge& y){
	return x.cost < y.cost;
}

edge es[10001];
ll V, E;

int main() {
	while(cin>>V>>E, V>0){
		for(int i=0; i<E; i++){
			int s, t, c; cin>>s>>t>>c;
			es[i].u = s-1;
			es[i].v = t-1;
			es[i].cost = c;
		}
		sort(es, es+E, comp);
		init(V);
		vector<int> ans;
		for(int i=0; i<E; i++){
			edge e = es[i];
			if (!same(e.u, e.v)){
				unite(e.u, e.v);
				ans.push_back(e.cost);
			}
		}
		ll mid;
		mid = ans[ans.size()/2];
		cout << mid << "\n";
	}
	return 0;
}
