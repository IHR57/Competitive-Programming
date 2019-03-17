//Problem ID: LightOJ - 1347 (Aladdin and the Magical Lamp)
//Programmer: IQBAL HOSSAIN     Description: Suffix Array
//Date: 15/03/19
#include <bits/stdc++.h>
#define MAX 20005
using namespace std;

typedef pair<int, int> pii;
int n, c[20][MAX];

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

    for(int h = 0; (1 << h) < n; h++){
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
            pii curr = make_pair(c[h][p[i]], c[h][(p[i] + (1 << h)) % n]);
            pii prev = make_pair(c[h][p[i-1]], c[h][(p[i-1] + (1 << h)) % n]);
            if(curr != prev)
                classes++;
            c[h+1][p[i]] = classes - 1;
        }
    }

    return p;
}

//int lcp(int i, int j)
//{
//    int ans = 0, log_n = (int) log2(n);
//    if((1 << log_n) == n)
//        log_n--;
//    for(int k = log_n; k >= 0; k--){
//        if(c[k][i] == c[k][j]){
//            ans += (1 << k);
//            i += (1 << k);
//            j += (1 << k);
//        }
//    }
//
//    return ans;
//}

vector<int> lcp_construction(string s, vector<int> p)           //lcp in O(n) complexity
{
    int n = s.size();
    vector<int> Rank(n, 0);

    for(int i = 0; i < n; i++){
        Rank[p[i]] = i;
    }

    int k = 0;
    vector<int> lcp(n-1, 0);
    for(int i = 0; i < n; i++){
        if(Rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = p[Rank[i] + 1];
        while(i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[Rank[i]] = k;
        if(k)
            k--;
    }
    return lcp;
}

int main()
{
    int test, caseno = 1, len1, len2, len3;
    string s;
    char str[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        len1 = strlen(str);
        s += (string) str;
        s += "#";
        scanf("%s", str);
        len2 = len1 + strlen(str);
        s += (string) str;
        s += "$";
        scanf("%s", str);
        s += (string) str;
        s += "%";
        // cout<<s<<endl;

        //memset(c, 0, sizeof(c));

        vector<int> p = suffix_array(s);
        vector<int> lcp = lcp_construction(s, p);

        bool flag1, flag2, flag3;
        int ans = 0;
        for(int i = 0; i < p.size() - 2; i++){
            flag1 = flag2 = flag3 = false;
            for(int j = i; j < i + 3; j++){
                if(p[j] < len1)     flag1 = true;
                else if(p[j] >= len1 && p[j] <= len2)    flag2 = true;
                else        flag3 = true;
            }
            if(flag1 && flag2 && flag3){
                ans = max(ans, min(lcp[i], lcp[i+1]));
            }
        }

        printf("Case %d: %d\n", caseno++, ans);
        s.clear();
    }

    return 0;
}
