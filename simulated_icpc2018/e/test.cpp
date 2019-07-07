#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int> > to;
vector<int> color;

bool can;

void dfs(int id, int c)
{
	color[id]=c;

	for(int i=0;i<to[id].size();i++)
	{
		int nxid=to[id][i];
		if(color[nxid]==-1)
			dfs(nxid,(c+1)%2);
		else
		{
			if(color[nxid]==c)
				can=false;
		}
	}


}

int main() {
	while(true)
	{
		cin >> n >> m;
		if(n==0)break;
		to=vector<vector<int> >(n);
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			x--;y--;
			to[x].push_back(y);
			to[y].push_back(x);
		}

		color=vector<int>(n,-1);
		can=true;
		dfs(0,0);

		if(can==false)
			cout << 0 << endl;
		else
		{
			int g1=0,g2=0;
			for(int i=0;i<n;i++)
			{
				if(color[i]==0)g1++;
				else g2++;
			}

			set<int> cnt;
			if(g1%2==0)cnt.insert(g1/2);
			if(g2%2==0)cnt.insert(g2/2);
			cout << cnt.size() << endl;
			for(auto itr=cnt.begin();itr != cnt.end();itr++)
				cout << *itr << endl;



		}

	}	

}
