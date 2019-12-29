//Problem ID: SPOJ - ADASTRNG (ADA ans Substring)
//Programmer: IQBAL HOSSAIN     Description: Suffix Array
//Date: 18/03/19
//Problem Link: https://www.spoj.com/problems/ADASTRNG/
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<int> build_suffix_array(string s)
{
    int n = (int) s.length();
    const int alphabet = 256;   //total ASCII character

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for(int i = 0; i < n; i++){
        cnt[s[i]]++;
    }
    for(int i = 1; i < alphabet; i++){
        cnt[i] += cnt[i-1];
    }

    for(int i = 0; i < n; i++)      //counting sort
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;

    for(int i = 1; i < n; i++){     //assigning class
        if(s[p[i]] != s[p[i-1]]){
            classes++;
        }
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);

    for(int h = 0; (1<<h) < n; h++){
        for(int i = 0; i < n; i++){
           pn[i] = p[i] - (1<<h);
           if(pn[i] < 0)
               pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        //memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;

        for(int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];

        for(int i = n - 1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        cn[p[0]] = 0;
        classes = 1;

        for(int i = 1; i < n; i++){
            pii cur = make_pair(c[p[i]], c[(p[i] + ( 1<< h)) % n]);
            pii prev = make_pair(c[p[i-1]], c[(p[i-1] + (1 << h)) % n]);

            if(prev != cur){
                classes++;
            }
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }

    return p;
}

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
    char s[MAX];
    string str;
    ll counter[30] = {0};

    scanf("%s", s);
    int len = strlen(s);
    str = (string) s;
    str += "$";

    vector<int> p = build_suffix_array(str);
    vector<int> lcp = lcp_construction(str, p);

    for(int i = 1; i < p.size(); i++){
        int temp = (len - p[i]) - lcp[i-1];
        counter[str[p[i]] - 'a'] += (ll) temp;
    }

    for(int i = 0; i < 26; i++){
        printf("%lld ", counter[i]);
    }
    printf("\n");

    return 0;
}
