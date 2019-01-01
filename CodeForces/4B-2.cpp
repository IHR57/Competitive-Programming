#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int d, sumTime, rem[MAX], fst[MAX], cs[MAX], x, y;

    cin>>d>>sumTime;

    int sum = 0;
    for(int i = 0; i < d; i++){
        cin>>x>>y;
        sum += x;
        rem[i] = y - x;
        fst[i] = x;
        cs[i] = 0;
    }

    if(sumTime < sum){
        cout<<"NO"<<endl;
        return 0;
    }
    else if(sumTime == sum){
        cout<<"YES"<<endl;
        for(int k = 0; k < d; k++){
            cout<<fst[k]<<" ";
        }
        cout<<endl;
        return 0;
    }
    else{
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0; i < d; i++){
                if(rem[i] != 0){
                    sum += 1;
                    rem[i] -= 1;
                    cs[i]++;
                    flag = true;
                    if(sum == sumTime){
                        cout<<"YES"<<endl;
                        for(int k = 0; k < d; k++){
                            cout<<fst[k] + cs[k]<<" ";
                        }
                        cout<<endl;
                        return 0;
                    }
                }
            }
        }
        if(!flag)
            cout<<"NO"<<endl;
    }

    return 0;
}
