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

ll func(ll y, ll m, ll d)
{
	ll ret = 0;
	ret += (y-1)/3 * (2*39*5+20*10);
	ret += (y-1)%3 * (39*5);
	for(int i=1; i<m; i++){
		if (i%2 == 1 || y%3 == 0){
			ret += 20;
		}else{
			ret += 19;
		}
	}
	ret += d;
	return ret;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n; cin>>n;
	ll ans1000 = func(1000, 1, 1);
	rep(i, n){
		ll y, m, d; cin>>y>>m>>d;
		ll ans = ans1000 - func(y, m, d);
		cout << ans << "\n";
	}
	return 0;
}