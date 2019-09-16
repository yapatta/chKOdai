#include <bits/stdc++.h>
using namespace std;

int main() {
	int l;
	string s;
	cin >> l >> s;

	vector<int> ans(l,0);
	for(int i=0;i<l;i++)
	{
		if(s[i]!='.')continue;
		int left=0,right=0;
		int tmp=0;
		for(int j=i-1;j>=0;j--)
		{
			if(s[j]=='.') {
				tmp = 0;
				break;
			}
			if(s[j]=='B')tmp++;
			if(s[j]=='W')
			{
				left=tmp;
				break;
			}
		}
		tmp = 0;
		for(int j=i+1;j<l;j++)
		{
			if(s[j]=='.'){
				tmp=0;
				break;
			}
			if(s[j]=='B')tmp++;
			if(s[j]=='W')
			{
				right=tmp;
				break;
			}
		}
		ans[i] = left + right;
		bool lflag=false,rflag=false;
		for(int j=i-1;j>=0;j--)
		{
			if(s[j]=='.') {
				lflag=false;
				break;
			}
			if(s[j]=='B'){
				lflag=true;
				break;
			}
			if(s[j]=='W')
			{
				continue;
			}
		}
		for(int j=i+1;j<l;j++)
		{
			if(s[j]=='.') {
				rflag=false;
				break;
			}
			if(s[j]=='B') {
				rflag=true;
				break;
			}
			if(s[j]=='W')
			{
				continue;
			}
		}
		if(lflag and rflag) ans[i] = 0;
		//cerr << lflag << " " << rflag << endl;
		//cerr << i << " "  << left << " " << right << " " << ans[i] << endl;
	}
	
	sort(ans.begin(), ans.end());
	cout << ans[l-1] << endl;
}
