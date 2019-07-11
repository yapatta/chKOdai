#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(cin >> n >> m)
	{
		if(n==0) break;
		vector<priority_queue<int> > q(m);
		
		for(int i=0;i<n;i++)
		{
			int d,v;
			cin >> d >> v;
			d--;
			q[d].push(v);
		}
		int ans = 0;
		for(int i=0;i<m;i++)
		{
			ans += q[i].top();
		}
		cout << ans << endl;
	}
}
