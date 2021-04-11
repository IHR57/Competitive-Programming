class Solution {
public:
    int num[15] = {0};
    string ans = "";
    int cnt = 0;
    
    string solve(int pos, int prev, int n, int k)
    {
        if(pos >= n){
            cnt++;
            //cout<<"Here"<<endl;
            if(cnt == k){
                for(int i = 0; i < n; i++){
                    if(num[i] == 0)
                        ans += "a";
                    else if(num[i] == 1)
                        ans += "b";
                    else
                        ans += "c";
                }
                return ans;
                exit(0);
            }
            return "";
        }
        for(int i = 0; i < 3; i++){
            if(i != prev){
                num[pos] = i;
                solve(pos + 1, i, n, k);
            }
        }
        return ans;
    }
    
    string getHappyString(int n, int k) {
        string res = solve(0, -1, n, k);
        
        return res;
    }
};