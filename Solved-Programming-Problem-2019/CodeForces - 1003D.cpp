//Problem ID: CodeForces - 1003D (Coins and Queries)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 23/04/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int counter[40];
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, val;

    cin>>n>>q;

    int idx = 1;
    for(int i = 0; i < n; i++){
        cin>>val;
        if(mp[val] == 0){
            mp[val] = idx++;
        }
        counter[mp[val]]++;
    }

    for(int i = 0; i <  q; i++){
        cin>>n;
        int k = log2(n), res = 0;
        for(int j = k; j >= 0; j--){
            int temp = (1 << j);
            int cnt = min(counter[mp[temp]], n / temp);
            if(cnt >  0){
                res += cnt;
                n = (n - (cnt * temp));
                if(n == 0)
                    break;
            }
            //cout<<n<<endl;
        }
        if(n == 0)
            cout<<res<<endl;
        else
            cout<<-1<<endl;
    }
}
