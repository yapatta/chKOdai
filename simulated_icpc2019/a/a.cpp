#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n,m;
	while(true) {
		cin >> n >> m;
		if(n==0) break;

		int ans = 0;
		for(int i=0;i<n;i++)
		{
			int tmp;
			cin >> tmp;
			ans += min(tmp, m/n);
		}
		cout << ans << endl;
	}
}
