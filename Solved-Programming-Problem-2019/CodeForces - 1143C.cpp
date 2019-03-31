//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int parent[MAX], c[MAX], cnt[MAX];
vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, v;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>u>>v;
        graph[u].push_back(i);
        parent[i] = u;
        c[i] = v;
        if(v == 0 && u != -1){
            cnt[u]++;
        }
    }

    set<int> s;

    for(int i = 1; i <= n; i++){
        if(c[i] == 1 && cnt[i] == 0)
            s.insert(i);
    }

    if(s.size() == 0){
        cout<<-1<<endl;
        return 0;
    }
    for(set<int> :: iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    cout<<s.size()<<endl;
//    while(!s.empty()){
//        int temp = *s.begin();
//        cout<<temp<<" ";
//        bool flag = true;
//        for(int i = 0; i < graph[temp].size(); i++){
//            if(c[graph[temp][i]] == 0){
//                flag = false;
//                break;
//            }
//        }
//        if(flag)
//        s.erase(temp);
//    }
//    cout<<endl;

    return 0;
}
