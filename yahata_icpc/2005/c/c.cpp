#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
		int N;
		cin >> N;
		// 1回多くgetlineしないとN回inputできない
		for(int i=0;i<=N;i++){
				string s;
				getline(cin, s);
				cout << s << endl;
		}
}
