#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	ll n, l; cin>>n>>l;
	vector<pair<ll, ll> > p(n);
	set<ll> s;
	for(int i=0; i<n; i++){
		ll l, r; cin>>l>>r;
		s.insert(l); s.insert(r);
		p[i] = make_pair(l, r);
	}
	sort(p.begin(), p.end());
	ll cur=0, x=0;
	for(int i=0; i<n; i++){
		ll maxi=0;
		while(p[i].first<=cur){
			maxi = max(maxi, p[i].second);
			i++;
		}
		cur = maxi;
		x++; i--;
		if (cur==l) break;
	}
	ll mini, y;
	map<ll, ll> m;
	ll idx=0;
	for(auto it=s.begin(); it!=s.end(); it++){
		m[*it] = idx;
		idx++;
	}
	vector<ll> imos(s.size()+1);
	for(int i=0; i<n; i++){
		ll left = m[p[i].first];
		ll right = m[p[i].second];
		imos[left]++;
		imos[right+1]--;
	}
	mini = imos[0];
	for(int i=1; i<imos.size()-1; i++){
		imos[i]+=imos[i-1];
		mini = min(mini, imos[i]);
	}
	y = n-(mini-1);
	cout << x << " " << y << endl;

	return 0;
}