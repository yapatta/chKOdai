#include <bits/stdc++.h>
using namespace std;
int main() {
	string h;
	int y,m,d;
	while(cin >> h) {
		if(h=="#") break;
		cin >> y >> m >> d;
		if( (y==31 and m>=5) or y>=32 ){
			cout << "? " << y-30 << " " << m << " " << d << endl;
		}else {
			cout << h << " " << y << " " << m << " " << d << endl;
		}
	}
}
