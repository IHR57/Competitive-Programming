//Problem ID: LightOJ - 1314 (Name for Babies)
//Programmer: IQBAL HOSSAIN     Description: Suffix and LCP array
//Date: 13/03/19
//Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1314
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

typedef pair<int, int> pii;
int c[20][MAX], n;

vector<int> suffix_array(string s)
{
    n = s.size();
    const int alphabet = 256;
    vector<int> p(n), cnt(max(alphabet, n), 0);

    for(int i = 0; i < n; i++){
        cnt[s[i]]++;
    }
    for(int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];

    for(int i = 0; i < n; i++){
        p[--cnt[s[i]]] = i;
    }
    int classes = 1;
    c[0][p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(s[p[i]] != s[p[i-1]]){
            classes++;
        }
        c[0][p[i]] = classes - 1;
    }

    vector<int> pn(n);

    for(int h = 0; (1<<h) < n; h++){
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);

        for(int i = 0; i < n; i++){
            cnt[c[h][pn[i]]]++;
        }
        for(int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];

        for(int i = n - 1; i >= 0; i--){
            p[--cnt[c[h][pn[i]]]] = pn[i];
        }
        c[h+1][p[0]] = 0;
        classes = 1;
        for(int i = 1; i < n; i++){
            pii curr = make_pair(c[h][p[i]] , c[h][(p[i] + (1 << h)) % n]);
            pii prev = make_pair(c[h][p[i - 1]] , c[h][(p[i - 1] + (1 << h)) % n]);

            if(curr != prev){
                classes++;
            }
            c[h+1][p[i]] = classes - 1;
        }
    }

    return p;
}

int lcp(int i, int j)
{
    int ans = 0, log_n = (int) log2(n);
    if((1<<log_n) == n)
        log_n--;
    for(int k = log_n; k >= 0; k--){
        if(c[k][i] == c[k][j]){
            ans += (1 << k);
            i += (1 << k);
            j += (1 << k);
        }
    }

    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    char str[MAX];
    int p, q, test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        scanf("%d %d", &p, &q);
        int len = strlen(str);
        string s = (string) str;
        s += "$";

        memset(c, 0, sizeof(c));
        vector<int> SA = suffix_array(s);

        int result = 0;
        int temp;

        for(int i = 1; i < SA.size(); i++){
            temp = lcp(SA[i], SA[i-1]);
            //cout<<temp<<endl;
            int ln = len - SA[i];
            int l = len - SA[i] - temp;
            if(ln > q){
                l -= (ln - q);
            }
            if(temp < p){
                l -= (p - temp - 1);
            }
            if(l > 0)
                result += l;
        }
        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
