#include <cstdio>
#include <iostream>

using namespace std;

void FZT(int n, int *a) {
  for(int i=0; i<n; i++)
    for(int j=0; j<(1<<n); j++)
      if(!(j & (1<<i))) a[j] |= a[j | (1 << i)];
}

void FZT2(int n, int *a) {
  for(int i=0; i<n; i++)
    for(int j=0; j<(1<<n); j++)
      if((j & (1<<i))) a[j] |= a[j ^ (1 << i)];
}



int a[1<<20], b[1<<20];;

int main() {
  int N;

  scanf("%d", &N);

  for(int i=0; i<(1<<N); i++) {
    scanf("%d", a+i);
    b[i] = a[i];
  }

  FZT2(N, a);
  //FZT(N, a);

  for(int i=0; i<(1<<N); i++) {
    if(b[i] != a[i]) {
      puts("-1");
      return 0;
    }
  }

  int ans = 0;

  for(int i=0; i<(1<<N); i++) {
    if(!a[i]) continue;

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
