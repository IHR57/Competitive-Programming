class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(0), fib.push_back(1), fib.push_back(1);
        for(int i = 3; ; i++){
            int temp = fib[i-1] + fib[i-2];
            if(temp >= 1e9)
                break;
            fib.push_back(temp);
        }
        
        sort(fib.begin(), fib.end());
        
        int cnt = 0;
        while(k){
            int idx = lower_bound(fib.begin(), fib.end(), k) - fib.begin();
            if(fib[idx] != k)
                idx--;
            //cout<<fib[idx]<<endl;
            k -= fib[idx];
            cnt++;
        }
        
        return cnt;
    }
};