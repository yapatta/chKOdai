#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int main() {
	int n;
	cin>> n;
	int cnt = 0;
	vector<int> reason;
	for(int i=0;i<(1<<n);i++)
	{
		int a;
		cin >> a;
		if(reason.size()>100)
			break;
		if(a==1) {
			bool flag=false;
			for(int j=0;j<reason.size();j++)
			{
				int rea=reason[j];
				if((i & rea) == rea) {
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				reason.push_back(i);
				cnt++;
			}
		}else {
			for(int j=0;j<reason.size();j++)
			{
				int rea = reason[j];
				if((i & rea) == rea) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
//		cout << "reason" << endl;
//		for(int j=0;j<reason.size();j++)
//			cerr << bitset<8>(reason[j]) << endl;
	}
	cout << cnt << endl;
}
