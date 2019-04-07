//Problem ID: CodeForces - 659D (Bicycle Race)
//Programmer: IQBAL HOSSAIN     Description: Implementation/MATH
//Date: 01/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<pair<int, int> > v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, n;

    cin>>n;

    for(int i = 0; i <= n; i++){
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }

    int cnt = 0;
    for(int i = 2; i < v.size(); i++){
        if(v[i].first > v[i-1].first){
            if(v[i-2].second > v[i-1].second)
                cnt++;
        }
        else if(v[i].first < v[i-1].first){
            if(v[i-2].second < v[i-1].second)
                cnt++;
        }
        else if(v[i].second > v[i-1].second){
            if(v[i-2].first < v[i-1].first)
                cnt++;
        }
        else{
            if(v[i-2].first > v[i-1].first)
                cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
