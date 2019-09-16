#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int odd=0,even=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]%2==0)
		{
			even++;
		}
		else
			odd++;
	}
	cout << ((odd==0 or even==0) ? 0:(odd%2==0 ? n-2:n-1)) << endl;
}
