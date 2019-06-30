#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;
int a,e,s,r,n,m;

ll rev(string x, string y, int rotate)
{
	int LP[105][105];
	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++)
			LP[i][j] = INF;
	int j,k;
	LP[0][0] = 0;
	for(j=1;j<=x.size();j++) LP[j][0] = LP[j-1][0] +( (j <= x.size()-rotate) ?e : e-r);
	for(k=1;k<=y.size();k++) LP[0][k] = LP[0][k-1] + a;

	//aをbに近づけたい!
	for(j=1;j<=x.size();j++) {
    	for(k=1;k<=y.size();k++) {
     	 //a[j]を削除するか、a[j+1]にb[k]と同じ文字を挿入するか
     	 //上記２つの行為の回数で最小な方を採用
     	 int m = min(LP[j-1][k]+((j<=x.size()-rotate)?e:e-r), LP[j][k-1]+a);
     	 if(x[j-1] == y[k-1]) {
       		 //最後の文字が同じだから最後の文字がなくても編集距離は同じ
        	m = min(m,LP[j-1][k-1]);
       		 LP[j][k] = m;
      	}else {
        	//最後の文字を置換する
       		 m = min(m,LP[j-1][k-1]+s);
        	LP[j][k] = m;
      	}
    }
  }
  
  //cout << x << endl << y << endl;
  	//cout << LP[x.size()][y.size()] << endl;
	return LP[x.size()][y.size()];
}

int main(){
	string x,y;
	while(true)
	{
		cin >> x;
		if(x=="#")break;
		cin >> y;
		cin >> a >> e >> s >> r;
		n=x.size();
		m=y.size();

		ll ans = INF;
		for(int i=0;i<n;i++)
		{
			ll tmp = r*i;

			tmp += rev(x,y, i);
			if(tmp<ans)ans=tmp;
			string tmpx=x.substr(1) + x.substr(0,1);
			x=tmpx;
		}
		cout << ans << endl;
	}

}
