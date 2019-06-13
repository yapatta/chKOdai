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

ll w, h;
char field[100][100];
bool use[100][100];
ll ans=0;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y)
{
	use[y][x] = true;
	ans++;
	rep(i, 4){
		ll tx = x+dx[i];
		ll ty = y+dy[i];
		if (!(0<=tx && tx<=w-1 && 0<=ty && ty<=h-1)) continue;
		if (use[ty][tx] || field[ty][tx]=='#') continue;
		dfs(tx, ty);
	}
	return;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while(cin>>w>>h, w!=0){
		ll sx, sy;
		ans = 0;
		memset(use, 0, sizeof(use));
		rep(i, h){
			rep(j, w){
				cin >> field[i][j];
				if (field[i][j]=='@'){
					sx = j; sy = i;
				}
			}
		}
		dfs(sx, sy);
		cout << ans << "\n";
	}
	return 0;
}