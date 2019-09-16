#include <cstdio>
#include <iostream>

using namespace std;

int a[1<<20], b[1<<20];;

int main() {
  int N;

  scanf("%d", &N);

  for(int i=0; i<(1<<N); i++) {
    scanf("%d", a+i);
  }

  int ans = 0;

  for(int i=0; i<(1<<N); i++) {
    if(!a[i]) {
		for(int j=0;j<N;j++) {
			if (i & (1 << j)) {
				if(a[i^(1<<j)]) {
    		    	cout << -1 << endl;
					return 0;
				}
			}	
		}
		continue;
	}

    bool ok = true;

    for(int j=0; j< N; j++) {
      if (i & (1 << j)) {
        ok &= !a[i ^ (1<<j)];
      }
    }

    ans += ok;

  }


  cout << ans << endl;
}
