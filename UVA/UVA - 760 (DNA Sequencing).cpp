//Problem ID: UVA - 760 (DNA Sequencing)
//Programmer: IQBAL HOSSAIN     Description: Suffix Array
//Date: 16/03/19
//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=701
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <cstring>
#define MAX 305
using namespace std;

typedef pair<int, int> pii;

vector<int>  build_suffix_array(string s)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for(int i = 0; i < n; i++)
        cnt[s[i]]++;
    for(int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];

    for(int i = 0; i < n; i++){
        p[--cnt[s[i]]] = i;
    }
    int classes = 1;
    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; h++){
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0)
                pn[i] += n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);
        for(int i = 0; i < n; i++){
            cnt[c[pn[i]]]++;
        }
        for(int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for(int i = n - 1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        classes = 1;
        cn[p[0]] = 0;

        for(int i = 1; i < n; i++){
            pii curr = make_pair(c[p[i]], c[(p[i] + (1 << h)) % n]);
            pii prev = make_pair(c[p[i-1]], c[(p[i-1] + (1 << h)) % n]);
            if(curr != prev)
                classes++;
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
    string str1, str2, str;
    int line = 0;

    while(cin>>str1>>str2){
        str = str1 + "#" + str2 + "$";
        int len = (int) str1.size();
        //cout<<str<<endl;
        vector<int> p = build_suffix_array(str);
        vector<int> lcp = lcp_construction(str, p);

        int Max = 0;
        bool flag1, flag2;
        for(int i = 0; i < p.size() - 1; i++){
            flag1 = flag2 = false;
            for(int j = i; j < i + 2; j++){
                (p[j] <= len) ? flag1 = true : flag2 = true;
            }
            if(flag1 && flag2){
                Max = max(Max, lcp[i]);
            }
        }
        if(line)
            cout<<endl;
        line = 1;
        if(Max == 0)
            cout<<"No common sequence."<<endl;
        else{
            set<string> vs;
            for(int i = 0; i < p.size() - 1; i++){
                flag1 = flag2 = false;
                for(int j = i; j < i + 2; j++){
                    (p[j] <= len) ? flag1 = true : flag2 = true;
                }
                if(flag1 && flag2){
                    if(lcp[i] == Max){
                        string temp = str.substr(p[i], lcp[i]);
                        vs.insert(temp);
                    }
                }
            }
            set<string> :: iterator it;
            for(it = vs.begin(); it != vs.end(); it++){
                cout<<*it<<endl;
            }
        }
        str.clear();
    }

    return 0;
}
