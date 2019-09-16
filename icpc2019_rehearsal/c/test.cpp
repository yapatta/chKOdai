#include<bits/stdc++.h>

using namespace std;
int judge[] = {5,7,5,7,7};
int main()
{
    int n;
    while(cin >> n)
    {
		if(n==0)
			break;
        vector<string> s;
        for(int i=0;i<n;i++)
        {
            string tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int cnt = 0, itr = i, jd = 0;
            bool flag = true;
            while(1)
            {
                cnt += s[itr].size();
                if(cnt > judge[jd])
                {
                    flag = false;
                    break;
                }else if(cnt == judge[jd])
                {
                    jd++;
                    cnt = 0;
                    if(jd==5)
                        break;
                }
                itr++;
                if(itr>=s.size())
                {
                    flag = false;
                    break;
                }
            }
			if(flag)
				ans.push_back(i+1);
        }
		for(int i=0;i<1;i++)
			cout << ans[i] << endl;
    }
}
