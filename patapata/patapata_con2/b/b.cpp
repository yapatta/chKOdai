#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,d,l;
	while(cin >> t >> d >> l)
	{
		if(t==0) break;

		int ans = 0;
		int en = -1;
		for(int i=0;i<t;i++)
		{
			if(i<=en)
			{
				ans++;
			}
			int x;
			cin >> x;
			if(x >= l)
			{
				en = i + d;
			}
		}
		cout << ans << endl;
	}
}
