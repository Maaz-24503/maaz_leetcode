class ProductOfNumbers {
public:
    int sz;
    int latestZero;
    vector<long long> prod;
    ProductOfNumbers() {
        this->prod = {1LL};
        sz = 0;
        this->latestZero = -1;
    }
    
    void add(int num) {
        if(num != 0) prod.push_back(prod[sz] * (1LL * num));
        else {
            prod.push_back(1LL);
            this->latestZero = sz;
        }
        sz++;
    }
    
    int getProduct(int k) {
        if(this->latestZero >= sz-k) return 0;
        return prod[sz]/prod[sz-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */