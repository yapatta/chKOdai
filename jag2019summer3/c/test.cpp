#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m;
	cin >> n >> m;
	vector<long long> l(n),r(n);
	set<long long> S;
	map<long long,long long> M;
	for(long long i=0;i<n;i++)
	{
		cin >> l[i] >> r[i];
		S.insert(l[i]); S.insert(r[i]);
	}
	long long idx=0;
	for(auto it=S.begin(); it!=S.end(); it++){
		M[*it] = idx++;
	}
	vector<long long> imos(S.size()+1,0);
	for(long long i=0;i<n;i++){
		long long left = M[l[i]];
		long long right = M[r[i]];
		imos[left]++;
		imos[right+1]--;
	}

	long long mx=imos[0];
	for(long long i=0;i<imos.size()-1;i++)
	{
		imos[i+1]=imos[i+1]+imos[i];
		if(imos[i+1]>mx)
			mx=imos[i+1];
	}
	long long lll=m+5,rrr=-1;
	for(long long i=0;i<n;i++)
	{
		if(imos[M[l[i]]]==mx)
			if(l[i]<lll)lll=l[i];
				
		if(imos[M[r[i]]]==mx)
			if(r[i]>rrr)rrr=r[i];
	}
	
	cout << (mx-1)*m+(mx%2==0 ? m-lll:rrr) << endl;
//	cout << mx << endl;
//	cout << lll << " " << rrr << endl;

}
