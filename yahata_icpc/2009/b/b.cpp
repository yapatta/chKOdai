#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > c;
vector<vector<bool> > done;
int w,h;
int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {1,0,-1,1,-1,1,0,-1};

void dfs(int y, int x)
{
		done[y][x] = true;
		for(int i=0;i<8;i++)
		{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(0<=ny && ny<h && 0<=nx && nx<w && c[ny][nx]==1 && !done[ny][nx])
				{
						dfs(ny,nx);
				}
		}
}

signed
main()
{
	while(cin >> w >> h and !(w==0 & h==0))
	{
			c = vector<vector<int> >(h,vector<int>(w));
			done = vector<vector<bool> >(h,vector<bool>(w, false));
			for(int y=0;y<h;y++)
					for(int x=0;x<w;x++)
							cin >> c[y][x];

			int cnt = 0;
			for(int y=0;y<h;y++)
			{
					for(int x=0;x<w;x++)
					{
							if(c[y][x] && !done[y][x]){
									cnt++;
									dfs(y,x);
							}
					}
			}
			cout << cnt << endl;
	}
}
