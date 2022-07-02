struct Stock {
    map<int, int> timeStamp;
    int maxTimeStamp;
    multiset<int, greater<int>> maxPrice;
    multiset<int> minPrice;
};
class StockPrice {
public:
    Stock stock;
    StockPrice() {
        stock.maxTimeStamp = 0;
    }
    void update(int timestamp, int price) {
        int oldPrice = stock.timeStamp[timestamp];
        stock.timeStamp[timestamp] = price;
        if(stock.maxPrice.find(oldPrice) == stock.maxPrice.end()) {
            stock.maxPrice.insert(price);
        }
        else {
            stock.maxPrice.erase(stock.maxPrice.find(oldPrice));
            stock.maxPrice.insert(price);
        }
        if(stock.minPrice.find(oldPrice) == stock.minPrice.end()) {
            stock.minPrice.insert(price);
        }
        else {
            stock.minPrice.erase(stock.minPrice.find(oldPrice));
            stock.minPrice.insert(price);
        }
        stock.maxTimeStamp = max(timestamp, stock.maxTimeStamp);
    }
    
    int current() {
        return stock.timeStamp[stock.maxTimeStamp];
    }
    
    int maximum() {
        return *stock.maxPrice.begin();
    }
    
    int minimum() {
        return *stock.minPrice.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */