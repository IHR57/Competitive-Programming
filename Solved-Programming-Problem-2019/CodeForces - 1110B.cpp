//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    map<int, int> MP;

    int n, m, k, arr[MAX], diff[MAX], counter[MAX] = {0};

    cin>>n>>m>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(i > 0){
            diff[i] = arr[i] - arr[i-1];
        }
    }

    sort(diff + 1, diff + n);

    int idx = 1, x = 1;
    MP[1000000007] = 0;
    counter[0] = 1;
    for(int i = n - 1; i >= 1; i--){
        if(x >= k)
            break;
        if(MP.find(diff[i]) == MP.end()){
            MP[diff[i]] = idx;
            idx++;
        }
        counter[MP[diff[i]]]++;
        x++;
    }

    arr[n] = arr[n-1] + 1000000007;

    int start = 0;
    ll result = 0;
    for(int i = 1; i <= n; i++){
        int d = arr[i] - arr[i-1];
        if(MP.find(d) != MP.end()){
            if(counter[MP[d]] > 0){
                result += (ll) ((ll) arr[i - 1] - (ll) arr[start] + 1);
                start = i;
                counter[MP[d]]--;
            }
        }
    }

    cout<<result<<endl;

    return 0;
}
