// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, counter[26] = {0};

    cin>>n;

    string str;

    cin>>str;

    //int len = (int) str.size();

    if(n == 1){
        cout<<"Yes"<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        counter[str[i]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(counter[i] > 1){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;

    return 0;
}
