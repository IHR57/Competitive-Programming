//Problem ID: CodeForces - 991D (Bishwock)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 18/02/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

string s[2];

int main()
{
    cin>>s[0];
    cin>>s[1];

    int len = (int) s[0].length();

    int ans = 0, rem = 0;

    for(int i = 0; i < len; i++){
        int cnt = 0;
        if(s[0][i] == '0')
            cnt++;
        if(s[1][i] == '0')
            cnt++;
        rem += cnt;

        if(rem >= 3){
            ans++;
            rem -= 3;
        }
        else{
            rem = cnt;
        }
    }

    cout<<ans<<endl;

    return 0;
}
