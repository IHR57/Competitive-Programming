//Problem ID: CodeForces - 898E (Squares and not squares)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 07/05/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef long long ll;

PQ sq, nonSq;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    int val;

    for(int i = 0; i < n; i++){
        cin>>val;
        int temp = sqrt(val);
        if(temp * temp == val){
            if(val == 0)
                nonSq.push(2);
            else
                nonSq.push(1);
        }
        else{
            int k = min(val - temp * temp, (temp + 1) * (temp + 1) - val);
            sq.push(k);
        }
    }

    ll ans = 0;
    if(sq.size() > n / 2){
        while(sq.size() != n / 2){
            ans += (ll) sq.top();
            sq.pop();
        }
    }
    else if(nonSq.size() > n / 2){
        while(nonSq.size() != n / 2){
            ans += (ll) nonSq.top();
            nonSq.pop();
        }
    }

    cout<<ans<<endl;

    return 0;
}
