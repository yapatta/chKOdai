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

//次のようなインデックス構成でvectorを作る
//
//(0, 4), (1, 4), ..., (4, 4)
//(0, 3), (1, 3), ..., (4, 3)
//(0, 2), (1, 2), ..., (4, 2)
//(0, 1), (1, 1), ..., (4, 1)
//(0, 0), (1, 0), ..., (4, 0)
//
//こうすることでvector::eraseをするだけで
//勝手に詰めてくれる．

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll h;
	while(cin>>h, h!=0){
		vector<vll> field(5, vll(h));
		for(int i=h-1; i>=0; i--)rep(j, 5)
			cin >> field[j][i];

		ll ans=0;
		bool loop = true;
		while(loop){
			loop = false;
			for(int i=h-1; i>=0; i--){
				ll left=0, right=0;
				rep(j, 4){
					if (i>=field[j].size() || i>=field[j+1].size()){
						if (right-left>=2) break;
						left=j+1;
						continue;
					}
					if (field[j][i]==field[j+1][i]) right=j+1;
					if (field[j][i]!=field[j+1][i]){
						if (right-left>=2) break;
						left=j+1;
					}
					if (right-left>=2) loop = true;
				}
				if (right-left>=2){
					for(int k=left; k<=right; k++){
						ans += field[k][i];
						field[k].erase(field[k].begin()+i);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}