//Problem ID: CodeForces - 1082C (Multi-Subject Competition)
//Programmer: IQBAL HOSSAIN     Description: Greedy/Sorting
//Date: 11/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef priority_queue<int,vector<int>,greater<int> > PQ;
vector<int> level[MAX];
PQ pq[MAX];
int sum[MAX], counter[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, s, r;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>r>>s;
        counter[r]++;
        sum[r] += s;
        level[counter[r]].push_back(r);
        pq[r].push(s);
    }

    int Max = 0, maxLevel = *max_element(counter, counter + m + 1);

//    cout<<maxLevel<<endl;
//    for(int i = 0; i < maxLevel; i++){
//        for(int j = 0; j < level[i].size(); i++){
//            cout<<level[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i = maxLevel; i >= 1; i--){
        int temp = 0;
        for(int j = 0; j < level[i].size(); j++){
            int idx = level[i][j];
            if(sum[idx] > 0){
                temp += sum[idx];
            }
            sum[idx] -= pq[idx].top();
            pq[idx].pop();
        }
        Max = max(Max, temp);
    }

    cout<<Max<<endl;

    return 0;
}
