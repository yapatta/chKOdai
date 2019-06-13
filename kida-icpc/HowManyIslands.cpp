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

ll ans=0;
ll w, h;
int field[50][50];

void dfs(ll y, ll x)
{
	field[y][x] = 0;
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			ll tx = x+j;
			ll ty = y+i;
			if (!(0<=tx && tx<=w-1 && 0<=ty && ty<=h-1)) continue;
			if (field[ty][tx]==0) continue;
			dfs(ty, tx);
		}
	}
	return;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while(cin>>w>>h, w!=0){
		ans=0;
		rep(i, h) rep(j, w){
			cin >> field[i][j];
		}
		rep(i, h) rep(j, w){
			if (field[i][j] == 1){
				dfs(i, j);
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}