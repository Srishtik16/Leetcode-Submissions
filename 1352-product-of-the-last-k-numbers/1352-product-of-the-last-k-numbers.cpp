class fenwick_tree{
private:
    vector<long long> BIT;
public:
    fenwick_tree(int n){
        BIT.resize(n + 1, 0);
    }
    long long query(int i){
        long long res = 0;
        while(i >= 0){
            res += BIT[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    void update(int i, int val){
        while(i < BIT.size()){
            BIT[i] += val;
            i = (i | (i + 1));
        }
    }
};
class ProductOfNumbers {
public:
    vector<fenwick_tree> ft;
    int timeStamp;
    ProductOfNumbers() {
        for(int i = 0; i <= 100; i++) {
            fenwick_tree ft1(40005);
            ft.push_back(ft1);
        }
        timeStamp = 0;
    }
    
    void add(int num) {
        ft[num].update(timeStamp, 1);
        timeStamp++;
    }
    
    int getProduct(int k) {
        int product = 1;
        for(int i = 0; i <= 100; i++) {
            if((ft[i].query(timeStamp - 1) - ft[i].query(timeStamp - k - 1)) == 0) {
                continue;
            }
            if(product == 0) {
                break;
            }
            product *= powl(i, (ft[i].query(timeStamp - 1) - ft[i].query(timeStamp - k - 1)));
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */