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

#define INF 1e10

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n, m;
	while(cin>>n>>m, n!=0){
		vll s(n), t(m);
		pll ans = mp(INF, INF);
		ll ssum=0, tsum=0;
		rep(i, n) cin >> s[i], ssum+=s[i];
		rep(i, m) cin >> t[i], tsum+=t[i];
		rep(i, n)rep(j, m){
			if ((t[j]-s[i])*2 == tsum-ssum && s[i] < ans.fi){
				ans.fi = s[i];
				ans.se = t[j];
			}
		}
		if (ans.fi!=INF)
			cout << ans.fi << " " << ans.se << "\n";
		else
			cout << "-1\n";
	}

	return 0;
}