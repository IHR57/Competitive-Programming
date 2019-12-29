//Problem ID: LightOJ - 1060 (nth Permutation)
//Programmer: IQBAL HOSSAIN     Description: Combinatorics
//Date: 25/03/19
//Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1060
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll fact[22], r;
int counter[30];

int main()
{
    fact[0] = 1;
    for(int i = 1; i <= 21; i++)
        fact[i] = (i * fact[i-1]);

    int test, caseno = 1;
    char str[50];

    scanf("%d", &test);

    while(test--){
        scanf("%s %lld", str, &r);
        r--;
        int len = strlen(str);
        memset(counter, 0, sizeof(counter));

        for(int i = 0; i < len; i++){
            counter[str[i] - 'a']++;
        }

        ll res = 0;

        printf("Case %d: ", caseno++);

        ll temp = fact[len];
        for(int i = 0; i < 26; i++){
            temp /= fact[counter[i]];
        }
        if(r >= temp){
            printf("Impossible\n");
            continue;
        }

        for(int i = 0; i < len; i++){
            for(int j = 0; j < 26; j++){
                if(counter[j]){
                    counter[j]--;
                    ll ans = fact[len - i - 1];
                    for(int k = 0; k < 26; k++){
                        ans /= fact[counter[k]];
                    }
                    if(res + ans > r){
                        printf("%c", j + 97);
                        break;
                    }
                    else if(res + ans <= r){
                        res += ans;
                        counter[j]++;
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
