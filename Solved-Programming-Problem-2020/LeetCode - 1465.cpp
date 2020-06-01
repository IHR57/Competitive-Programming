typedef long long ll;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h), verticalCuts.push_back(w);
        int maxH = 0, maxV = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        maxH = horizontalCuts[0], maxV = verticalCuts[0];
        for(int i = 1; i < horizontalCuts.size(); i++) {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        for(int i = 1; i < verticalCuts.size(); i++) {
            maxV = max(maxV, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        ll res = (1LL * maxH * maxV) % 1000000007;
        int ans = res;
        return ans;
    }
};