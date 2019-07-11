#include<bits/stdc++.h>
#define R 2
#define L 3
#define D 0
#define U 1
using namespace std;

bool to[35][35][4];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(int sx,int sy,int gx,int gy)
{
	int ans=0;
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(make_pair(sx,sy), 0));
	vector<vector<bool> >  done(gx+5,vector<bool>(gy+5,false));
	done[sx][sy]=true;
	while(!q.empty())
	{
		auto get=q.front();
		q.pop();
		int x=get.first.first;
		int y=get.first.second;
		if(x==gx and y==gy)
		{
			ans = get.second;
			break;
		}
		for(int i=0;i<4;i++)
		{
			int nx = get.first.first + dx[i];
			int ny = get.first.second + dy[i];
			if(to[x][y][i]==true and done[nx][ny]==false)
			{
				q.push(make_pair(make_pair(nx,ny),get.second+1));
				done[nx][ny]=true;
			}
		}
	}

	return (ans==0)? 0 : ans+1;
}

int main()
{
	int w,h;
	while(cin >> w >> h)
	{
		if(w==0 and h==0)return 0;
		for(int i=0;i<35;i++)
			for(int j=0;j<35;j++)
				for(int k=0;k<4;k++)
					to[i][j][k]=false;
		for(int i=0;i<2*h-1;i++)
		{
			if(i%2==0)
			{
				for(int j=0;j<w-1;j++)
				{
					int in;
					cin >> in;
					if(in==0)
					{
						to[j][i/2][R]=true;
						to[j+1][i/2][L]=true;
					}
				}
			}
			else
			{
				for(int j=0;j<w;j++)
				{

					int in;
					cin >> in;
					if(in==0)
					{
						to[j][i/2][D]=true;
						to[j][(i+1)/2][U]=true;
					}
				}
			}
		}

		cout << bfs(0,0,w-1,h-1) << endl;

	}

}
