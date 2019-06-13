#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e9+7;

signed
main(){
		int d,w;
		while(cin >> d >> w && !(d==0 && w==0))
		{
				vector<vector<int> > e(d, vector<int>(w));
				for(int i=0;i<d;i++)
				{
						for(int j=0;j<w;j++)
						{
								cin >> e[i][j];
						}
				}
				int ans = 0;

				//縦A個, 横B個探索する
				for(int A=3;A<=d;A++)
				{
						for(int B=3;B<=w;B++)
						{
								//(y,x)が探索の初期値点
								for(int y=0;y<=d-A;y++)
								{
										for(int x=0;x<=w-B;x++)
										{
												//枠内の最大を求める
												int in_max = 0, in_sum = 0, in_num = 0;
												for(int a=y+1;a<=y+A-2;a++)
												{
														for(int b=x+1;b<=x+B-2;b++)
														{
																in_num++;
																in_sum += e[a][b];
																if(in_max < e[a][b])
																		in_max = e[a][b];
														}
												}
												//cout << in_sum << " " << in_max << endl;
													
												//枠外の最小を求める
												int out_min = MAX;
												for(int a=y;a<y+A;a++)
												{
														if(out_min > e[a][x]) out_min = e[a][x];
														if(out_min > e[a][x+B-1]) out_min = e[a][x+B-1];

												}
																									
												for(int b=x;b<x+B;b++)
												{
														if(out_min > e[y][b]) out_min = e[y][b];
														if(out_min > e[y+A-1][b]) out_min = e[y+A-1][b];

												}

												//cout << out_min << " " << in_max << endl;
												
												int sum = in_num * out_min - in_sum;
												if(out_min > in_max)
												{
														//cout << in_num << endl; 
														if(ans < sum) ans = sum;
												}
												
										}
								}

						}
				}
				cout << ans << endl;
		}
}
