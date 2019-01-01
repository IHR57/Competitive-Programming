#include <bits//stdc++.h>
using namespace std;

int h[55], v[55];
vector <int> value;

int main()
{
    int n, horizontal, vertical;

    cin>>n;

    memset(h, 0, sizeof(h));
    memset(v, 0, sizeof(v));
    value.clear();

    for(int i = 1; i <= n*n; i++){
        cin>>horizontal>>vertical;
        if(!h[horizontal] && !v[vertical]){
            value.push_back(i);
            h[horizontal]++;
            v[vertical]++;
        }
    }

    int Size = value.size();

    for(int i = 0; i < Size-1; i++){
        cout<<value[i]<<" ";
    }
    cout<<value[Size -1]<<endl;

    //cout<<endl;

    return 0;
}
