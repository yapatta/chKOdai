#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		int n;
		while(cin >> n && n!=0)
		{
				vector<int> al(26,0);
				vector<char> c(n);

				bool flag = true;
				for(int i=0;i<n;i++)
				{
						cin >> c[i];
				}

				for(int i=1;i<=n;i++)
				{
						al[c[i-1]-'A']++;
						int rest = n - i;

						auto ma_itr = max_element(al.begin(),al.end());
						int tmp = *ma_itr;

						//ma_itr以外での最大値を求めたい
						*ma_itr = -100;
						auto ma2_itr = max_element(al.begin(), al.end());
						*ma_itr = tmp;
						//cout << *ma_itr << " " << *ma2_itr << endl;

						if(*ma_itr <= *ma2_itr + rest){

						}else{
								cout << char('A'+ma_itr-al.begin()) << " " << i << endl;
								flag = false;
								break;
						}
				}
				if(flag){
						cout << "TIE" << endl;
				}
		}
}
