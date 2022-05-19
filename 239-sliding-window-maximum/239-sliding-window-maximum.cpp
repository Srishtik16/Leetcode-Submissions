class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int x) {
        deque<int> dq;
        vector<int> aux;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(!dq.empty() && dq.front() == i - x) {
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= x - 1) {
                aux.push_back(arr[dq.front()]);
            }
        }
        return aux;
    }
};