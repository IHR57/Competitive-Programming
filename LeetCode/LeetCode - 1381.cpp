class CustomStack {
public:
    int arr[1005], idx, Size;
    CustomStack(int maxSize) {
        idx = -1;
        Size = maxSize;
    }
    
    void push(int x) {
        if(idx + 1 < Size){
            arr[++idx] = x;
        }
    }
    
    int pop() {
        if(idx < 0)
            return -1;
        return arr[idx--];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, idx + 1); i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */