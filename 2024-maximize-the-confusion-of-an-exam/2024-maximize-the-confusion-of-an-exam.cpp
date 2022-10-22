class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        vector<int> prefT(n, 0), prefF(n, 0);
        prefT[0] = answerKey[0] == 'T';
        prefF[0] = 1 - prefT[0];
        for(int i = 1; i < n; i++) {
            prefT[i] = prefT[i - 1] + (answerKey[i] == 'T');
            prefF[i] = i + 1 - prefT[i];
        }
        auto range = [&](int l, int r, bool which) {
            if(l < 0 || r >= n || l > r) {
                return -1;
            }
            if(which) {
                return prefT[r] - (l > 0 ? prefT[l - 1] : 0);
            }
            else {
                return prefF[r] - (l > 0 ? prefF[l - 1] : 0);
            }
        };
        int l = 1, r = n, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            bool ok = false;
            for(int i = 0; i < n; i++) {
                if(range(i, i + mid - 1, true) != -1) {
                    int tc = range(i, i + mid - 1, true);
                    int fc = range(i, i + mid - 1, false);
                    if(tc <= k || fc <= k) {
                        ok = true;
                        break;
                    }
                }
            }
            if(ok) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};