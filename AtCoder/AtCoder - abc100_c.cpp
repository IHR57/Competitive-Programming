#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;

ll arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, cnt = 0;;

    cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
    	while(!(arr[i] & 1)){
	    	arr[i] >>= 1;
	    	cnt++;
	    }
    }

    cout<<cnt<<endl;

    return 0;
}
