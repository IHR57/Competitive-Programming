//Problem ID: CodeChef - SUMAGCD (Sum and GCD)
//Programmer: IQBAL HOSSAIN     Description: Data Structures
//Date: 09/06/19
//Problem Link: https://www.codechef.com/JUNE19A/problems/SUMAGCD
#include <bits/stdc++.h>
#define MAX 100005
#define INF 1e9
using namespace std;

typedef long long ll;

int arr[MAX], tree[4*MAX], val;

void build(int node, int l, int r)
{
    if(l == r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = __gcd(tree[node*2], tree[node*2+1]);
}

int query(int node, int l, int r, int i, int j)
{
    if(i > j)
        return val;
    if(i == l && j == r)
        return tree[node];
    int mid = (l + r) >> 1;
    return __gcd(query(node * 2, l, mid, i, min(j, mid)), query(node*2+1, mid + 1, r, max(i, mid + 1), j));

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int test, n;
    map<int, int> mp;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int k = 0, idx = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            if(mp[val] == 0){
                mp[val] = idx++;
                arr[k++] = val;
            }
        }
        if(k == 1){
            printf("%d\n", arr[0] * 2);
            continue;
        }
        if(k == 2){
            printf("%d\n", arr[0] + arr[1]);
            continue;
        }
        build(1, 0, k - 1);
        int Max = 0;
        val = arr[1];
        int temp = query(1, 0, k - 1, 1, k - 1);
        Max = max(Max, temp + arr[0]);
        val = arr[0];
        temp = query(1, 0, k - 1, 0, k-2);
        Max = max(Max, temp + arr[k-1]);

        for(int i = 1; i < k - 1; i++){
            int t1 = query(1, 0, k - 1, 0, i - 1);
            int t2 = query(1, 0, k - 1, i + 1, k-1);
            Max = max(Max, __gcd(t1, t2) + arr[i]);
        }

        printf("%d\n", Max);
        mp.clear();
    }
    return 0;
}