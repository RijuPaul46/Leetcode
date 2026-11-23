class ProductOfNumbers {
public:
    vector<int>pre;
    int last;
    ProductOfNumbers() {
        last=-1;
    }
    
    void add(int num) {
        int n=pre.size();
        if(num==0){
            pre.clear();
        }
        else{
        if(n==0){
            pre.push_back(num);
        }
        else{
            pre.push_back(pre.back()*num);
        }
        }
    }
    
    int getProduct(int k) {
        int n=pre.size();
        if(k>n)return 0;
        int rem=n-k-1;
        if(rem>=0)
        return pre.back()/pre[rem];
        return pre.back();
         
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */