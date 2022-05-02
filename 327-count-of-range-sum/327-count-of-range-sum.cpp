#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long pref = 0, ans = 0;
        ordered_set oset;
        for(auto x: nums) {
            pref += x;
            if(pref >= lower && pref <= upper) {
                ans++;
            }
            ans += oset.order_of_key(pref - lower + 1) - oset.order_of_key(pref - upper);
            oset.insert(pref);
        }
        return ans;
    }
};