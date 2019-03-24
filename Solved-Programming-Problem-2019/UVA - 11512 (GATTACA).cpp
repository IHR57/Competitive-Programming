//Problem ID: UVA - 11512 (GATTACA)
//Programmer: IQBAL HOSSAIN     Description: Suffix Array
//Date: 19/03/19
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 1005
using namespace std;

typedef pair<int, int> pii;
int c[15][MAX];
int n;

vector<int> build_suffix_array(string s)
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
    for(int k = log_n; k >= 0; k--){
        if(c[k][i] == c[k][j]){
            ans += (1 << k);
            i += (1 << k);
            j += (1 << k);
        }
    }

    return ans;
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
    int test;
    string str;

    cin>>test;

    while(test--){
        cin>>str;
        int len = (int) str.length();
        str += "$";

        vector<int> p = build_suffix_array(str);
        vector<int> lcp = lcp_construction(str, p);

        int Max = 0;

        for(int i = 0; i < lcp.size(); i++){
            Max = max(Max, lcp[i]);
        }

        if(Max == 0){
            cout<<"No repetitions found!"<<endl;
            continue;
        }
        int idx = -1, flag = 0;
        string ans = "";
        for(int i = 0; i < lcp.size(); i++){
            if(lcp[i] == Max){
                idx = i;
                ans += str.substr(p[i], Max);
                break;
            }
        }

        int cnt = 2;
        for(int i = idx + 1; i < lcp.size(); i++){
            if(lcp[i] == Max)
                cnt++;
            else
                break;
        }

        cout<<ans<<" "<<cnt<<endl;
    }

    return 0;
}
