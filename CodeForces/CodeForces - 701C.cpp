//Problem ID: CodeForces - 701C (They are Everywhere)
//Programmer: IQBAL HOSSAIN     Description: Binary Search
//Date: 30/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int cs[MAX][60];
string s, str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    map<char, int> mp;

    cin>>n;
    cin>>s;

    str += "#";
    str += s;

    int idx = 0;
    for(int i = 1; i <= n; i++){
        if(mp.find(str[i]) == mp.end()){
            mp[str[i]] = idx++;
        }
    }

    for(int i = 1; i <= n; i++){
        int k = mp[str[i]];
        for(int j = 0; j < idx; j++){
            if(k == j)
                cs[i][j] += 1 + cs[i-1][j];
            else
                cs[i][j] = cs[i-1][j];
            //cout<<cs[i][j]<<" ";
        }
        //cout<<endl;
    }

    int res = 1<<28;

    for(int i = 1; i <= n; i++){
        int low = i, high = n, mid, ans = -1;
        while(low <= high){
            mid = (low + high + 1) / 2;
            int cnt = 0;
            for(int j = 0; j < idx; j++){
                if(cs[mid][j] - cs[i-1][j] > 0)
                    cnt++;
            }
            if(cnt >= idx){
                ans = mid;
                //cout<<"I AM HERE"<<endl;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(ans != -1){
            res = min(res, ans - i + 1);
        }
    }

    cout<<res<<endl;

    return 0;
}
