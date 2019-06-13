#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		ll b;
		while(cin >> b && b!=0)
		{
				//初期化
				ll cnt = 1, sum = 1;
				ll left = 1, right = 2;

				while(1)
				{
						if(sum > b)
						{
								sum -= left;
								left++;
								cnt--;
						}
						else if(sum < b)
						{
								sum += right;
								right++;
								cnt++;
						}
						else
						{
								break;
						}

				}

				cout << left << " " << cnt << endl;
		}
}
