class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        for(char c: s) {
            m[c]++;
        }
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        for(auto x: m) {
            if(x.second > (n + 1) / 2) {
                return string(0, '(');
            }
            pq.push({x.second, x.first});
        }
        string ans = "";
        while(pq.size() > 1) {
            auto f = pq.top();
            pq.pop();
            auto s = pq.top();
            pq.pop();
            ans += f.second;
            ans += s.second;
            if(f.first > 1) {
                m[f.second]--;
                pq.push({m[f.second], f.second});
            }
            if(s.first > 1) {
                m[s.second]--;
                pq.push({m[s.second], s.second});
            }
        }
        if(pq.size() > 0) {
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};