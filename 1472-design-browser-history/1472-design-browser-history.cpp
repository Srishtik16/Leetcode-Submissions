class BrowserHistory {
public:
    vector<string> history;
    int index;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        history.resize(index + 1);
        history.push_back(url);
        index++;
    }
    
    string back(int steps) {
        int before = min(index, steps);
        index -= before;
        return history[index];
    }
    
    string forward(int steps) {
        int after = min((int)history.size() - index - 1, steps);
        index += after;
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */