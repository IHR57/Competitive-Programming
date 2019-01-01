#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int zero, one;

    cin>>zero>>one;

    if(zero * 2 + 2 < one){
        cout<<-1<<endl;
        return 0;
    }
    if(zero > one + 1){
        cout<<-1<<endl;
        return 0;
    }
    if(zero == one){
        for(int i = 0; i < zero; i++){
            cout<<"10";
        }
        cout<<endl;
        return 0;
    }
    if(zero == one + 1){
        cout<<0;
        for(int i = 0; i < one; i++){
            cout<<"10";
        }
        cout<<endl;
        return 0;
    }

    int diff = one - zero;
    int Min = min(min(one, zero), diff);

    one -= 2 * Min;
    zero -= Min;

    for(int i = 0; i < Min; i++){
        cout<<"110";
    }

    if(one == zero){
        for(int i = 0; i < one; i++){
            cout<<"10";
        }
    }
    else{
        if(one == 1){
            cout<<"1";
        }
        else if(one == 2){
            cout<<"11";
        }
    }

    cout<<endl;

    return 0;
}
