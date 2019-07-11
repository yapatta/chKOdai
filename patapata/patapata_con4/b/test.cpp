#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		if(n==0) break;
		vector<pair<double,string> > ans(n);
		for(int i=0;i<n;i++) {
			string l;
			int p,a,b,c,d,e,f,s,m;
			cin >> l;
			cin >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			ans[i].first = (-1)*( (f*m*s)-p) /(double)((a+b+c) + (d+e)*m);
			ans[i].second = l;
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<n;i++) {
			cout << ans[i].second << endl;
		}
		cout << "#" << endl;
	}
}
