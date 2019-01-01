// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c, pos = 0, temp;

    cin>>a>>b>>c;

    a = a * 10;

    for(int i = 1; i <= 1000; i++){
        int temp = a / b;
        if(temp == c){
            pos = i;
            break;
        }
        a = (a - (temp * b)) * 10;
    }

    if(pos){
        cout<<pos<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}
