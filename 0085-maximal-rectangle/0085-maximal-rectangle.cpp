class Solution {
public:
    int largestRectangle(vector<int> a) {
        int n = a.size();
        stack<int> st1, st2;
        vector<int> prev(n, -1), next(n, n);
        for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
            while(!st1.empty() && a[i] <= a[st1.top()]) {
                st1.pop();
            }
            while(!st2.empty() && a[j] <= a[st2.top()]) {
                st2.pop();
            }
            prev[i] = st1.empty() ? -1 : st1.top();
            next[j] = st2.empty() ? n : st2.top();
            st1.push(i);
            st2.push(j);
        }
        int area = 0;
        for(int i = 0; i < n; i++) {
            int height = a[i];
            int left = prev[i];
            int right = next[i];
            area = max(area, height * (right - left - 1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0') {
                    mat[i][j] = 0;
                }
                else {
                    mat[i][j] = i > 0 ? mat[i - 1][j] + 1 : 1;
                }
            }
        }
        int ans = 0;
        for(auto x: mat) {
            ans = max(ans, largestRectangle(x));
        }
        return ans;
    }
};