#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int a[MAX], g[MAX];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i]>>g[i];
    }

    int sumA = 0, sumB = 0;

    for(int i = 0; i < n; i++){
        if(fabs((sumA + a[i]) - sumB) <= 500){
            v.push_back(0);
            sumA += a[i];
        }
        else if(fabs((sumB + g[i]) - sumA) <= 500){
            v.push_back(1);
            sumB += g[i];
        }
        else{
            cout<<"-1"<<endl;
            return 0;
        }
    }

    for(int i = 0; i < v.size(); i++){
        (v[i] == 0) ? cout<<"A" : cout<<"G";
    }
    cout<<endl;

    return 0;
}
