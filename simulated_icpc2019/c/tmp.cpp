#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll x, y;
	while(cin>>x>>y){
		ll ax = abs(x);
		ll ay = abs(y);
		
		if (ax%2==0 && ay%2==0){
			cout << ax+ay << "\n";
		}else if(ax%2==1 && ay%2==1){
			cout << ax+ay-1 << "\n";
		}else{
			if (ax==0 || ay==0){
				if (ax<=1 && ay<=1){
					cout << "1\n";
				}else{
					cout << ax+ay+1 << "\n";
				}
			}else{
				cout << ax+ay << "\n";
			}
		}
	}
}
