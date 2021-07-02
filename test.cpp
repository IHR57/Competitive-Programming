#include<iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, set<int> > mp;
set<int> s;
unordered_map<int, int> counter;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> cnt;

void init()
{
    mp.clear();
    cnt.clear();
    s.clear();
    counter.clear();
}
void Add(int P, int N)
{
    mp[N].insert(P);
    pair<int, int> p(N, P);
    cnt[p]++;
    s.insert(N);
    counter[N]++;
}

int Use(int P1, int P2)
{
    int ans = -1, idx;

    for(set<int> :: reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
        set<int> :: iterator temp = mp[*it].lower_bound(P1);
        if(temp != mp[*it].end()) {
            if(*temp <= P2) {
                ans = *it;
                idx = *temp;
                break;
            }
        }
    }

    if(ans != -1) {
        if(--cnt[make_pair(ans, idx)] == 0) {
            mp[ans].erase(idx);
        }
        if(mp[ans].size() == 0) {
            if(--counter[ans] == 0) {
                s.erase(ans);
            }
        }
    }

    return ans;
}

int main()
{
    init();
    int tt;
    cin>>tt;
    while(tt--)
    {
        int N,which_function_need_to_call,P1,P2;
        cin>>which_function_need_to_call;
        if(which_function_need_to_call==1)
        {
            cin>>P1>>N;
            Add(P1,N);
        }
        else if(which_function_need_to_call==2)
        {
            cin>>P1>>P2;
            cout<<Use(P1,P2)<<endl;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}

