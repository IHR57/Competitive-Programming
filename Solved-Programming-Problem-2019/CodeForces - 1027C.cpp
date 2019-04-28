//Problem ID: CodeForces - 1027C (Minimum Value Rectangle)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 22/04/19
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int arr[MAX], counter[10005], visited[10005];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        memset(counter, 0, sizeof(counter));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            counter[arr[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(!visited[arr[i]]){
                if(counter[arr[i]] >= 2){
                    v.push_back(arr[i]);
                    visited[arr[i]] = 1;
                }
            }
        }

        sort(v.begin(), v.end());

        double Min = 1e14, temp, res;
        int x1, x2, x3, x4;

        for(int i = 0; i < v.size(); i++){
            if(counter[v[i]] >= 4){
                temp = 2 * ((double)v[i] + (double) v[i]);
                res = (temp * temp) / ((double) v[i] * (double) v[i]);
                //cout<<res<<endl;
                if(res < Min){
                    Min = res;
                    x1 = x2 = x3 = x4 = v[i];
                }
            }
            else{
                if(i + 1 <= v.size() - 1){
                    temp = 2.0 * ((double) v[i] + (double) v[i+1]);
                    res = (temp * temp) / ((double) v[i] * (double) v[i+1]);
                   // cout<<res<<endl;
                    if(res < Min){
                        Min = res;
                        x1 = x2 = v[i];
                        x3 = x4 = v[i+1];
                    }
                }
            }
        }
        cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
        v.clear();
    }

    return 0;
}
