#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int main() {
	int n = 20;
	int cnt = 0;
	vector<int> reason;
	for(int i=0;i<(1<<n);i++)
	{
		int a = 0;
		if( i!=0 and (i-1 & i)==i) a= 1;
		if(a==1) {
			bool flag=false;
			cout << reason.size() << endl;
			for(int j=0;j<reason.size();j++)
			{
				int rea=reason[j];
				if((i & rea) == rea) {
					flag=true;

				}else {
			
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
				/*
				if((i & rea) == rea) {
					cout << -1 << endl;
					return 0;
				}
				*/
			}
		}
		//cerr << bitset<8>(rea) << endl;
	}
	cout << cnt << endl;
}
