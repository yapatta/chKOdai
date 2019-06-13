#include <bits/stdc++.h>
using namespace std;

signed
main(){
	int n,p;
	while(cin >> n >> p && !(n==0 && p==0))
	{
			vector<int> s(n,0);
			int index = 0;
			int bowl = p;
			
			while(1)
			{
					if(bowl == 0)
					{
							bowl += s[index];
							s[index] = 0;
					}
					else
					{
							s[index]++;
							bowl--;
					}

					if(s[index]==p)
					{
							cout << index << endl;
							break;
					}else{
							index = (index+1) % n;
					}
			}
	}
}
