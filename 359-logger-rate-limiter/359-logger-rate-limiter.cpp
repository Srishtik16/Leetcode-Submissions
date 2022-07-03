class Logger {
public:
    map<string, int> lastStamp;
    Logger() {
        ;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(lastStamp.find(message) == lastStamp.end()) {
            lastStamp[message] = timestamp;
            return true;
        }
        if(lastStamp[message] + 10 > timestamp) {
            return false;
        }
        else {
            lastStamp[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */