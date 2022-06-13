class Solution {
public:
    multiset<int> msSmall;
    multiset<int, greater<int>> msLarge;
    void insert(int x) {
        if(msLarge.empty() || *msLarge.begin() > x) {
            msLarge.insert(x);
        }
        else {
            msSmall.insert(x);
        }
        if(msLarge.size() > msSmall.size() + 1) {
            msSmall.insert(*msLarge.begin());
            msLarge.erase(msLarge.begin());
        }
        else if(msLarge.size() + 1 < msSmall.size()) {
            msLarge.insert(*msSmall.begin());
            msSmall.erase(msSmall.begin());
        }
    }
    void del(int x) {
        if(msSmall.find(x) != msSmall.end()) {
            msSmall.erase(msSmall.find(x));
        }
        else {
            msLarge.erase(msLarge.find(x));
        }
    }
    void adjust() {
        while(msLarge.size() > msSmall.size() + 1) {
            msSmall.insert(*msLarge.begin());
            msLarge.erase(msLarge.begin());
        }
        while(msLarge.size() + 1 < msSmall.size()) {
            msLarge.insert(*msSmall.begin());
            msSmall.erase(msSmall.begin());
        }
    }
    double getMedian() {
        int s = msLarge.size() + msSmall.size();
        if(s & 1) {
            if(msLarge.size() > msSmall.size()) {
                return *msLarge.begin();
            }
            else {
                return *msSmall.begin();
            }
        }
        else {
            double ans = *msLarge.begin() + 0.0 + *msSmall.begin();
            ans /= 2.0;
            return ans;
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        msLarge.clear();
        msSmall.clear();
        for(int i = 0; i < k; i++) {
            insert(nums[i]);
        }
        vector<double> ans;
        ans.push_back(getMedian());
        int n = nums.size();
        for(int i = k; i < n; i++) {
            del(nums[i - k]);
            adjust();
            insert(nums[i]);
            ans.push_back(getMedian());
        }
        return ans;
    }
};