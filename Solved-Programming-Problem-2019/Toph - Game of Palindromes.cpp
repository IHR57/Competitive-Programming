//Problem ID: Toph - Game of Palindromes
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 21/05/19
//Problem Link: https://toph.co/p/game-of-palindromes
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int isPalin[MAX][MAX];

string str;

bool solve(int i, int j)
{
    if(i >= j)
        return true;
    if(isPalin[i][j] != -1)
        return isPalin[i][j];
    return isPalin[i][j] = (str[i] == str[j] && solve(i + 1, j - 1));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;
    cin>>test;

    while(test--){
        cin>>str;
        memset(isPalin, -1, sizeof(isPalin));
        int cnt = 0;
        int n = str.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j))
                    cnt++;
            }
        }
        int C = (n * (n + 1)) / 2;
        double res = (double) cnt / (double) C;
        cout<<setiosflags(ios::fixed)<<setprecision(3);
        cout<<res<<endl;
    }

    return 0;
}