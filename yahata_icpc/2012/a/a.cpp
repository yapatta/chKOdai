#include <bits/stdc++.h>
using namespace std;

signed
main(){
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
				int y,m,d;
				cin >> y >> m >> d;
				int three_y = 333 - y/3;
				int else_y = 999 - y - three_y;
				int now_y_day = 0;
				if(y%3 == 0)
				{
					now_y_day = (20-d) + (10-m)*20;
				}else
				{
						if(m%2==0)
						{
								now_y_day = (19-d) + ((10-m)/2) * (19+20);
						}else
						{
								now_y_day = (20-d) + 19 + ((10-m)/2) * (19+20);
						}
				}
				int ans = (three_y * 200) + (else_y * 195) + now_y_day + 1;
				cout << ans << endl;
		}
}
