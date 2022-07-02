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
        sort(timePoints.begin(), timePoints.end());
        for(auto x: timePoints) {
            cout << x << " ";
        }
        cout << endl;
        vector<int> time1, time2;
        for(auto x: timePoints) {
            time1.push_back(convert(x));
        }
        for(auto x: time1) {
            cout << x << " ";
        }
        cout << endl;
        for(auto x: time2) {
            cout << x << " ";
        }
        cout << endl;
        // sort(time1.begin(), time1.end());
        // sort(time2.begin(), time2.end());
        int ans = INT_MAX;
        for(int i = 1; i < time1.size(); i++) {
            // cout << time1[i] << " " << time2[i] << endl;
            ans = min(ans, clockWise(time1[i], time1[i - 1]));
            ans = min(ans, antiClockWise(time1[i], time1[i - 1]));
            // ans = min(ans, abs(time2[i] - time2[i - 1]));
        }
        ans = min(ans, clockWise(time1[0], time1.back()));
        ans = min(ans, antiClockWise(time1[0], time1.back()));
        cout << antiClockWise(time1[0], time1.back()) << endl;
        return ans;
    }
};