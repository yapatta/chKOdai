#include <bits/stdc++.h>
using namespace std;
vector<string> s;
vector<vector<bool> > done;
int w,h;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int ans = 0;

void dfs(int y, int x)
{
		ans++;
        done[y][x] = true;
        for(int i=0;i<4;i++)
        {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0<=ny && ny<h && 0<=nx && nx<w && s[ny][nx]=='.' && !done[ny][nx])
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
            s = vector<string>(h);
            done = vector<vector<bool> >(h,vector<bool>(w, false));

			int sy,sx;
            for(int y=0;y<h;y++)
			{
					cin >> s[y];
					for(int x=0;x<w;x++)
					{
						if(s[y][x]=='@')
						{
								sy = y;
								sx = x;
						}
					}
			}
 			dfs(sy,sx);
            cout << ans << endl;
			ans = 0;
    }
}
