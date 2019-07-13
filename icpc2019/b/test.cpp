#include<bits/stdc++.h>

using namespace std;

int main()
{
	int h,w;
	while(cin >> h >> w)
	{
		if(h==0)break;
		vector<string> r(h);
		for(int i=0;i<h;i++)
			cin >> r[i];
		string s;
		cin >> s;
		map<char,pair<int,int> > mp;
		for(int i=0;i<h;i++)
			for(int j=0;j<r[i].size();j++)
			{
				mp[r[i][j]]=make_pair(i,j);
			}

		int ans=0;
		int x=0;
		int y=0;
		for(int i=0;i<s.size();i++)
		{
			ans+=(abs(x-mp[s[i]].first)+abs(y-mp[s[i]].second));
			ans++;
			x=mp[s[i]].first;
			y=mp[s[i]].second;
			
		}

		cout << ans << endl;

	
	}
	
}
