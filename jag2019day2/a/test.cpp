#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n;
	cin >> n;
	vector<int> tor(n,-1);
	vector<int> toc(n,-1);
	bool can=true;
	for(int i=0;i<n;i++)
	{
		int r,c;
		cin >> r >> c;
		r--;c--;
		if(tor[r]!=-1)
		{
			can=false;
		}
		if(toc[c]!=-1)
		{
			can=false;
		}
		tor[r]=c;
		toc[c]=r;
	}
	if(!can)
	{
		cout << -1 << endl;
		return 0;
	}

	int cnt=0;
	vector<bool> done(n,false);
	for(int i=0;i<n;i++)
	{
		if(done[i]==true)continue;
		cnt++;
		int nx=tor[i];
		while(true)
		{
			done[nx]=true;
			nx=tor[nx];
			if(done[nx]==true)
				break;
		}
	}
	int ans=n-cnt;
/*
	cnt=0;
	done=vector<bool>(n,false);
	for(int i=0;i<n;i++)
	{
		if(done[i]==true)continue;
		cnt++;
		int nx=toc[i];
		while(true)
		{
			done[nx]=true;
			nx=toc[nx];
			if(done[nx]==true)
				break;
		}
	}
	ans=min(ans,n-cnt);
*/
	cout << ans << endl;

}
