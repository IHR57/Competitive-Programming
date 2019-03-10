#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];

    cin>>n;

    for(int i = 0; i < 2 * n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + 2 * n);

    int Min = 1<<28, first, second;
    vector<int> v;

    for(int i = 0; i < 2 * n; i++){
        for(int j = i + 1; j < 2 * n; j++){
            int cnt = 0, sum = 0;
            for(int k = 0; k < 2 * n; k++){
                if(k != i && k != j){
                    v.push_back(arr[k]);
                    cnt++;
                    if(cnt == 2){
                        cnt = 0;
                        sum += (v[1] - v[0]);
                        v.clear();
                    }
                }
            }
            Min = min(Min, sum);
        }
    }

    cout<<Min<<endl;

    return 0;
}
