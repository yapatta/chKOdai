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
	string s, t;
	while(cin>>s>>t, s!="."){
		if (s==t){
			cout << "IDENTICAL\n";
			continue;
		}
		bool isstr=false, cond;
		ll diff=0;
		ll spos=0, tpos=0;
		ll lsp = 0, ltp = 0;
		while(true){
			spos = s.find("\"", lsp);
			tpos = t.find("\"", ltp);
			if (spos==string::npos || tpos==string::npos){
				cond = s.substr(lsp) == t.substr(ltp);
			}else{
				cond = s.substr(lsp, spos-lsp) == t.substr(ltp, tpos-ltp);
			}
			if (!cond) (isstr) ? diff++ : diff+=2;
			if (spos==string::npos || tpos==string::npos) break;
			if (diff >= 2) break;
			isstr = !isstr;
			lsp = spos+1;
			ltp = tpos+1;
		}
		if (diff >= 2){
			cout << "DIFFERENT\n";
		}else{
			cout << "CLOSE\n";
		}
	}
	return 0;
}