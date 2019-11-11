#include <bits/stdc++.h>
using namespace std;

int n,t,l,b;

int add(int a,int b)
{
	if(a+b<=n)
		return a+b;
	else
		return n-(a+b-n);
}

int main() {
	while(1) {
		cin >> n >> t >> l >> b;
		if(n==0) break;
		vector<bool> L(n+1,false);
		vector<bool> B(n+1,false);
		for(int i=0;i<l;i++)
		{
			int tmp;
			cin >> tmp;
			L[tmp]=true;
		}
		for(int i=0;i<b;i++)
		{
			int tmp;
			cin >> tmp;
			B[tmp]=true;
		}

		double dp[105][105]={};

		dp[0][0]=1;

		for(int i=0;i<t;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(B[j]==true)
				{

				}
				else if(L[j]==true)
				{
					for(int k=1;k<=6;k++)
					{
						dp[add(j,k)][i+2]+=dp[j][i]/6;
					}
				}
				else
				{
					for(int k=1;k<=6;k++)
					{
						dp[add(j,k)][i+1]+=dp[j][i]/6;
					}
				}
			}
			for(int j=0;j<n;j++)
				if(B[j]==true)
				{
					dp[0][i+1]+=dp[j][i+1];
					dp[j][i+1]=0;
				}
			dp[n][i+1]+=dp[n][i];
		}

		/*
		for(int i=0;i<=n;i++)
			for(int j=0;j<=t;j++)
				cout << fixed <<setprecision(10) << dp[i][j] << (j==t ? "\n":"\t");
		*/

		cout << fixed << setprecision(10) << dp[n][t] << endl;
	}
}
