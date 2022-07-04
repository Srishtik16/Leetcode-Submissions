class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> digits;
        for(char c: time) {
            if(c == ':') {
                continue;
            }
            digits.push_back(c);
        }
        auto isValid = [&] (string t) {
            string hr = t.substr(0, 2);
            string min = t.substr(3);
            int hour = stoll(hr);
            int mins = stoll(min);
            if(hour < 0 || hour > 23) {
                return false;
            } 
            if(mins < 0 || mins > 59) {
                return false;
            }
            return true;
        };
        auto convert = [&](string t) {
            string hr = t.substr(0, 2);
            string min = t.substr(3);
            int hour = stoll(hr);
            int mins = stoll(min);
            int val = hour * 60 + mins;
            return val;
        };
        auto clockWise = [&](int x, int y) {
            return abs(x - y);
        };
        auto antiClockWise = [&](int x, int y) {
            return min(x, y) + 1440 - (max(x, y));
        };
        string ans = "";
        int diff = INT_MAX;
        for(char c1: digits) {
            for(char c2: digits) {
                for(char c3: digits) {
                    for(char c4: digits) {
                        string s = "";
                        s += c1;
                        s += c2;
                        s += ':';
                        s += c3;
                        s += c4;
                        if(!isValid(s) || s == time) {
                            continue;
                        }
                        int nextTime = 0;
                        if(s > time) {
                            nextTime = clockWise(convert(time), convert(s));
                        }
                        else {
                            nextTime = antiClockWise(convert(time), convert(s));
                        }
                        if(diff > nextTime) {
                            diff = nextTime;
                            ans = s;
                        }
                    }
                }
            }
        }
        if(ans.empty()) {
            ans = time;
        }
        return ans;
    }
};