class ProductOfNumbers {
    vector<int> nums;
public:


    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
        
    }
    
    int getProduct(int k) {
        int n=nums.size();
       int p=1;
        for(int i=n-1;i>n-1-k;i--){
               p=p*nums[i]; 
        }
        return p;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */