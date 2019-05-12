//Problem ID: AtCoder- abc125_d (Flipping Signs)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 11/05/19
//Problem Link: https://atcoder.jp/contests/abc125/tasks/abc125_d
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int arr[MAX];

int main()
{
    int n, cnt = 0;;

    scanf("%d", &n);
    ll sum = 0, Min = 1e12;
    for(int i = 1; i <= n; i++){
        scanf("%d",  &arr[i]);
        if(arr[i] < 0)
            cnt++;
        if(abs(arr[i]) < Min)
            Min = abs(arr[i]);
        sum += (ll) abs(arr[i]);
    }

    if(cnt % 2){
        sum -= 2 * Min;
    }
    printf("%lld\n", sum);

    return 0;
}
