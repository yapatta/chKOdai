#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,l,r;
	while(cin >> n >> l >> r)
	{
		if(n==0)break;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		int cnt=0;
		for(int i=l;i<=r;i++)
		{
			bool uru=true;
			bool flag=false;
			for(int j=0;j<n;j++)
			{
				if(i%a[j]==0)
				{
					uru=(j%2==0 ? true:false);
					flag=true;
					break;
				}
			}
			if(flag==false)
				uru=(n%2==0 ? true:false);
			if(uru)
				cnt++;
		}
		cout << cnt << endl;
	}
}


