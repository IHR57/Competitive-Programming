// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int bit[MAX], n;

void update(int idx, int value)
{
    while(idx <= n){
        bit[idx] += value;
        idx += (idx & -idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[MAX], temp[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        temp[i] = a[i];
    }

    sort(temp, temp + n);

    int result = 1<<28;
    int Max = -10000000;

    vector<int> v;

    update(a[0], 1);
    v.push_back(a[0]);

    for(int i = 1; i < n; i++){
        int sum = query(a[i]-1);
        if(sum != i){
            v.push_back(a[i]);
        }
        update(a[i], 1);
    }

    for(int i = 0; i < v.size(); i++){
        int idx = lower_bound(temp, temp+n, v[i]) - temp;
        int temp = abs(i-idx);
        //cout<<temp<<endl;
        if(temp >= Max){
            Max = temp;
            if(v[i] < result)
                result = v[i];
        }
    }

    cout<<result<<endl;

    return 0;
}
