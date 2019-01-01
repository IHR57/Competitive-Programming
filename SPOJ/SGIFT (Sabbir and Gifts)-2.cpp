//Problem ID: SPOJ SGIFT (Sabbir and Gifts)
//Programmer: IQBAL HOSSAIN     Description: BIT
//Date: 02-12-17
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long ll;

ll tree[MAX];

void update(int idx, int n, ll value)
{
    while(idx <= n){
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

ll query(int idx)
{
    ll sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
    int n, q, a, b;
    set<int> s;

    scanf("%d", &n);
    ll arr[n+10], temp[n+10];

    for(int i = 1; i <= n; i++){
        scanf("%lld", &arr[i]);
        temp[i] = arr[i];
        s.insert(arr[i]);
    }

    sort(temp + 1, temp + n + 1);       //sort temp

    for(int i = 1; i <= n; i++){
        int idx = lower_bound(temp + 1, temp + n + 1, arr[i]) - temp;
        update(idx, n, arr[i]);
    }

    scanf("%d", &q);

    while(q--){
        scanf("%d %d", &a, &b);
        int idx1 = lower_bound(temp + 1, temp + n + 1, a) - temp;
        int idx2 = lower_bound(temp + 1, temp + n + 1, b) - temp;
        //cout<<idx1<<" "<<idx2<<endl;
        ll result;
        if(s.find(b) != s.end())
            result = query(idx2) - query(idx1-1);
        else
            result = query(idx2-1) - query(idx1-1);
        printf("%lld\n",result);
    }

    return 0;
}
