#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

string s;

bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
	if (x.first != y.first){
		return x.first > y.first;
	}else{
		return x.second < y.second;
	}
}

ll calc(int a, int b, int c)
{
	vector<ll> number;
	vector<char> ope;
	//priority, index
	vector<pair<int, int> > priority;

	int nest=0;
	rep(idx, s.size()){
		if (s[idx]=='(') nest++;
		else if (s[idx]==')') nest--;
		else if ('0'<=s[idx] && s[idx]<='9') number.push_back((int)(s[idx]-'0'));
		else if (s[idx]=='+'){
			ope.push_back(s[idx]);
			priority.push_back(make_pair(nest*10+a, priority.size()));
		}
		else if (s[idx]=='-'){
			ope.push_back(s[idx]);
			priority.push_back(make_pair(nest*10+b, priority.size()));
		}
		else if (s[idx]=='*'){
			ope.push_back(s[idx]);
			priority.push_back(make_pair(nest*10+c, priority.size()));
		}
 	}
 	vector<bool> use(ope.size(), false);
 	sort(priority.begin(), priority.end(), cmp);
 	
 	/*rep(i, ope.size()){
 		cout << ope[priority[i].second] << ", " << priority[i].first << ", " << priority[i].second << endl;
 	}
 	cout << endl;*/
 	
 	int size = ope.size();

 	rep(i, size){
 		int index = priority[i].second;
 		use[index] = true;
 		rep(j, index){
 			if (use[j]) index--;
 		}
		cout << "index " << index << endl;
 		if (ope[index]=='+'){
 			number[index] = number[index]+number[index+1];
 			number.erase(number.begin()+index+1);
 			//cout << res << endl;
 		}
 		else if (ope[index]=='-'){
 			number[index] = number[index]-number[index+1];
 			number.erase(number.begin()+index+1);
 			//cout << res << endl;
 		}
 		else if (ope[index]=='*'){
 			number[index] = number[index]*number[index+1];
 			number.erase(number.begin()+index+1);
 			//cout << res << endl;
 		}
 		ope.erase(ope.begin()+index);
		cout << number.size() << endl;
		for(int i=0;i<number.size();i++)
			cout << number[i] << " ";
		cout << endl;
 	}
	return number[0];
}

int main()
{
	cin>>s;
	ll maxi = LLONG_MIN;
	rep(i, 3)rep(j, 3)rep(k, 3){
		//cout << i << ", " << j << ", " << k << endl;
		maxi = max(maxi, calc(i, j, k));
		//cout << endl;
	}
	cout << maxi << "\n";
	return 0;
}
