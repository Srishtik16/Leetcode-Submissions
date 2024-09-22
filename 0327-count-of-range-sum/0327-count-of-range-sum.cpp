#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<long long, null_type,greater_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // Count sums <= upper - count sums <= lower - 1
        // find prefix sums
        // if pref >= val we need all sums = pref - x <= val
        // x >= pref - val
        int n = nums.size();
        auto count = [&](int val) {
            ordered_set oset;
            long long pref = 0, ans = 0;
            oset.insert(0);
            for(int i = 0; i < n; i++) {
                pref += nums[i];
                ans += oset.order_of_key(pref - val - 1);
                oset.insert(pref);
            }
            return ans;
        };
        return count(upper) - count(lower - 1);
    }
};