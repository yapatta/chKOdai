#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e8;

signed
main(){
		int a,b,c;
		cin >> a >> b >> c;
		int ans = MAX;

		for(int k=0;k<a+b;k++)
		{
				for(int t=0;t<c;t++)
				{
						if(k*(a+b) <= c+60*t && c+60*t <= k*(a+b) + a)
						{
								ans = min(ans, c+60*t);
						}
				}
		}
		if(ans == MAX)
		{
				cout << -1 << endl;
		}else
		{
				cout << ans << endl;
		}
}
