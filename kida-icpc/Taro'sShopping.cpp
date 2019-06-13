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

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n, m;
	while(cin>>n>>m, n!=0){
		ll ans=0;
		vll a(n);
		rep(i, n) cin>>a[i];
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if (a[i]+a[j] <= m)
					ans = max(ans, a[i]+a[j]);

		if (ans!=0)
			cout << ans << "\n";
		else
			cout << "NONE\n";
	}
	return 0;
}