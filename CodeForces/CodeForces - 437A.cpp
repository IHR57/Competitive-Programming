#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int len[4];
    string str;

    for(int i = 0; i < 4; i++){
        cin>>str;
        len[i] = str.size() - 2;
        //cout<<len[i]<<endl;
    }

    int ans = 0, idx;
    for(int i = 0; i < 4; i++){
        int cnt1 = 0, cnt2 = 0;
        for(int j = 0; j < 4; j++){
            if(i == j)
                continue;
            if(len[i]  >= (2 * len[j])){
                cnt1++;
            }
            else if(len[i] <= (len[j] / 2))
                cnt2++;
        }
       // cout<<cnt1<<" "<<cnt2<<endl;
        if(cnt1 == 3 || cnt2 == 3){
            ans++;
            idx = i;
        }
    }

    if(!ans || ans >= 2){
        cout<<"C"<<endl;
    }
    else{
        cout<<char(idx + 65)<<endl;
    }
    return 0;
}
