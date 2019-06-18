#include <bits/stdc++.h>
using namespace std;
using ll= long long;

signed
main(){
		int m;
		cin >> m;
		
		for(int i=0;i<m;i++){
				string s;
				cin >> s;
				int ans = 0;
				map<string,int> exist;
				for(int j=1;j<s.size();j++){
						//切ったsをspfi,spseに
						vector<string> spfi(2), spse(2);
						string fi = s.substr(0,j);
						string se = s.substr(j);
						spfi[0] = fi;
						reverse(fi.begin(), fi.end());
						spfi[1] = fi;
					    spse[0] = se;
						reverse(se.begin(), se.end());
						spse[1] = se;
						
						for(int a=0;a<2;a++){
								for(int b=0;b<2;b++){
										string  tmp  = spfi[a] + spse[b];
										string  tmp2  = spse[b] + spfi[a];
										exist[tmp] = 1;
										exist[tmp2] = 1;
								}
						}
				}
				
				cout << exist.size() << endl;
		}

}
