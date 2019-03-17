//Problem ID: LightOJ - 1428 (Melody Comparison)
//Programmer: IQBAL HOSSAIN     Description: Suffix Array
//Date: 17/03/19
#include <bits/stdc++.h>
#define MAX 50005
using namespace std;

int pi[MAX], idx[MAX], lcp[MAX];
typedef pair<int, int>  pii;
int c[20][MAX];

vector<int> suffix_array(string s)
{
    int n = s.size();
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

    p.erase(p.begin());

    int log_n = (int) log2(n);
    for(int i = 1; i < n; i++){
        int x = p[i], y = p[i-1];
        lcp[i] = 0;
        if((1 << log_n) == n)
            log_n--;
        for(int k = log_n; k >= 0 && x < n && y < n; k--){
            if(c[k][x] == c[k][y]){
                lcp[i] += (1 << k);
                x += (1 << k);
                y += (1 << k);
            }
        }
    }

    return p;
}

//vector<int> lcp_construction(string s, vector<int> p)
//{
//    int n = s.size();
//    vector<int> Rank(n, 0);
//
//    for(int i = 0; i < n; i++){
//        Rank[p[i]] = i;
//    }
//
//    int k = 0;
//    vector<int> lcp(n-1, 0);
//    for(int i = 0; i < n; i++){
//        if(Rank[i] == n - 1){
//            k = 0;
//            continue;
//        }
//        int j = p[Rank[i] + 1];
//        while(i + k < n && j + k < n && s[i+k] == s[j+k])
//            k++;
//        lcp[Rank[i]] = k;
//        if(k)
//            k--;
//    }
//    return lcp;
//}

void kmp(string s)
{
    int n = s.length();
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

void kmp2(string str, string sbstr)
{
    int n = (int) str.length();
    int m = (int) sbstr.length();

    int i = 0, j = 0;
    while(i < n){
        if(str[i] == sbstr[j]){
            i++, j++;
        }
        if(j == m){
            idx[i-j] = i - j;
            j = pi[j-1];
        }
        else if(i < n && str[i] != sbstr[j]){
            if(j != 0)
                j = pi[j-1];
            else
                i++;
        }
    }
}

int main()
{
    int test, caseno = 1;
    string str, sbstr;
    char s[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%s", s);
        str = (string) s;
        scanf("%s", s);
        sbstr = (string) s;

        kmp(sbstr);
        int n = (int) str.length();
        int m = (int) sbstr.length();

        memset(idx, -1, sizeof(idx));
        str += "$";
        vector<int> p = suffix_array(str);
//        for(int i = 0; i < n; i++)
//            cout<<lcp[i]<<" ";
//        cout<<endl;
//        vector<int> lcp = lcp_construction(str, p);
        int ans = 0;

        if(n >= m){
            int temp = n;
            kmp2(str, sbstr);
            for(int i = n - 1; i >= 0; i--){
                if(idx[i] == -1)
                    idx[i] = temp;
                else
                    temp = idx[i];
            }
            for(int i = 0; i < n; i++){
                int t = min(n, idx[p[i]] + m - 1) - p[i] - lcp[i];
                if(t > 0)   ans += t;
            }
        }

        printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}
