#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int sum, limit, s = 0;
    vector<int> v;

    cin>>sum>>limit;

    int n = (int) log2(limit) + 1;

    bool flag = false;

    for(int mask = limit;  mask >= 1; mask--){
        for(int k = 0; k < n; k++){
            if((mask & (1<<k)) != 0){
                if(s + (1<<k) <= sum){
                    s += (1<<k);
                    //cout<<s<<endl;
                    v.push_back(mask);
                    if(s == sum){
                        flag = true;
                    }
                    break;
                }
            }
        }
        if(flag)    break;
    }

    if(!flag)
        cout<<-1<<endl;
    else{
        cout<<v.size()<<endl;
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
