//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    int len;

    cin>>len;
    cin>>str;

    int sum = 0;
    for(int i = 0; i < len; i++){
        if((str[i] - 48) % 2 == 0){
            sum += (i + 1);
        }
    }

    cout<<sum<<endl;

    return 0;
}
