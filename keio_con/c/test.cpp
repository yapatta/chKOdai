#include <bits/stdc++.h>
using namespace std;

string s;
long long it;
vector<string> perm;

long long numCalc(vector<long long> num, string ope) {
	
	
	for(long long o=0;o<3;o++) {
		for(long long i=0;i<ope.size();i++) {
			if(find(perm[o].begin(), perm[o].end(),ope[i]) != perm[o].end()
			{
				if(ope[i]=='+')
				{
					num[i] += num[i+1];
				}else if(ope[i]=='-')
				{
					num[i] -= num[i+1];
				}else if(ope[i]=='*')
				{
					num[i] *= num[i+1];
				}
				num.erase(num.begin()+(i+1));
				ope.erase(ope.begin()+i);
				i--;
			}
		}
	}
	return num[0];
}
long long calc(void)
{
	long long ans = 0;
	string ope;
	vector<long long> num; 
	while(it<s.size())
	{
		if(s[it]=='(')
		{
			it++;
			num.push_back(calc());
		}
		else if(s[it]==')')
		{
			it++;
			return numCalc(num,ope);
		}
		else
		{
			if(s[it]<'0' or s[it]>'9')
				ope.push_back(s[it]);
			else
			{
				string tmp = "";
				tmp += s[it++];
				while(it<s.size())
				{
					if(s[it]<'0' or s[it]>'9')
					{
						it--;
						break;
					}
					tmp+=s[it++];
				}
				num.push_back(stoll(tmp));
			}
			it++;
		}
	}
	return numCalc(num, ope);
}

int main() {
	cin >> s;
	long long ans = LLONG_MIN;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				perm=vector<string>(3);
				perm[i].push_back('+');
				perm[j].push_back('-');
				perm[k].push_back('*');
				it=0;
				ans = max(ans, calc());
			}
		}
	}
	cout << ans << endl;
}
