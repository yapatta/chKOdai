#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		int H;
		while(cin >> H && H!=0)
		{
				vector<vector<int> > d(H, vector<int>(5, -1));
				for(int i=0;i<H;i++)
				{
						for(int j=0;j<5;j++)
						{
								cin >> d[i][j];
						}
				}
				
				bool flag = true;
				int ans = 0;
				vector<int> minus_num(5,0);

				while(1)
				{
						flag = true;
						vector<vector<bool> > exist(H, vector<bool>(5, true));
						for(int y=0;y<H;y++)
						{
								int fi = -1, la = -1;
								bool seq = false;
								for(int x=2;x<5;x++)
								{
										if(d[y][x-2] == -1) continue;
										if(!seq && d[y][x-2] == d[y][x-1] && d[y][x-1] == d[y][x])
										{
												fi = x-2;
												la = x;
												seq = true;
										}
										else if(seq && d[y][x-1] == d[y][x])
										{
												la++;
										}else{
												seq = false;
										}
								}
								if(fi==-1 && la==-1) continue;
								
								//cout << fi << " " << la << endl;
								for(int x=fi;x<=la;x++)
								{
										exist[y][x] = false;
										ans += d[y][x];
								}

						}

						for(int x=0;x<5;x++)
						{								
								for(int y=0;y<H;y++)
								{
										if(exist[y][x]==false){
												flag = false;
													
												for(int sy=y;sy>minus_num[x];sy--)
												{
														d[sy][x] = d[sy-1][x];
												}
												d[minus_num[x]++][x] = -1;
										}
								}
						}
						if(flag) {
								cout << ans << endl;
								break;
						}
				}
		}
}
