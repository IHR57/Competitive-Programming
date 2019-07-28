#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;
    ll k;

    cin>>str;
    cin>>k;

    int len = str.size();

    int cnt = 0, n = -1;
    for(int i = 0; i < len; i++){
        if(str[i] != '1'){
            n = str[i] - 48;
            break;
        }
        else
            cnt++;
    }

    if(k <= cnt || n == -1){
        cout<<"1"<<endl;
    }
    else{
        cout<<n<<endl;
    }

    return 0;
}