class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> prev(n), next(n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            if(s.empty()) {
                prev[i] = -1;
            }
            else {
                prev[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            if(s.empty()) {
                next[i] = n;
            }
            else {
                next[i] = s.top();
            }
            s.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (abs(prev[i] - next[i]) - 1) * a[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mat[i][j] = matrix[i][j] == '0' ? 0 : 1;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                mat[j][i] += mat[j - 1][i];
                if(matrix[j][i] == '0') {
                    mat[j][i] = 0;
                }
            }
        }
        int ans = 0;
        for(auto x: mat) {
            ans = max(ans, largestRectangleArea(x));
        }
        return ans;
    }
};