#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef pair<int, int> pii;

vector<int> sort_cycle_shifts(string s)
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

vector<int> suffix_array_construction(string s)
{
    s += "$";
    vector<int> sorted_shifts = sort_cycle_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());

    return sorted_shifts;
}

int main()
{
    string s = "mississippi";
    vector<int> v = suffix_array_construction(s);

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
