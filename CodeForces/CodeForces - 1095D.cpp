//Problem ID: CodeForces - 1095D (Circular Dance)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 09/04/19
#include <bits/stdc++.h>
#define pb push_back
#define MAX 200005
using namespace std;

typedef pair<int, int> pii;
pii v[MAX];
int visited[MAX];
int res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>v[i].first>>v[i].second;
    }

    visited[1] = visited[v[1].first] = visited[v[1].second] = 1;
    res[0] = 1, res[1] = v[1].first, res[2] = v[1].second;
    int cnt = 3, j = 3;

    int k = 1;
    while(true){
        if(cnt >= n)
            break;
        int tempx = v[res[k]].first, tempy = v[res[k]].second;
        if(res[k+1] != tempx && res[k+1] != tempy){
            swap(res[k], res[k+1]);
            if(!visited[tempx]){
                res[j++] = tempx;
                cnt++;
            }
            if(!visited[tempy]){
                res[j++] = tempy;
                cnt++;
            }
            visited[tempx] = visited[tempy] = 1;
            k += 2;
        }
        else if(res[k+1] == tempx){
            if(!visited[tempy]){
                res[j++] = tempy;
                cnt++;
                visited[tempy] = 1;
            }
            k += 1;
        }
        else if(res[k+1] == tempy){
            if(!visited[tempx]){
                res[j++] = tempx;
                cnt++;
                visited[tempx] = 1;
            }
            k += 1;
        }
    }

    for(int i = 0; i < j; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}
