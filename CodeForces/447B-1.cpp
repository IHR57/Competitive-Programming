#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[MAX];
    int k, weight[30];

    cin>>str;
    cin>>k;

    int Max = 0;
    for(int i = 0; i < 26; i++){
        cin>>weight[i];
        if(weight[i] > Max)
            Max = weight[i];
    }

    int len = strlen(str);

    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += ((i + 1) * weight[str[i] - 97]);
    }

    //cout<<sum<<endl;
    for(int i = 0; i < k; i++){
        sum += ((i + len + 1) * Max);
    }

    cout<<sum<<endl;

    return 0;
}
