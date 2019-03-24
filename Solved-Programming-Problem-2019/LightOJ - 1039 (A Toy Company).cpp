//Problem ID: LightOJ - 1039 (A Toy Company)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 20/03/19
/*Notes: I've solved this problem using brute force method, it can be solved with bfs, as the limit is very small brute force
will also work*/
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

const int inf = 1<<28;

int isForbidden[26][26][26];
int ans;
char start[5], finish[5];

void solve(int p, int q, int r)
{
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, temp;
    int t1 = finish[0]-'a', t2 = finish[1]-'a' , t3 = finish[2]-'a';
    int s1 = start[0]-'a', s2 = start[1]-'a', s3 = start[2]-'a';

    for(int i = s1; cnt1 < 26; (p == 0) ? i = (i + 1) % 26 : i = (i - 1 + 26) % 26){
        cnt2 = 0;
        for(int j = s2; cnt2 < 26; (q == 0) ? j = (j + 1) % 26 : j = (j - 1 + 26) % 26){
            cnt3 = 0;
            for(int k = s3; cnt3 < 26; (r == 0) ? k = (k + 1) % 26 : k = (k - 1 + 26) % 26){
//                if(isForbidden[i][j][k])
//                    break;
                if(!isForbidden[i][j][k] && i == t1 && j == t2 && k == t3){
                    temp = 0;
                    if(p == 0){
                        if(t1 >= s1)
                            temp += (t1 - s1);
                        else if(t1 < s1)
                            temp += (26 + t1) - s1;
                    }
                    else if(p == 1){
                        if(t1 >= s1)
                            temp += (26 + s1 - t1);
                        else if(t1 < s1)
                            temp += (s1 - t1);
                    }
                    if(q == 0){
                        if(t2 >= s2)
                            temp += (t2 - s2);
                        else if(t2 < s2)
                            temp += (26 + t2) - s2;
                    }
                    else if(q == 1){
                        if(t2 >= s2)
                            temp += (26 + s2 - t2);
                        else if(t2 < s2)
                            temp += (s2 - t2);
                    }
                    if(r == 0){
                        if(t3 >= s3)
                            temp += (t3 - s3);
                        else if(t3 < s3)
                            temp += (26 + t3) - s3;
                    }
                    else if(r == 1){
                        if(t3 >= s3)
                            temp += (26 + s3 - t3);
                        else if(t3 < s3)
                            temp += (s3 - t3);
                    }
                    //cout<<ans<<endl;
                    ans = min(ans, temp);
                }
                cnt3++;
            }
            cnt2++;
        }
        cnt1++;
    }
}

int main()
{
    int test, caseno = 1, q;
    char str1[MAX], str2[MAX], str3[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%s", start);
        scanf("%s", finish);
        scanf("%d", &q);

        memset(isForbidden, 0, sizeof(isForbidden));

        for(int i = 0; i < q; i++){
            scanf("%s %s %s", str1, str2, str3);
            int len1  = strlen(str1), len2 = strlen(str2), len3 = strlen(str3);
            for(int j = 0; j < len1; j++){
                for(int k = 0; k < len2; k++){
                    for(int l = 0; l < len3; l++){
                        isForbidden[str1[j]-'a'][str2[k]-'a'][str3[l]-'a'] = 1;
                    }
                }
            }
        }

        ans = inf;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    solve(i, j, k);
                }
            }
        }

        if(ans == inf || isForbidden[start[0]-'a'][start[1]-'a'][start[2]-'a'] || isForbidden[finish[0]-'a'][finish[1]-'a'][finish[2]-'a']){
            printf("Case %d: -1\n", caseno++);
        }
        else
            printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}
