//Problem ID: CodeForces - 742B (Arpa’s obvious problem and Mehrdad’s terrible solution)
//Programmer: IQBAL HOSSAIN     Description: MATH
//Date: 27/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int arr[MAX], counter[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;

    cin>>n>>x;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        counter[arr[i]]++;
    }

    ll ans = 0;

    for(int i = n - 1; i >= 0; i--){
        counter[arr[i]]--;
        int temp = (arr[i] ^ x);
        if(temp <= 100000 && counter[temp]){
            ans += (ll) counter[temp];
        }
    }

    cout<<ans<<endl;

    return 0;
}
