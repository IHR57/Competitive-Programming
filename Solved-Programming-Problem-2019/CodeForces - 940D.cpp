//Problem ID: CodeForces - 940D (Alena and the Heater)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 29/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int temp[10], arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(i < 5){
            temp[i] = arr[i];
        }
    }

    cin>>str;

    ll l = -1e9, r = 1e9;

    for(int i = 4; i < n; i++){
        temp[i%5] = arr[i];
        if(str[i] == str[i-1]){
            continue;
        }
        if(str[i] == '0'){
            ll t = *min_element(temp, temp + 5);
            r = min(r, t - 1);
        }
        else{
            ll t = *max_element(temp, temp + 5);
            l = max(l, t + 1);
        }
    }

    cout<<l<<" "<<r<<endl;

    return 0;
}
