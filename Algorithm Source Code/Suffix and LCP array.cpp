#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

struct info
{
    int tup[2], idx;
    bool operator<(const info &a) const
    {
        return tup[0] != a.tup[0] ? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
}arr[MAX];

int Rank[18][MAX], step, LCP[MAX];
string text;

void build_suffix_array()
{
    int n = text.size(), jump;
    for(int i = 0; i < n; i++){
        Rank[0][i] = text[i];
        memset(arr[i].tup, 0, sizeof(arr[i].tup));
    }
    for(step = 1, jump = 1; jump <= n; step++, jump++){
        for(int j = 0; j <= n; j++){
            arr[j].idx = j;
            arr[j].tup[0] = Rank[step-1][j];
            arr[j].tup[1] = j + jump < n ? Rank[step-1][j+jump] : -1;
        }
        sort(arr, arr + n);
        Rank[step][arr[0].idx] = 0;

        for(int j = 1; j < n; j++){
            Rank[step][arr[j].idx] = arr[j].tup[0] == arr[j-1].tup[0] &&
            arr[j].tup[1] == arr[j-1].tup[1] ? Rank[step][arr[j-1].idx] : j;
        }
    }

    cout << "Suffix Array : \n\n";
    for(int i = 0; i < n; i++)
        cout<<arr[i].idx<<' '<<text.substr(arr[i].idx)<<endl;
}

void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].idx;
        id2 = arr[i].idx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        cout << arr[i - 1].idx << ' ' << arr[i].idx << ' ' << LCP[i] << endl;
    }
    for(i = 0; i < n; i++)
        cout << i << ' ' << LCP[i] << endl;
}

int main()
{
    text = "mississippi";
    build_suffix_array();
    build_LCP_array();

    return 0;
}
