#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		int h,w;
		while(cin >> h >> w && !(h==0 && w==0))
		{
				int sd = h*h + w*w;
				bool hw_exist = false;
				int ans_h = 150, ans_w = 150, ans_sd = ans_h*ans_h+ans_w*ans_w;
				for(int nh=1;nh*nh<sd;nh++)
				{
						for(int nw=nh+1;nh*nh+nw*nw<=sd;nw++)
						{
								if(nh==h && nw==w) continue;
								if(nh*nh+nw*nw == sd && h < nh && nh < ans_h)
								{
										ans_h = nh;
										ans_w = nw;
										hw_exist = true;
								}
						}
				}

				if(hw_exist)
				{
						cout << ans_h << " " << ans_w << endl;
						continue;
				}
				
				ans_h = 150, ans_w = 150, ans_sd = ans_h*ans_h+ans_w*ans_w;
				for(int nh=1;nh<=200;nh++)
				{
						for(int nw=nh+1;nw<=200;nw++)
						{
								if(nh==h && nw==w) continue;
								int tmp_sd = nh*nh+nw*nw;
								if(tmp_sd > sd)
								{
										if(tmp_sd < ans_sd)
										{
												ans_h = nh;
												ans_w = nw;
												ans_sd = tmp_sd;
										}
								}
						}
				}
				for(int nh=1;nh<=200;nh++)
				{
						for(int nw=nh+1;nw<=200;nw++)
						{
								if(nh==h && nw==w) continue;
								int tmp_sd = nh*nh+nw*nw;
								if(tmp_sd == ans_sd && nh < ans_h)
								{
										ans_h = nh;
										ans_w = nw;
								}
						}
				}

				cout << ans_h << " " << ans_w << endl;
		}
}
