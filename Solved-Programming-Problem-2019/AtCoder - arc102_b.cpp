//Problem ID: AtCoder - arc102_b (All Your Paths are Different Lengths)
//Programmer: IQBAL HOSSAIN 	Description: Graph/Bit Manupulation
//Date: 24/07/19
//Problem Link: https://atcoder.jp/contests/arc102/tasks/arc102_b
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int lg(int n)
{
	int cnt = 0;
	while(n != 1){
		n /= 2;
		cnt++;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int L;

	cin>>L;
	int n = lg(L) + 1;		//total number of vertices
	int m = (n * 2 - 2);

	for(int i = 0; i < n - 1; i++){
		if(check(L, i)){
			m++;
		}
	}

	cout<<n<<" "<<m<<endl;
	int k = 0;
	for(int i = n - 1; i >= 1; i--){
		cout<<i<<" "<<i+1<<" "<<0<<endl;
		cout<<i<<" "<<i+1<<" "<<(1<<k)<<endl;
		k++;
	}

	int sum = 0;
	k = n;
	for(int i = 0; i < n - 1; i++){
		if(check(L, i)){
			sum += (1<<i);
			cout<<1<<" "<<k<<" "<<(L - sum)<<endl;
		}
		k--;
	}

	return 0;
}