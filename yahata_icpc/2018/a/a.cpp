#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		ll n;
		while(cin >> n && n!=0)
		{
				vector<ll> a(n);
				ll sum = 0;
				for(int i=0;i<n;i++)
				{
						cin >> a[i];
						sum += a[i];
				}

				ll cnt = 0;
				for(int i=0;i<n;i++)
				{
						if(n * a[i] <= sum){
								cnt++;
						}
				}
				cout << cnt << endl;
		}
}
