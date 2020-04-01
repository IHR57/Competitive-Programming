#define MOD 1000000007
#define pb push_back
typedef long long ll;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int> > vp;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i = 0;  i < speed.size(); i++){
            vp.pb(make_pair(speed[i], efficiency[i]));
        }
        
        sort(vp.begin(), vp.end(), compare);
        
        ll Max = 0, sum = 0;
        for(int i = 0; i < k; i++){
            sum += vp[i].first;
            Max = max(Max, sum * vp[i].second);
            pq.push(vp[i].first);
        }
        
        for(int i = k; i < n; i++){
            if(vp[i].first > pq.top()){
                sum -= pq.top();
                sum += vp[i].first;
                pq.pop();
                pq.push(vp[i].first);
                Max = max(Max, sum * vp[i].second);
            }
        }
        
        return Max % MOD;
        
    }
};