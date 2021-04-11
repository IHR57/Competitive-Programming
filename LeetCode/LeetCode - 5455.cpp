class Solution {
public:
    int st[100005][19];
    
    void buildSpartTable(int N, vector<int>& array){
        for (int i = 0; i < N; i++)
            st[i][0] = array[i];

        for (int j = 1; j <= 18; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }
    
    int log2Base(int x) {
        int cnt = 0;
        while(x) {
            cnt++;
            x /= 2;
        }
        return cnt - 1;
    }
    
    int query(int L, int R) {
        int j = log2Base(R - L + 1);
        int maximum = max(st[L][j], st[R - (1 << j) + 1][j]);
        return maximum;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = 1, high = 1e9, mid, ans = -1;
        
        buildSpartTable(bloomDay.size(), bloomDay);
        
        while(low <= high) {
            mid = (low + high + 1) >> 1;
            int cnt = 0;
            for(int i = 0; i < bloomDay.size(); ) {
                if(i + k <= bloomDay.size() && query(i, i + k - 1) <= mid) {
                    cnt++;
                    i = i + k;
                }
                else{
                    i++;
                }
            }
            if(cnt >= m) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};