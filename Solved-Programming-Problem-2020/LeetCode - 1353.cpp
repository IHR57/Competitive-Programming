class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int> > pq;
        sort(events.begin(), events.end());
        
        int n = events.size();
        
        int idx = 0, cnt = 0;;
        for(int i = 1; i <= 100000; i++){
            while(!pq.empty() && pq.top() < i)
                pq.pop();
            while(idx < n && events[idx][0] == i){
                pq.push(events[idx][1]);
                idx++;
            }
            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }
        
        return cnt;
    }
};