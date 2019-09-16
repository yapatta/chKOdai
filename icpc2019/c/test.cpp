#include<bits/stdc++.h>

#define ll long long
#define rep(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

ll n, m;

void dfs(set<ll> &mlist, vector<ll> &w, ll weight, int i)
{
	if (i == m){
		mlist.insert(weight);
		return;
	}
	dfs(mlist, w, weight+w[i], i+1);
	dfs(mlist, w, weight-w[i], i+1);
	dfs(mlist, w, weight, i+1);
}

int main()
{
	while(cin>>n>>m, n>0){
		vector<ll> a(n), w(m);
		rep(i, n) cin>>a[i];
		rep(i, m) cin>>w[i];

		set<ll> mlist;
		map<ll, ll> mp;
		dfs(mlist, w, 0ll, 0);
		
		/*for(auto itr=mlist.begin(); itr!=mlist.end(); itr++){
			cout << *itr << endl;
		}*/]

		ll cnt0 = 0;
		rep(i, n){
			if (mlist.count(a[i])){
				cnt0++;
				continue;
			}
			set<ll> tset;
			for(auto itr=mlist.begin(); itr!=mlist.end(); itr++){
				tset.insert(a[i]+(*itr));
				tset.insert(llabs(a[i]-(*itr)));
			}
			for(auto itr=tset.begin(); itr!=tset.end(); itr++){
				mp[(*itr)]++;
			}
		}

		ll ans=-1;
		if (mp.size()){
			for(auto itr=mp.begin(); itr!=mp.end(); itr++){
				if (itr->first <= 0) continue;
				if (itr->second == n-cnt0){
					ans = itr->first;
					break;
				}
			}
		}else{
			ans=0;
		}
		cout << ans << "\n";
	}
	return 0;
}
