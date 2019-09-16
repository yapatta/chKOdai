#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S,O;
ll N;
const ll MOD = 1e9+7;
/*
const ll MAX_N = 3e9;
ll par[MAX_N];
ll rank[MAX_N];
string v[MAX_N];

void init(ll n)
{
	v = "";
	for(int i =0;i<n;i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x)
{
	if(par[x]==x){
		return x;
	}else {
		return par[x] = find(par[x]);
	}
}
void unite(int x,int y) {
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(rank[x] < rank[y]) {
		par[x] = y;
	}else {
		par[y] = x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
}
bool same(int x, int y) {
	return find(x)==find(y);
}
*/

int main() {
	cin >> S >> O >> N;
	ll allsize = N + S.size() + N + O.size();
	vector<vector<int> > node(allsize/2+1);
	//init(allsize);
	
	// 初期化
	for(ll i = 0;i<N;i++) {
		if(i>allsize-1-i) break;
		node[i].push_back(allsize-1-i);
	}
	ll hogezaki = N + S.size();
	for(int i=0;i<N;i++) {
		node[i].push_back(hogezaki+i);
		node[i].push_back(allsize-hogezaki-1-i);
	}
	ll ans = 1;
	vector<bool> used(allsize,false);
	for(int i=0;i<allsize/2+1;i++)
	{
		if(used[i] == true) continue;
		if(O.size()-1-i >= 0) {
			ans *= 1;
			if(used[i] || used[hogezaki+i] || 			(allsize-hogezaki-1-i >= 0 and
used[allsize-hogezaki-1-i])) {
				cout << 0 << endl;
				return 0;
			}
			used[i] = true;
			used[hogezaki+i] = true;
			if(allsize-hogezaki-1-i >= 0)
				used[allsize-hogezaki-1-i] = true;
		}else if(N <= i and i <= hogezaki){
			ans *= 1;
			used[i] = true;
			used[hogezaki+i] = true;
			if(allsize-hogezaki-1-i >= 0)
				used[allsize-hogezaki-1-i] = true;
		}else {
			ans *= 27;
			used[i] = true;
			used[hogezaki+i] = true;
			if(allsize-hogezaki-1-i >= 0)
				used[allsize-hogezaki-1-i] = true;
		}
		ans %= MOD;
	}
	cout << ans << endl;
}
