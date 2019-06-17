#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
		string s;
		while(getline(cin, s) and s != "."){
				s = regex_replace(s, regex("[a-zA-Z \\.]"), "");
				while(s!=""){
						string before = s;
						s = regex_replace(s, regex("\\(\\)|\\[\\]"), "");
						if(s==before) break;
				}
				cout << ((s=="")?"yes":"no") << endl;
		}
}
