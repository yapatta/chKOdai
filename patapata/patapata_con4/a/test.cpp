#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,p,r;
	while(cin >> t >> p >> r) {
		if(t==0) break;
		vector<int> acc(t, 0);
		vector<vector<int> > wrong(t,vector<int>(p,0));
		vector<int> pena(t, 0);
		for(int i=0;i<r;i++) {
			int a,b,c;
			string cw;
			cin >> a >> b >> c >> cw;
			a--,b--;
			if(cw=="CORRECT") {
				acc[a]++;
				pena[a] += (c+wrong[a][b]*1200);
			}else if("WRONG") {
				wrong[a][b]++;
			}
		}
		vector<pair<pair<int,int>,int> > ans(t);
		for(int i=0;i<t;i++){
			ans[i] = make_pair(make_pair(-acc[i],pena[i]), i);
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<t;i++) {
			cout << ans[i].second + 1 << " " << -ans[i].first.first <<  " " << ans[i].first.second << endl;
		}
	}
}
