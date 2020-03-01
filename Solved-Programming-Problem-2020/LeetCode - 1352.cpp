class ProductOfNumbers {
public:
    int cm[40005], cs[40005];
    int idx;
    
    ProductOfNumbers() {
        idx = 0;
        cm[0] = 1;
        cs[0] = 0;
    }
    
    void add(int num) {
        ++idx;
        if(num == 0){
            cs[idx] = cs[idx-1] + 1;
            cm[idx] = 1;
            return;
        }
        else
            cs[idx] = cs[idx-1];
        cm[idx] = cm[idx-1] * num;
    }
    
    int getProduct(int k) {
        if(cs[idx] - cs[idx-k] > 0)
            return 0;
        return cm[idx] / cm[idx-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */