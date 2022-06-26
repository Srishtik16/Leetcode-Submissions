class FreqStack {
public:
    int timestamp;
    map<int, vector<int>> timestamps;
    multiset<vector<int>> pq;
    FreqStack() {
        timestamp = 1e9;
    }
    
    void push(int N) {
        timestamp--;

        if(timestamps[N].empty()) {
            timestamps[N].push_back(timestamp);
            pq.insert({-int(timestamps[N].size()), timestamps[N].back(), N});
        } else {
            int prevTimestamp = timestamps[N].back();
            int freq = timestamps[N].size();

            pq.erase(pq.find({-freq, prevTimestamp, N})); 

            timestamps[N].push_back(timestamp);
            pq.insert({-int(timestamps[N].size()), timestamps[N].back(), N});
        }
    }
    
    int pop() {
        vector<int> elementToErase = *pq.begin();
        pq.erase(pq.begin());
        int element = elementToErase[2];
        timestamps[element].pop_back();
        if(timestamps[element].size())
            pq.insert({-int(timestamps[element].size()), timestamps[element].back(), element});

        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */