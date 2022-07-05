class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<string> islands;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string s = "";
                while(j < m && board[i][j] != '#') {
                    s += board[i][j];
                    j++;
                }
                islands.push_back(s);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = m - 1; j >= 0; j--) {
                string s = "";
                while(j >= 0 && board[i][j] != '#') {
                    s += board[i][j];
                    j--;
                }
                islands.push_back(s);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                string s = "";
                while(j < n && board[j][i] != '#') {
                    s += board[j][i];
                    j++;
                }
                islands.push_back(s);
            }
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                string s = "";
                while(j >= 0 && board[j][i] != '#') {
                    s += board[j][i];
                    j--;
                }
                islands.push_back(s);
            }
        }
        for(auto s: islands) {
            bool ok = false;
            if(s.size() != word.size()) {
                continue;
            }
            for(int i = 0; i < word.size(); i++) {
                if(s[i] == ' ') {
                    ok = true;
                    continue;
                }
                if(s[i] == word[i]) {
                    ok = true;
                    continue;
                }
                ok = false;
                break;
            }
            if(ok) {
                return true;
            }
        }
        return false;
    }
};