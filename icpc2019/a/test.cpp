#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		if(n==0)break;
		vector<int> p(n,0);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				int tmp;
				cin >> tmp;
				p[j]+=tmp;
			}
		sort(p.begin(),p.end());
		cout << p[n-1] << endl;
	}
	
}
