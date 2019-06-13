#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		int n,m,t,p;
		while(cin >> n >> m >> t >> p && !(n==0 && m==0 && t==0 && p==0))
		{
				vector<vector<int> > z(m, vector<int>(n,1));

				//w,hは更新されていく幅と高さ
				int w = n, h = m;

				for(int i=0;i<t;i++)
				{
						int d,c;
						cin >> d >> c;

						if(d==1)
						{
								vector<vector<int> > tmp(h, vector<int>(w, 0)), tmp2(h, vector<int>(w, 0));
								//tmpの初期化
								for(int a=0;a<h;a++)
								{
										for(int b=0;b<w-c;b++)
										{
												tmp[a][b] = z[a][b+c];
										}
								}


								for(int a=0;a<h;a++)
								{
										for(int b=0;b<c;b++)
										{
												tmp2[a][b] = z[a][c-1-b];
										}
								}

								//最後にtmpの状態をzに適用
								for(int a=0;a<h;a++)
                                {
                                        for(int b=0;b<w;b++)
                                        {
                                        		z[a][b] = 0;
		 										z[a][b] = tmp[a][b] + tmp2[a][b];
										}
                                }

								//wの値を更新
								w = max(w-c,c);

						}
						else if(d==2)
						{
								vector<vector<int> > tmp(h, vector<int>(w, 0)),tmp2(h, vector<int>(w, 0));
								//tmpの初期化
								for(int a=0;a<h-c;a++)
								{
										for(int b=0;b<w;b++)
										{
												tmp[a][b] = z[a+c][b];
										}
								}

								for(int a=0;a<c;a++)
								{
										for(int b=0;b<w;b++)
										{
												tmp2[a][b] = z[c-1-a][b];
										}
								}

								//最後にtmpの状態をzに適用
								for(int a=0;a<h;a++)
                                {
                                        for(int b=0;b<w;b++)
                                        {
                                        		//初期化
                                        		z[a][b] = 0;
		 										z[a][b] = tmp[a][b] + tmp2[a][b];
										}
                                }
								
								//hの値を更新
								h = max(h-c,c);

						}

						//debug
						/*
						for(int a=0;a<m;a++)
						{
							for(int b=0;b<n;b++)
							{
								cout << z[a][b] << " ";
							}
							cout << endl;
						}
						*/

				}


				int ans = 0;

				for(int i=0;i<p;i++)
				{
						int x,y;
						cin >> x >> y;
						cout << z[y][x] << endl;

				}
		}
}
