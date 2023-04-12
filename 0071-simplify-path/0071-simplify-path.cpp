class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string str = "";
        stringstream ss(path);
        while(getline(ss, str, '/')) {
            if(str == "" || str == ".") {
                continue;
            }
            else if(str == ".." && !s.empty()) {
                s.pop();
            }
            else if(str != "..") {
                s.push(str);
            }
        }
        string ans = "";
        while(!s.empty()) {
            string st = s.top();
            reverse(st.begin(), st.end());
            ans += "/" + st;
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        if(!ans.empty()) {
            ans.pop_back();
        }
        ans = "/" + ans;
        return ans;
    }
};