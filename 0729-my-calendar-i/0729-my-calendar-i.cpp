class MyCalendar {
public:
    multiset<pair<int, int>> ms;
    MyCalendar() {
        ms.clear();
    }
    
    bool book(int start, int end) {
        for(auto x: ms) {
            if(min(x.second, end - 1) >= max(x.first, start)) {
                return false;
            }
        }
        ms.insert({start, end - 1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */