class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
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
        vector<int> time1, time2;
        for(auto x: timePoints) {
            time1.push_back(convert(x));
        }
        sort(time1.begin(), time1.end());
        int ans = INT_MAX;
        for(int i = 1; i < time1.size(); i++) {
            ans = min(ans, clockWise(time1[i], time1[i - 1]));
            ans = min(ans, antiClockWise(time1[i], time1[i - 1]));
        }
        ans = min(ans, clockWise(time1[0], time1.back()));
        ans = min(ans, antiClockWise(time1[0], time1.back()));
        return ans;
    }
};