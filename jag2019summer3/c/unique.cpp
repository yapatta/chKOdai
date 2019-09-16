#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> n;
	n.push_back(6);
	n.push_back(6);
	n.push_back(3);
	n.push_back(3);
	n.push_back(4);
	n.push_back(7);
	n.push_back(10);
	sort(n.begin(), n.end());
	n.erase(unique(n.begin(), n.end()), n.end());
	for(auto e:n){
		cout << e << endl;
	}
	return 0;
}