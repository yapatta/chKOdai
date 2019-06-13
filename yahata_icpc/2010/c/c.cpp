#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e8;

signed
main(){
	int n;
	vector<int> odd, four;
	for(int i=1;i*(i+1)*(i+2)<=6*1e6;i++)
	{
			int tmp = i*(i+1)*(i+2)/ 6;
			if(tmp %2 == 1) odd.push_back(tmp);
			four.push_back(tmp);
	}
			
	//初期化
	vector<int> dp(1e6+5, MAX), dp_odd(1e6+5, MAX);
	dp[0] = 0;

	for(int i=1;i<=1e6;i++)
	{
			for(int j=0;j<four.size() and four[j]<=i;j++)
			{
					dp[i] = min(dp[i], dp[i-four[j]]+1);
			}
	}

	dp_odd[0] = 0;

	for(int i=1;i<=1e6;i++)
	{
			for(int j=0;j<odd.size() and odd[j]<=i;j++)
			{
					dp_odd[i] = min(dp_odd[i], dp_odd[i-odd[j]]+1);
			}
	}

	while(cin >> n && n!=0)
	{
			cout << dp[n] << " " << dp_odd[n] << endl;
	}
}
