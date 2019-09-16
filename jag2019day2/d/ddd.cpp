#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int main() {
	int n;
	cin>> n;
	int cnt = 0;
	int rea = 0;
	vector<int> aa(1<<n);
	for(int i=0;i<(1<<n);i++)
	{
		cin >> aa[i];
	}
	for(int i=0;i<(1<<n);i++)
	{
		int a=aa[i];
		if(a==1) {
			if(i & rea) {

			}else {
				rea |= i;
				cnt++;
			}
		}else {
			if(i & rea) {
				cout << -1 << endl;
				return 0;
			}
		}
		//cerr << bitset<8>(rea) << endl;
	}
	cnt = 0;
	for(int i=0;i<(1<<n);i++)
	{
		int a=aa[i];
		if(a==1) {
			if((i & rea)==i) {
				rea -= i;
				cnt++;
			}else {

			}
		}else {

		}
	}
	cout << cnt << endl;
}

