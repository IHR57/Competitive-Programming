//Problem ID: CodeForces 1041C (Coffee Break)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 16/02/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int visited[MAX];

typedef pair<int, int> pii;
set<pii> s;
int arr[MAX];

bool compare(pii A, pii B)
{
    return A.first < B.first;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, d;

    cin>>n>>m>>d;

    for(int i = 0; i < n ; i++){
        cin>>arr[i];
        s.insert(make_pair(arr[i], i));
    }

    int cnt = 1;
    while(!s.empty()){
        int pos = s.begin()->second;
        visited[pos] = cnt;
        s.erase(s.begin());
        while(true){
            set<pii> :: iterator it;
            it = s.lower_bound({arr[pos] + d + 1, 0});
            if(it == s.end()){
                break;
            }
            pos = it->second;
            s.erase(it);
            visited[pos] = cnt;
        }
        cnt++;
    }

    cout<<cnt-1<<endl;
    for(int i = 0; i < n; i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;


    return 0;
}
