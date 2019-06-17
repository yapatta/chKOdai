#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};
signed
main(){
		int N;
		while(cin >> N && N!=0){
				vector<int> n(N), d(N);
				for(int i=1;i<N;i++){
						cin >> n[i] >> d[i];
				}
				//全探索
				//もし正方形範囲を超えるならflag = false
				bool flag;
				for(int sy=0;sy<N;sy++){
						for(int sx=0;sx<N;sx++){
								flag = true;
								vector<bool> Hdone(N), Wdone(N);
								vector<pair<int,int> > z(N);
								z[0] = {sy,sx};
								Hdone[sy] = true;
								Wdone[sx] = true;

								for(int i=1;i<N;i++){
										int ny = z[n[i]].first + dy[d[i]];
										int nx = z[n[i]].second + dx[d[i]] ;
										if(0  <= ny and nx < N and 0 <= nx and nx < N){
												Hdone[ny] = true;
												Wdone[nx] = true;
												z[i] = {ny,nx};
										}else{
												flag = false;
												break;
										}
								}
								if(flag){
										int w = 0, h = 0;
										for(int i=0;i<N;i++){
												if(Hdone[i]) h++;
												if(Wdone[i]) w++;
										}
										cout << w << " " << h << endl;
										break;
								}
						}
						if(flag) break;
				}
		}
}
