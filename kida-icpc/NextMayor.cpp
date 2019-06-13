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

	ll n, p;
	while(cin>>n>>p, n!=0){
		vll pos(n, 0);
		ll m = p;
		for(ll i=0; ;i++){
			int j = i % n;
			if (p>0){
				p--;
				pos[j]++;
				if (pos[j] == m){
					cout << j << "\n";
					break;
				}
			}else{
				p += pos[j];
				pos[j] = 0;
			}
		}
	}
	return 0;
}