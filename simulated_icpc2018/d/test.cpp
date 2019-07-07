#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll N;
int main() {
	vector<ll> sum(55);
	vector<string> zero(55);
	zero[0] = "1";
	sum[0] = 0;
	for(ll i=1;i<=50;i++)
	{
		zero[i] = zero[i-1] + "0";
		sum[i] = sum[i-1] + 9*9*( (1<<(i-1) ) - 1 );
	}

	while(cin >> N)
	{
		if(N==0) break;
		int keta = -1;
		for(ll i=1;i<=50;i++)
		{
			if(sum[i-1] < N and N <= sum[i])
			{
				keta = i;
				break;
			}
		}
		if(keta==-1) break;
		cout << N << " " << keta << endl;
		map<string,ll> app;
		for(ll x=9;x>=1;x--)
		{
			for(ll y=9;y>=0;y--)
			{
				if(x==y) continue;
				queue<pair<string,bool> > q;
				q.push(make_pair(to_string(x), false) );
				while(!q.empty())
				{
					auto tmp = q.front();
					q.pop();
					cout <<  "zero tmp.first zero " << zero[keta-1] << " " <<  tmp.first << " " << zero[keta] << endl;
					if(zero[keta-1] <= tmp.first and tmp.first < zero[keta]  and tmp.second==true)
					{
						cout << tmp.first << endl;
						app[tmp.first] = 1;
					}
					if( zero[keta] <= tmp.first + "0")
					{
						continue;
					}
					q.push( make_pair(tmp.first+to_string(x), tmp.second) );
					q.push(make_pair(tmp.first+to_string(y),true) );
				}
			}
		}
		ll rest = N - sum[keta-1];
		for(auto key : app)
		{
			rest--;
			if(rest == 0) {
				cout << key.first<< endl;
				break;
			}
		}
	}
}
