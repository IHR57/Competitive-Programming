#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int n = (int) str.length();
    str += str;
    int len = (int) str.length();

    int ans = 1, Max = 0;

    for(int i = 1; i < len; i++){
        if(str[i] != str[i-1]){
            ans++;
        }
        else{
            Max = max(Max, ans);
            ans = 1;
        }
    }

    Max = max(Max, ans);
    Max = min(Max, n);

    cout<<Max<<endl;

    return 0;
}
