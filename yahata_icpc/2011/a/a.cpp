#include <bits/stdc++.h>
using namespace std;
const int MAX = 250000;

signed
main(){
		vector<bool> prime(MAX, true);
		prime[0] = false;
		prime[1] = false;
		for(int i=2;i<=MAX;i++)
		{
				if(prime[i])
				{
						for(int j=2*i;j<=MAX;j+=i)
						{
								prime[j] = false;
						}

				}
		}
		int n;
		while(cin >> n and n!=0)
		{
				int cnt = 0;
				for(int i=n+1;i<=2*n;i++)
				{
						if(prime[i]) cnt++;
				}
				cout << cnt << endl;
		}
}
