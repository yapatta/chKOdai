#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e6+5;
signed
main(){
	//10e6までの素数を列挙
	//初期化
	bool isPrime[MAX+5];
	isPrime[1] = false;
	for(int i=2;i<=MAX;i++)
			isPrime[i] = true;

	for(int i=2;i<=MAX;i++)
	{
			if(isPrime[i])
					for(int j=2*i;j<=MAX;j+=i)
							isPrime[j] = false;
	}

	int a,d,n;
	while(cin >> a >> d >> n && !(a==0 && d==0 && n==0)){
			int cnt = 0;
			int ans = a;
			while(1)
			{
					if(isPrime[ans])
					{
							cnt++;
							if(cnt==n)
									break;
					}
					ans += d;
			}
			cout << ans << endl;
	}
}
