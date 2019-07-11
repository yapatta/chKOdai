#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		if(n==0) break;
		vector<set<int> > know(n);
		for(int i=0;i<n;i++) {
			int m;
			cin >> m;
			for(int j=0;j<m;j++) {
				int p;
				cin >> p;
				know[i].insert(p);
			}
		}int k;
		cin >> k;
		vector<int> l(k),ans;
		for(int i=0;i<k;i++)
			cin >> l[i];
		for(int i=0;i<n;i++) {
			int before = know[i].size();
			for(int j=0;j<k;j++) {
				know[i].insert(l[j]);
			}
			int after = know[i].size();
			if(before == after) {
				ans.push_back(i);
			}
		}
		if(ans.size()==1) {
			cout << 1+ans[0] << endl;
		}else
			cout << -1 << endl;
	}
}
