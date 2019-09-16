#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N,M;
vector<vector<pair<ll,ll> > > node;

int main() {
	cin >> N >> M;
	node=vector<vector<pair<ll,ll>>>(N);
	for(int i=0;i<M;i++)
	{
		int a,b,x;
		cin >> a >> b >> x;
		a--, b--;
		node[a].push_back(b, -x);
		node[b].push_back(a, x);
	}
}
