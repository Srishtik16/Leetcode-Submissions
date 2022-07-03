using ll = long long;
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<ll> ans;
        if(finalSum & 1) {
            return ans;
        }
        finalSum /= 2;
        for(ll i = 1;; i++) {
            if(i * (i + 1) / 2 > finalSum) {
                break;
            }
            ans.push_back(i * 2);
        }
        finalSum *= 2;
        ll sum = accumulate(ans.begin(), ans.end(), 0LL);
        ll diff = finalSum - sum;
        ans.back() += diff;
        return ans;
    }
};