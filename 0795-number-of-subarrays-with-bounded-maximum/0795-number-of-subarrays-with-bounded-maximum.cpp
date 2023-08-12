template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        SparseTable<int> st(nums, [&](const int &x, const int &y) {
            return max(x, y);
        });
        vector<int> dp(n, 0), dp1(n, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = nums[i] < left;
            dp1[i] = nums[i] <= right;
        }
        for(int i = 1; i < n; i++) {
            int l = 0, r = i, ans = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(st.get(mid, i) < left) {
                    ans = i - mid + 1;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            l = 0, r = i;
            int ans1 = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(st.get(mid, i) <= right) {
                    ans1 = i - mid + 1;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            dp[i] = ans;
            dp1[i] = ans1;
        }
        return accumulate(dp1.begin(), dp1.end(), 0LL) - accumulate(dp.begin(), dp.end(), 0LL);
    }
};