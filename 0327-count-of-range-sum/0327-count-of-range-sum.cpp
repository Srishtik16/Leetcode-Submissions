#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<long long, null_type,greater_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        auto countSums = [&](int val) {
            ordered_set oset;
            long long sum = 0, ans = 0;
            for(int i = 0; i < n; i++) {
                sum += nums[i];
                if(sum <= val) {
                    ans++;
                }
                ans += oset.order_of_key(sum - val - 1); // values >= sum - val because it will be subtracted
                oset.insert(sum);
            }
            return ans;
        };
        return countSums(upper) - countSums(lower - 1);
    }
};