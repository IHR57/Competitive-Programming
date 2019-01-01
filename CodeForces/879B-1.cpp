//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long lint;

int main()
{
    lint n, k, arr[600], counter[600] = {0};

    scanf("%lld %lld", &n, &k);

    lint Max = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        if(arr[i] > Max)
            Max = arr[i];
    }

    lint temp = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > temp){
            temp = arr[i];
            counter[temp]++;
        }
        else{
            counter[temp]++;
        }
    }

    int flag = 0;
    lint ans;

    for(int i = 0; i < n; i++){
        if(counter[arr[i]] >= k){
            flag = 1;
            ans = arr[i];
            break;
        }
    }

    if(flag)
        printf("%lld\n", ans);
    else
        printf("%lld\n", Max);

    return 0;
}
