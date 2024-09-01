class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        stack<int> st1, st2, st3, st4;
        vector<int> nge(n), pge(n), nse(n), pse(n);
        for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
            // prev
            while(!st1.empty() && arr[i] < arr[st1.top()]) {
                st1.pop();
            }
            // next
            while(!st2.empty() && arr[j] <= arr[st2.top()]) {
                st2.pop();
            }
            // prev
            while(!st3.empty() && arr[i] >= arr[st3.top()]) {
                st3.pop();
            }
            // next
            while(!st4.empty() && arr[j] > arr[st4.top()]) {
                st4.pop();
            }
            pge[i] = st1.empty() ? -1 : st1.top();
            nge[j] = st2.empty() ? n : st2.top();
            pse[i] = st3.empty() ? -1 : st3.top();
            nse[j] = st4.empty() ? n : st4.top();
            st1.push(i);
            st2.push(j);
            st3.push(i);
            st4.push(j);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int l = abs(i - pge[i]);
            int r = abs(i - nge[i]);
            ans -= l * 1LL * r * arr[i];
            l = abs(i - pse[i]);
            r = abs(i - nse[i]);
            ans += l * 1LL * r * arr[i];
        }
        return ans;
    }
};