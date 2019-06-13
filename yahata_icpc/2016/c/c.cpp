#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 8*1e6;

signed
main(){
		int m,n;
		while(cin >> m >> n && !(m==0 && n==0))
		{
				if(n < m){
						cout << m+n << endl;
						continue;
				}

				vector<bool> done(MAX,false);
				int cnt = 0;
				for(int num=m;num<=MAX;num++)
				{
						if(cnt == n) break;
						
						if(done[num]==false)
						{
								cnt++;
								for(int i=num;i<=MAX;i+=num)
								{
										done[i] = true;
								}

						}
				}

				for(int num=m;num<=MAX;num++)
				{
						if(done[num]==false)
						{
								cout << num << endl;
								break;
						}
				}

		}
}
