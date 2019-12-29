//Problem ID: CodeForces - 1029C (Maximal Intersection)
//Programmer: IQBAL HOSSAIN     Description: Greedy/MATH
//Date: 15/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<pair<int, int> > vp;
multiset<int> ms1, ms2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l, r;

    cin>>n;

    int idx = 1;
    for(int i = 0; i < n; i++){
        cin>>l>>r;
        vp.push_back(make_pair(l, r));
        ms1.insert(l);
        ms2.insert(r);
    }

    int counter1 = ms1.count(*ms1.rbegin());
    int counter2 = ms2.count(*ms2.begin());

    //cout<<counter1<<" "<<counter2<<endl;
    int tmp1 = *ms1.rbegin(), tmp2 = *ms2.begin();

    int Max = 0;
    for(int i = 0; i < vp.size(); i++){
        ms1.erase(vp[i].first);
        ms2.erase(vp[i].second);
        int t1, t2;
        if(!ms1.empty())
            t1 = *ms1.rbegin();
        else{
            t1 = tmp1;
        }
        if(!ms2.empty())
            t2 = *ms2.begin();
        else{
            t2 = tmp2;
        }
        if(vp[i].first == tmp1 && counter1 > 1){
            t1 = tmp1;
        }
        if(vp[i].second == tmp2 && counter2 > 1){
            t2 = tmp2;
        }
        if(t2 >= t1){
            Max = max(Max, t2 - t1);
        }
        ms1.insert(vp[i].first);
        ms2.insert(vp[i].second);
    }

    cout<<Max<<endl;

    return 0;
}
