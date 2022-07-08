class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int product;
    ProductOfNumbers() {
        prefixProduct.push_back(1);
        product = 1;
    }
    
    void add(int num) {
        if(num == 0) {
            prefixProduct.clear();
            product = 1;
            prefixProduct.push_back(product);
            return;
        }
        product *= num;
        prefixProduct.push_back(product);
    }
    
    int getProduct(int k) {
        if(prefixProduct.size() <= k) {
            return 0;
        }
        return prefixProduct.back() / prefixProduct[prefixProduct.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */