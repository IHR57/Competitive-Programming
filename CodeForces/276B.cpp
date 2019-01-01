#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[MAX];
    int counter[30] = {0};

    cin>>str;

    int len = strlen(str);

    for(int i = 0; i < len; i++){
        counter[str[i] - 'a']++;
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(counter[i] % 2 != 0){
            cnt++;
        }
    }

    if(cnt == 0 || cnt == 1){
        cout<<"First"<<endl;
        return 0;
    }
    if(cnt % 2 == 0){
        cout<<"Second"<<endl;
        return 0;
    }
    cout<<"First"<<endl;

    return 0;
}
