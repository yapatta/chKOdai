#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define lf double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

ll n, m;

void dfs(unordered_set<ll> &mset, vll &w, ll weight, int i)
{
	if (i == m){
		if (weight >= 0) mset.ins(weight);
		return;
	}
	dfs(mset, w, weight+w[i], i+1);
	dfs(mset, w, weight-w[i], i+1);
	dfs(mset, w, weight, i+1);
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	while(cin>>n>>m, n>0){
		vll a(n), w(m);
		rep(i, n) cin>>a[i];
		rep(i, m) cin>>w[i];;

		unordered_set<ll> mset;
		dfs(mset, w, 0, 0);

		for(int i=0; i<a.size(); ){
			if (mset.count(a[i]))
				a.erase(a.begin()+i);
			else
				i++;
		}
		if (a.empty()){
			cout << "0\n";
			continue;
		}
		n = a.size();

		vector<set<ll>> cand(n);
		for(auto itr=mset.begin(); itr!=mset.end(); itr++){
			cand[0].ins((*itr)+a[0]);
			cand[0].ins(llabs((*itr)-a[0]));
		}
		for(int i=1; i<n; i++){
			for(auto itr=cand[i-1].begin(); itr!=cand[i-1].end(); itr++){
				if (mset.count((*itr)+a[i]) || mset.count(llabs((*itr)-a[i]))){
					cand[i].ins(*itr);
				}
			}
		}
		if (cand[n-1].empty()){
			cout << "-1\n";
		}else{
			cout << *(cand[n-1].begin()) << "\n";
		}
	}
	return 0;
}