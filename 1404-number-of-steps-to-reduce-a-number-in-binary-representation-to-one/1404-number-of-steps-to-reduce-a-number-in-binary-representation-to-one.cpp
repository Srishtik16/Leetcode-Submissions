class Solution {
public:
    int numSteps(string s) {
        auto add = [&] (string a) {
            a.insert(a.begin(), '0');
            int n = a.size();
            for(int i = n - 1; i >= 0; i--) {
                if(a[i] == '0') {
                    a[i] = '1';
                    break;
                }
                else {
                    a[i] = '0';
                }
            }
            if(a[0] == '0') {
                a.erase(a.begin());
            }
            return a;
        };
        auto trim = [&] (string a) {
            reverse(a.begin(), a.end());
            while(a.back() == '0') {
                a.pop_back();
            }
            reverse(a.begin(), a.end());
            return a;
        };
        s = trim(s);
        queue<string> q;
        map<string, bool> vis;
        q.push(s);
        vis[s] = true;
        int moves = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto u = q.front();
                q.pop();
                if(u == "1") {
                    return moves;
                }
                if(u.back() == '1') {
                    string st = add(u);
                    st = trim(st);
                    if(!vis[st]) {
                        vis[st] = true;
                        q.push(st);
                    }
                }
                else {
                    string st = u;
                    st.pop_back();
                    st = trim(st);
                    if(!vis[st]) {
                        vis[st] = true;
                        q.push(st);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};