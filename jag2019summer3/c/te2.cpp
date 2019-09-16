#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<pair<pair<int,int>, int>> ystart(n);
	vector<pair<pair<int,int>, int>> yend(n);
	vector<bool> used(n,false);
	for(int i=0;i<n;i++)
	{
		int l,r;
		cin >> l >> r;
		ystart[i]=make_pair(make_pair(l,r),i);
		yend[i]=make_pair(make_pair(r,l),i);
	}
	sort(ystart.begin(),ystart.end());
	sort(yend.begin(),yend.end());

	int cnt=0;
	int loop=0;
	bool tor=true;
	int now=-1;
	while(true)
	{
		if(cnt==n)break;
		loop++;
		if(tor)
		{
			if(loop==1)now=-1;
			else now=0;
			bool endflag=false;
			while(true)
			{
				auto itr=upper_bound(yend.begin(),yend.end(),make_pair(make_pair(now,0),0));
				while(true)
				{
					if((*itr).first.second>now and used[(*itr).second]==false)break;
					itr++;
					if(itr==yend.end())
					{
						endflag=true;
						break; 
					}
				}
				if(endflag)
				{
					tor=!tor;
					break;
				}
				now=(*itr).first.first;
				used[(*itr).second]=true;
				cnt++;
			}
		}
		else
		{
			now=m;
			bool endflag=false;
			while(true)
			{
				auto itr=lower_bound(ystart.begin(),ystart.end(),make_pair(make_pair(now,0),0));
				//cout << (*itr).second << endl;
				if(itr==ystart.begin()) {
					endflag=true;
				}
				else itr--;
				while(true)
				{
					if(endflag)break;
					if((*itr).first.second<now and used[(*itr).second]==false)break;
					itr--;
					if(itr==ystart.begin())
					{
						if((*itr).first.second<now and used[(*itr).second]==false)break;
						else
						{
							endflag=true;
							break; 
						}
					}
				}
				if(endflag)
				{
					tor=!tor;
					break;
				}
				now=(*itr).first.first;
				used[(*itr).second]=true;
				cnt++;
			}

		}
	}
	cout << loop << " " << now << endl;
	cout << (loop-1)*m+(loop%2==0 ? m-now:now) << endl;

}
