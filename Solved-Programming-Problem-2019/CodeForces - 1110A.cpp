//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int b, k, number, odd = 0, even = 0;

    cin>>b>>k;

    if(b % 2 == 0){
        for(int i = 0; i < k; i++){
            cin>>number;
        }
        if(number % 2 == 0){
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
        return 0;
    }
    for(int i = 0; i < k; i++){
        cin>>number;
        if(number % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    if(odd % 2 == 0){
        cout<<"even"<<endl;
    }
    else{
        cout<<"odd"<<endl;
    }

    return 0;
}
