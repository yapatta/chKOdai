#include <bits/stdc++.h>
using namespace std;

signed
main(){
		int n,m;
		while(cin >> n >> m && !(n==0 && m==0))
		{
				vector<int> s(n), t(m);
				int s_sum = 0, t_sum = 0;
				for(int i=0;i<n;i++)
				{
						cin >> s[i];
						s_sum += s[i];
				}
				for(int i=0;i<m;i++)
				{
						cin >> t[i];
						t_sum += t[i];
				}

				bool flag = false;
				int ans_s = 100, ans_t = 100;
				for(int i=0;i<n;i++)
				{
						for(int j=0;j<m;j++)
						{
								int s_tmp = s[i];
								int t_tmp = t[j];

								s_sum -= s_tmp;
								t_sum -= t_tmp;

								s_sum += t_tmp;
								t_sum += s_tmp;
								if(s_sum == t_sum)
								{
										if(ans_s+ans_t > s_tmp+t_tmp)
										{
												ans_s = s_tmp;
												ans_t = t_tmp;
										}
										flag = true;
								}

								s_sum -= t_tmp;
								t_sum -= s_tmp;

								s_sum += s_tmp;
								t_sum += t_tmp;
						}
						if(flag) break;
				}
				if(flag) cout << ans_s << " " << ans_t << endl;
				else cout << -1 << endl;
		}
}
