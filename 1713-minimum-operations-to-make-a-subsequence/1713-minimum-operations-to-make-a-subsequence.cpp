template <typename T>
int lis(const vector<T> &a) {
  vector<T> u;
  for (const T &x : a) {
    auto it = lower_bound(u.begin(), u.end(), x);
    if (it == u.end()) {
      u.push_back(x);
    } else {
      *it = x;
    }
  }
  return (int) u.size();
}
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[target[i]] = i;
        }
        vector<int> a;
        for(auto x: arr) {
            if(m.find(x) == m.end()) {
                continue;
            }
            a.push_back(m[x]);
        }
        return n - lis(a);
    }
};