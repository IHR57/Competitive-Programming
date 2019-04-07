//Problem ID: CodeForces - 1137A (Skyscrapers)
//Programmer: IQBAL HOSSAIN     Description: Implementation/Sorting
//Date: 07/04/19
#include <bits/stdc++.h>
#define MAX 1005
#define pb push_back
using namespace std;

vector<int> row[MAX], col[MAX];
int arr[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    vector<int> :: iterator it;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
            row[i].pb(arr[i][j]);
            col[j].pb(arr[i][j]);
            if(i == n - 1){
                sort(col[j].begin(), col[j].end());
                it = unique(col[j].begin(), col[j].end());
                col[j].resize(distance(col[j].begin(), it));
            }
        }
        sort(row[i].begin(), row[i].end());
        it = unique(row[i].begin(), row[i].end());
        row[i].resize(distance(row[i].begin(), it));
    }
    int ans;
    for(int i = 0; i <  n; i++){
        for(int j = 0; j < m; j++){
            int temp1 = lower_bound(row[i].begin(), row[i].end(), arr[i][j]) - row[i].begin();
            int temp2 = lower_bound(col[j].begin(), col[j].end(), arr[i][j]) - col[j].begin();
            if(temp1 == temp2){
                ans = max(row[i].size(), col[j].size());
            }
            if(temp1 > temp2){
                ans = max(row[i].size(), temp1 + (col[j].size() - temp2));
            }
            else{
                ans = max(col[j].size(), temp2 + (row[i].size() - temp1));
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }

    return 0;
}
