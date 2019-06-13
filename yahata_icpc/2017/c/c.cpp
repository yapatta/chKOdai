#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		while(1)
		{
				string a,b;
				cin >> a;
				if(a == ".") break;
				cin >> b;
				
				int err_cnt = 0;
				vector<string> st_a, st_b;
				vector<string> oth_a, oth_b;

				int oa_cnt = 0,ob_cnt = 0;
				oth_a.push_back("");
				oth_b.push_back("");

				int st = 0, num = 0;
				bool flag = false;
				for(int i=0;i<a.size();i++)
				{
						if(flag){
								if(a[i]=='\"'){
										num++;
										st_a.push_back(a.substr(st,num));
										oth_a.push_back("");
										oa_cnt++;
										flag = false;
								}else{
										num++;
								}
						}else{
								if(a[i]=='\"'){
										st = i;
										flag = true;
										num = 1;

								}else{
										oth_a[oa_cnt] += a[i];
								}
						}
						
				}
				
				st = 0, num = 0;
				flag = false;
				for(int i=0;i<b.size();i++)
				{
						if(flag){
								if(b[i]=='\"'){
										num++;
										st_b.push_back(b.substr(st,num));
										oth_b.push_back("");
										ob_cnt++;
										flag = false;
								}else{
										num++;
								}
						}else{
								if(b[i]=='\"'){
										st = i;
										flag = true;
										num = 1;

								}else{
										oth_b[ob_cnt] += b[i];
								}
						}
	
				}
				/*
				for(int i=0;i<oth_a.size();i++){
					cout << oth_a[i] << endl;
				}
				for(int i=0;i<oth_b.size();i++){
					cout << oth_b[i] << endl;
				}
				*/
				//cout << oth_a << endl;
				//cout << oth_b << endl;
				int cnm_fcnt = 0;
				if(st_a.size()==st_b.size()){
						for(int i=0;i<st_a.size();i++)
						{
								if(st_a[i]!=st_b[i]) cnm_fcnt++;
						}
				}
				bool oth_flag = true;
				if(oth_a.size()!=oth_b.size()){
						oth_flag =false;
				}else{
						for(int i=0;i<oth_a.size();i++)
						{
								if(oth_a[i]!=oth_b[i]){
									oth_flag =false;
								}
						}
				}


				if(a==b){
						cout << "IDENTICAL" << endl;
				}else if(oth_flag && cnm_fcnt == 1){
						cout << "CLOSE" << endl;
				}else{
						cout << "DIFFERENT" << endl;
				}
		}
}
