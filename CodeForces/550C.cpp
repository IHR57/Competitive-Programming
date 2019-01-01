#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int dp[MAX][MAX];
char str1[MAX], str2[MAX];

int lcs(int i, int j)
{
    if(str1[i] == '\0' || str2[j] == '\0')
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(str1[i] == str2[j]){
        dp[i][j] = 1 + lcs(i + 1, j + 1);
    }
    else{
        dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
    }

    return dp[i][j];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>str1;

    int len = strlen(str1);

    /* if(len == 1){
        if(str1[0] == '0' || str1[0] == '8'){
            cout<<"YES"<<endl;
            cout<<str1[0]<<endl;
            return 0;
        }
    }
    else if(len == 2){
        bool flag = false;
        for(int i = 0; i < len; i++){
            if(str1[i] == '0' || str1[i] == '8'){
                cout<<"YES"<<endl;
                cout<<str1[i]<<endl;
                return 0;
            }
        }
        int number = (str1[0] - 48) * 10 + str1[1] - 48;
        if(number % 8 == 0){
            cout<<"YES"<<endl;
            cout<<str1<<endl;
            return 0;
        }
    } */
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if((i * 100 + j * 10 + k) % 8 == 0){
                    if(i == 0 && j == 0 && k == 0){
                        str2[0] = '0';
                    }
                    else if(i == 0 && j == 0){
                        str2[0] = k + 48;
                    }
                    else if(i == 0){
                        str2[0] = j + 48;
                        str2[1] = k + 48;
                    }
                    else{
                        str2[0] = i + 48;
                        str2[1] = j + 48;
                        str2[2] = k + 48;
                    }
                    memset(dp, -1, sizeof(dp));
                    int ans = lcs(0, 0);
                    int l = strlen(str2);
                    if(ans == l){
                        cout<<"YES"<<endl;
                        if(i == 0 && j == 0 && k == 0){
                            cout<<0<<endl;
                        }
                        else if(i == 0 && j == 0){
                            cout<<k<<endl;
                        }
                        else if(i == 0)
                            cout<<j<<k<<endl;
                        else
                            cout<<i<<j<<k<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}
