//Problem ID: CodeForces - 922C (Cave Painting)
//Programmer: IQBAL HOSSAIN     Description: Number Theory/Brute Force
//Date: 06/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;

    cin>>n>>k;

    if(k == 1){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(k >= n && n % 2 == 0){
        cout<<"No"<<endl;
        return 0;
    }

    ll prod = 1, cnt = 0;
    while(true){
        if((n + 1) % prod == 0){
            prod++;
        }
        else{
            prod--;
            break;
        }
    }

    if(k <= prod){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}
