//Problem ID: CodeForces - 1065C (Make it Equal)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 11/02/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

int level[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val, Min = 1<<28, Max = -1;
    ll k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>val;
        level[val]++;
        if(val < Min)
            Min = val;
        Max = max(Max, val);
    }

    for(int i = 200000; i >= 2; i--){
        if(level[i]){
            level[i-1] += level[i];
        }
    }

    int sum = 0;
    int cnt = 0, last = Max;
    for(int i = 200000; i >= Min; i--){
        if((sum + level[i]) <= k){
            sum = sum + level[i];
        }
        else{
            last = i;
            cnt++;
            sum = level[i];
        }
    }

    if(last != Min)
        cnt++;
    cout<<cnt<<endl;

    return 0;
}
