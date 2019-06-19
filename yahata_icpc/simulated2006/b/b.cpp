#include <bits/stdc++.h>
using namespace std;

int main(){
		int n,m,a;
		while(cin >> n >> m >> a and !(n==0 && m==0 && a==0)){
				vector<vector<int> > ami(1005);

				for(int i=0;i<m;i++){
						int h,p,q;
						cin >> h >> p >> q;
						h--, p--, q--;
						ami[h].push_back(p);
				}
				int point = a-1;
				for(int i=1004;i>=0;i--){
						for(int j=0;j<ami[i].size();j++){
								if(point==ami[i][j]){
										point = point + 1;
								}else if(point-1==ami[i][j]){
										point = point - 1;
								}
						}
				}
				cout << point+1 << endl;
		}
}
