//Problem ID: Toph - Zacob the Batsman
//Programmer: IQBAL HOSSAIN     Description: Math
//Date: 21/05/19
//Problem Link: https://toph.co/p/zacob-the-batsman
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;
    ll n;
    cin>>test;

    while(test--){
        cin>>n;

        if(n % 4 == 0 || (n > 4 && n % 4 == 2)){
            cout<<"Zacob Zacob!"<<endl;
        }
        else{
            cout<<"Sorry Zacob!"<<endl;
        }
    }

    return 0;
}