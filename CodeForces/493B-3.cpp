// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
#define debug (cout<<"I AM HERE:)"<<endl)
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> a, b;
    ll n, sum_a = 0, sum_b = 0;

    cin>>n;

    ll lastValue, value;
    for(int i = 0; i < n; i++){
        cin>>value;
        if(i == n - 1)
            lastValue = value;
        if(value > 0){
            a.push_back(value);
            sum_a += value;
        }
        else{
            value = -value;
            b.push_back(value);
            sum_b += value;
        }
    }

    if(sum_a > sum_b){
        cout<<"first"<<endl;
        return 0;
    }
    else if(sum_b > sum_a){
        cout<<"second"<<endl;
        return 0;
    }
    else{
        int flag = 0;
        for(int i = 0; i < a.size() && i < b.size(); i++){
            if(a[i] > b[i]){
                cout<<"first"<<endl;
                flag = 1;
                break;
            }
            else if(b[i] > a[i]){
                cout<<"second"<<endl;
                //debug;
                flag = 1;
                break;
            }
        }
        if(!flag){
            if(a.size() > b.size()){
                cout<<"first"<<endl;
            }
            else if(b.size() > a.size()){
                cout<<"second"<<endl;
            }
            else{
                if(lastValue > 0){
                    cout<<"first"<<endl;
                }
                else{
                    cout<<"second"<<endl;
                }
            }
        }
    }

    return 0;
}
