#include <bits/stdc++.h>
using namespace std;

signed
main(){
		int n;
		while(cin >> n && n!=0)
		{
				if(n==1){
						string tmp;
						cin >> tmp;
						cout << tmp;
						continue;
				}
				vector<vector<string> >  s(11);
				for(int i=0;i<n;i++)
				{
						string tmpS;
						cin >> tmpS;

						int dot_size = 0;
						for(int j=0;j<tmpS.size();j++)
						{
								if(tmpS[j]=='.'){
										dot_size++;
								}else{
										break;
								}
						}

						if(tmpS.back() == '*' || tmpS.back() == '+'){
								string outS = "";
								outS += tmpS.back();
								s[dot_size+1+1].push_back(outS);
						}else{
								string outS = tmpS.substr(dot_size);
								s[dot_size+1].push_back(outS);
						}

				}
				int ans = 0;
				for(int sn=10;sn>=1;sn--)
				{
						for(int si=0;sn<s[sn].size();si++)
						{
								if(s[sn][si]=="*"){
										int tmp = 1;
										si++;
										while(1){
												if(s[sn][si]=="+" || s[sn][si]=="*"){
														s[sn-1].push_back(to_string(tmp));
														ans = tmp;
														cout << ans << endl;
														break;
												}else{
														tmp *= stoi(s[sn][si]);
														si++;
												}
										}
								}
								if(s[sn][si]=="+")
								{
										int tmp = 0;
										si++;
										while(1)
										{
												if(s[sn][si]=="*" || s[sn][si]=="+"){
														s[sn-1].push_back(to_string(tmp));
														ans = tmp;
														cout << ans << endl;
														break;
												}else{
														tmp += stoi(s[sn][si]);
														si++;
												}

										}
								}
						}
				}
				cout << ans << endl;
				/* debug
				for(int i=0;i<=9;i++)
				{
						for(int j=0;j<s[i].size();j++)
						{
								cout << s[i][j] << " ";
						}
						cout << endl;
				}
				*/
		}
}
