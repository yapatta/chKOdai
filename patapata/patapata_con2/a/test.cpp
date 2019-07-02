#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(true)
	{
		cin >> n;
		if(n==0)
			break;
		vector<vector<bool> > mp(25,vector<bool>(25,true));
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin >> x >> y;
			mp[x][y]=false;
		}
		int m;
		cin >> m;
		int nx=10,ny=10;
		mp[nx][ny]=true;
		for(int i=0;i<m;i++)
		{
			char c;
			int d;
			cin >> c >> d;

			if(c=='N')
				for(int i=0;i<d;i++)
				{
					ny++;
					mp[nx][ny]=true;
				}
			else if(c=='S')
			for(int i=0;i<d;i++)
				{
					ny--;
					mp[nx][ny]=true;
				}
			else if(c=='E')
				for(int i=0;i<d;i++)
				{
					nx++;
					mp[nx][ny]=true;
				}
			else if(c=='W')
				for(int i=0;i<d;i++)
				{
					nx--;
					mp[nx][ny]=true;
				}
		}
		bool flag=true;
		for(int i=0;i<=20;i++)
			for(int j=0;j<=20;j++)
				if(mp[i][j]==false)
					flag=false;
		cout << (flag ? "Yes":"No") << endl;
		
	}
}
