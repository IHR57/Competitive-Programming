//Problem ID: CodeForces - 702B (Powers of Two)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 30/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int arr[MAX];
int counter[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<int, int> mp;
    int n;

    cin>>n;

    int idx = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = idx++;
        }
        counter[mp[arr[i]]]++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int temp = mp[arr[i]];
        counter[mp[arr[i]]]--;
        for(int j = log2(arr[i]); (1 << j) <= (1 << 30); j++){
            int temp = (1 << j);
            if(temp - arr[i] > 0){
                if(mp.find(temp-arr[i]) != mp.end()){
                    ans += (ll) counter[mp[temp-arr[i]]];
                }
            }
            if(temp >= (1 << 30))
                break;
        }
    }

    cout<<ans<<endl;

    return 0;
}
