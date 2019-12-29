//Problem ID: CodeForces - 774D (Lie or Truth)
//Programmer: IQBAL HOSSAIN     Description: Sorting
//Date: 24/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> a, b;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, v, l, r;

    cin>>n>>l>>r;

    for(int i = 0; i < n; i++){
        cin>>v;
        a.push_back(v);
    }
    for(int i = 0; i < n; i++){
        cin>>v;
        b.push_back(v);
    }

    sort(a.begin() + l - 1, a.begin() + r);
    sort(b.begin() + l - 1, b.begin() + r);

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            cout<<"LIE"<<endl;
            return 0;
        }
    }

    cout<<"TRUTH"<<endl;

    return 0;
}
