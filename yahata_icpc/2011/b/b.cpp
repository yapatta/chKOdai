#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
		string s;
		while(getline(cin, s) and s != "."){
				int maru = 0, kaku = 0;
				bool flag = true, lkaku = false, lmaru = false;
				for(int i=0;i<s.size();i++){
						if(s[i]=='(') {
								lmaru = true;
								maru++;
						}
						if(s[i]=='[') {
								lkaku = true;
								kaku++;
						}
						if(s[i]==')'){
								if(maru==0){
										flag = false;
										break;
								}else{
										if(lkaku){
												flag = false;
												break;
										}else{
												maru--;
												if(maru==0) lmaru = false;
										}										
								}
						}
						if(s[i]==']'){
								if(kaku==0){
										flag = false;
										break;
								}else{
										if(lmaru){
												flag = false;
												break;
										}else{
												kaku--;
												if(kaku==0) lkaku = false;
										}
								}
						}
				}
				
				if(flag && maru==0 && kaku==0) cout << "yes" << endl;
				else cout << "no" << endl;
		}
}
