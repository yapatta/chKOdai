#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		int n,m;
		while(cin >> n >> m && !(n==0 && m==0))
		{
				vector<int> a(n);
				for(int i=0;i<n;i++)
						cin >> a[i];
				
				int ans = -1;

				for(int i=0;i<n;i++)
				{
						for(int j=i+1;j<n;j++)
						{
								int key = a[i] + a[j];
								if(key <= m)
								{
										if(ans<key)
												ans = key;
								}
						}
				}

				if(ans == -1) cout << "NONE" << endl;
				else cout << ans << endl;
		}
}
