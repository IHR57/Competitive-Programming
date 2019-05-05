//Problem ID: LightOJ - 1393 (Crazy Calendar)
//Programmer: IQBAL HOSSAIN     Description: Game Theory (NIM Game)
//Date: 02/05/19
//https://codeforces.com/blog/entry/44651
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

map<string, int> mp;

int main()
{
    int test, caseno = 1, r, c;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &r, &c);
        int ans = 0, val;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                scanf("%d", &val);
                int temp = (r - i) + (c - j);
                if(temp % 2)
                    ans ^= val;
            }
        }
        if(ans){
            printf("Case %d: win\n", caseno++);
        }
        else{
            printf("Case %d: lose\n", caseno++);
        }
    }

    return 0;
}
