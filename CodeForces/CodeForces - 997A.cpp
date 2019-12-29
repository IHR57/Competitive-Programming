//Problem ID: CodeForces - 997A (Convert To ones)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 18/02/19
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;
string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x, y;

    cin>>n>>x>>y;
    cin>>str;

    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '0' && flag == false){
            cnt++;
            flag = true;
        }
        else if(str[i] != '0'){
            flag = false;
        }
    }

    int k = 0;
    ll Min = (cnt * y);
    for(int i = cnt; i >= 1; i--){
        ll temp = (i * y) + (k * x);
        Min = min(Min, temp);
        k++;
    }

    cout<<Min<<endl;

    return 0;
}
