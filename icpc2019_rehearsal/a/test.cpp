#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		if(n==0) break;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a.begin(),a.end());
		cout << a[n-1] << endl;

	}
}
