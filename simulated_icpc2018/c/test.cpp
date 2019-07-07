#include <bits/stdc++.h>
#define A 0
#define B 1
#define C 2
#define D 3
using namespace std;
string s;

int makeHash(int a[]) {
	stack<int> st;
	for(int i=s.size()-1;i>=0;i--) {
		if('a'<=s[i] and s[i]<='d') {
				if(s[i]=='a') st.push(a[A]);
				else if(s[i]=='b') st.push(a[B]);
				else if(s[i]=='c') st.push(a[C]);
				else if(s[i]=='d') st.push(a[D]);
			}
			else if(s[i]=='+') {
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				st.push(x | y);
			}
			else if(s[i]=='*') {
				int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x & y);
			}
			else if(s[i]=='^') {
				int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x ^ y);
			}
		}
	return st.top();

}
int main() {
	string p;
	while(cin >> s) {
		if(s==".") break;
		cin >> p;
		vector<int> a(4);
		for(int i=0;i<4;i++) {
			a[i] = p[i] - '0';
		}
		stack<int> st;
		for(int i=s.size()-1;i>=0;i--) {
			if('a'<=s[i] and s[i]<='d') {
				if(s[i]=='a') st.push(a[A]);
				else if(s[i]=='b') st.push(a[B]);
				else if(s[i]=='c') st.push(a[C]);
				else if(s[i]=='d') st.push(a[D]);
			}
			else if(s[i]=='+') {
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				st.push(x | y);
			}
			else if(s[i]=='*') {
				int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x & y);
			}
			else if(s[i]=='^') {
				int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x ^ y);
			}
		}
		int value = st.top();
		int cnt = 0;
		int tmp[4];
		for(int i=0;i<=9;i++) {
			for(int j=0;j<=9;j++) {
				for(int k=0;k<=9;k++) {
					for(int l=0;l<=9;l++) {
						tmp[0] = i;
						tmp[1] = j;
						tmp[2] = k;
						tmp[3] = l;
						if(makeHash(tmp) == value) cnt++;
					}
				}
			}
		}
		cout << value << " " << cnt << endl;
	}
}


