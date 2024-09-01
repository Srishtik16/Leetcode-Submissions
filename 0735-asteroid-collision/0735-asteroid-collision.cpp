class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // lets focus on ith asteroid moving to right
        // ith will destroy all to right if smaller and not already destroyed
        vector<int> sign;
        vector<int> pos, neg;
        for(auto x: asteroids) {
            if(x > 0) {
                pos.push_back(x);
                sign.push_back(1);
            }
            else {
                neg.push_back(x);
                sign.push_back(-1);
            }
        }
        stack<int> st;
        int n = asteroids.size();
        for(int i = n - 1; i >= 0; i--) {
            bool exploded = false;
            while(!st.empty() && sign[i] > 0 && sign[st.top()] < 0) {
                if(abs(asteroids[i]) > abs(asteroids[st.top()])) {
                    st.pop();
                }
                else if(abs(asteroids[i]) == abs(asteroids[st.top()])) {
                    st.pop();
                    exploded = true;
                    break;
                }
                else {
                    exploded = true;
                    break;
                }
            }
            if(!exploded) {
                st.push(i);
            }
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(asteroids[st.top()]);
            st.pop();
        }
        return res;
    }
};