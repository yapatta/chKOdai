#include<bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
	ll n, q, L, R;
	cin>>n>>q>>L>>R;
	vector<ll> a(n), Q(q), x(q), s(q), t(q);
	rep(i, n) cin>>a[i];
	sort(a.begin(), a.end());
	ll solveL, solveR;
	rep(i, q){
		cin>>Q[i]>>x[i]>>s[i]>>t[i];
	}

	ll left=-1;
	ll right=n;
	//L condition
	while(right-left>1){
		ll mid = (left+right)/2;
		ll ma = a[mid];
		rep(i, q){
			if (Q[i]==1 && ma>=x[i]){
				ma = (ma+s[i])*t[i];
			}else if(Q[i]==2 && ma<=x[i]){
				ma = (ma-s[i])/t[i];
			}
		}
		if (ma>=L){
			right = mid;
		}else{
			left = mid;
		}
	}
	solveL = right;
	left=-1;
	right=n;
	//L condition
	while(right-left>1){
		ll mid = (left+right)/2;
		ll ma = a[mid];
		rep(i, q){
			if (Q[i]==1 && ma>=x[i]){
				ma = (ma+s[i])*t[i];
			}else if(Q[i]==2 && ma<=x[i]){
				ma = (ma-s[i])/t[i];
			}
		}
		if (ma>R){
			right = mid;
		}else{
			left = mid;
		}
	}
	solveR = left;
	cout << solveR-solveL+1 << endl;
	return 0;
}