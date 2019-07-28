//Problem ID: CodeForces - 1175C (Electrification)
//Programmer: IQBAL HOSSAIN     Description: Brute Force/Greedy
//Date: 18/07/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n, k;

    cin>>test;

    while(test--){
        cin>>n>>k;

        for(int i = 0; i <  n; i++){
            cin>>arr[i];
        }    

        int x = 2e9, ans = -1;
        for(int i = 0; i + k < n; i++){
            int tx = (arr[i+k] - arr[i] + 1) >> 1;
            if(tx < x){
                x = tx;
                ans = (arr[i+k] + arr[i]) >> 1;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}