#include<iostream>
#include<vector>
#include <algorithm>
const int MAX = 1299709;
using namespace std;

bool isPrime[MAX+5];
int seqPrime[MAX+5];
int ITR = 0;

void  eratos() {
	// 初期化
	for(int i=0;i<=MAX;i++) {
		isPrime[i] = true;
	}
	for(int i=2;i<=MAX;i++) {
		if(isPrime[i]) {
			seqPrime[ITR++] = i;
			for(int j=2*i;j<=MAX;j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	eratos();
	int k;
	while(1) {
		cin >> k;
		if(k==0) break;
		auto now = upper_bound(seqPrime, seqPrime+ITR, k);
		auto before = now-1;
		if(*before == k) cout << 0 << endl;
		else cout << (*now-*before) << endl;
	}
}
