#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n,m;
	cin >> n >> m;
	vector<multiset<int>> v(m);
	vector<bool> used(n,false);
	for(int i=0;i<m;i++)
	{
		int k;cin >> k;
		for(int j=0;j<k;j++)
		{
			int vv;
			cin >> vv;
			vv--;
			v[i].insert(vv);
			used[vv]=true;
		}
	}
	int cnt=m;
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
		{
			if(v[i]==v[j])
			{
				cnt--;
			}
		}

	for(int i=0;i<n;i++)
		if(used[i]!=true)
		{
			cnt++;
		}

	cout << cnt << endl;
	
}
