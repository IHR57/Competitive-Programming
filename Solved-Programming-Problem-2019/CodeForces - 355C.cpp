//Problem ID: CodeForces - 355C (Vasya and Robot)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 08/01/19
#include <bits/stdc++.h>
#define MAX 100005
#define inf 2147483647
using namespace std;


int n, l, r, ql, qr, prefixSum[MAX], suffixSum[MAX], cost[MAX];

int main()
{
    scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);

    int total = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &cost[i]);
        total += cost[i];
    }

    prefixSum[0] = 0, suffixSum[n] = total;

    int temp = 0;
    for(int i = 0; i < n; i++){
        temp += cost[i];
        prefixSum[i+1] += temp;
        suffixSum[n-i-1] = total - prefixSum[i+1];
    }
    // for(int i = 0; i <= n; i++){
    //     cout<<i<<" -> "<<prefixSum[i]<<" "<<suffixSum[i]<<endl;
    // }

    int Min = inf;
    for(int i = 0; i <= n; i++){
        int ans = prefixSum[i] * l + suffixSum[n-i] * r;
        if(i > n - i){
            ans = ans + (2 * i - n - 1) * ql;
        }
        else if(i < n - i){
            ans = ans + (n - 2 * i - 1) * qr;
        }
        Min = min(Min, ans);
    }

    printf("%d\n", Min);

    return 0;
}
