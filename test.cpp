#include <bits/stdc++.h>
using namespace std;

int maxWeight;

int solve(int pos, int w, vector<vector<int>>& dp, vector<vector<int>>& arr, vector<pair<int, int>>& v) {
    if(pos >= v.size())     return 0;
    if(dp[pos][w] != -1) {
        return dp[pos][w];
    }

    int ret = 0;
    if((w + arr[v[pos].second][0]) <= maxWeight) {
        ret = arr[v[pos].second][2] + solve(pos + 1, w + arr[v[pos].second][0], dp, arr, v);
    }

    ret = max(ret, solve(pos + 1, w, dp, arr, v));

    return dp[pos][w] = ret;
}

int recur(int pos, int prevIdx, vector<pair<int, int>>& v, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(pos >= arr.size())
        return 0;

    if(dp[pos][prevIdx] != -1) {
        return dp[pos][prevIdx];
    }

    int ret = 0;
    //int lIdx = 0;
    //int rIdx = upper_bound(v.begin(), v.end(), make_pair(pos, 10000)) - v.begin();

    //if(lIdx < v.size()) {
        vector<pair<int, int>> tmp;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first > prevIdx && v[i].first <= pos)
                tmp.push_back(v[i]);
        }
        int n = tmp.size();
        vector<vector<int>> ddp(n, vector<int>(maxWeight + 1, -1));

        ret = solve(0, 0, ddp, arr, tmp) + recur(pos + 1, pos, v, arr, dp);
        cout<<ret<<endl;
    //}
    ret = max(ret, recur(pos + 1, prevIdx, v, arr, dp));
    return dp[pos][prevIdx] = ret;
}

int main() {
    int n, k;

    cin>>n>>k;

    maxWeight = k;

    vector<vector<int>> arr(n, vector<int>(3));
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }

    for(int i = 0; i < n; i++) {
        if((arr[i][1] + i) < n) {
            v.push_back({arr[i][1] + i, i});
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i].first<<" "<<v[i].second<<" W:"<<arr[v[i].second][2]<<" X:"<<arr[v[i].second][0]<<endl;
    }
    cout<<endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<recur(0, 0, v, arr, dp)<<endl;
}
