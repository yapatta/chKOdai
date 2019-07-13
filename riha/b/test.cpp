#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin >> n;
	string tmp;
	getline(cin, tmp);
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin , s);
		cout << s.size() << endl;
	}
}
