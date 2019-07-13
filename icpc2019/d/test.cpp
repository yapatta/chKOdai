#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		if(n==0)
			break;

		vector<int> a(n+5);
		vector<int> b(n+5);
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			a[i]--;
		}
		for(int i=0;i<n;i++)
		{
			cin >> b[i];
			b[i]--;
		}
		int ans=INT_MAX;
		for(int x=0;x<3;x++)
		{
			vector<int> tmp(n+5);
			for(int i=0;i<n;i++)
				tmp[i]=a[i];
			int cnt=0;
			if(b[0]!=tmp[0])
			{
				int upcnt=b[0]-tmp[0];
				if(tmp[0]>b[0])
					upcnt=b[0]-(tmp[0]-m);
				tmp[0]=b[0];
				for(int i=1;i<=x;i++)
				{
					tmp[0+i]+=upcnt;
					tmp[0+i]%=m;
				}
				cnt+=upcnt;
			}

			for(int i=1;i<n;i++)
			{
				if(tmp[i]==b[i])
					continue;
				else
				{
					int upcnt=b[i]-tmp[i];
					if(tmp[i]>b[i])
						upcnt=b[i]-(tmp[i]-m);
					cnt+=upcnt;
					tmp[i]=b[i];
					tmp[i+1]+=upcnt;
					tmp[i+1]%=m;
					tmp[i+2]+=upcnt;
					tmp[i+2]%=m;

				}
			}

			ans=min(ans,cnt);
		}
		cout << ans << endl;
	}
	
}
