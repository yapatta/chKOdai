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

//単純に全探索した

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n;
	while(cin>>n, n!=0){
		ll w, h; cin>>w>>h;
		vector<vector<char> > field(h, vector<char>(w, ' '));
		rep(i, n){
			ll x, y; cin>>x>>y;
			field[y-1][x-1] = 't';
		}
		ll s, t; cin>>s>>t;
		ll ans=0;
		for(int i=0; i<=h-t; i++){
			for(int j=0; j<=w-s; j++){
				ll cnt=0;
				rep(k, t)rep(l, s)
					if (field[i+k][j+l]=='t') cnt++;
				ans = max(ans, cnt);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}