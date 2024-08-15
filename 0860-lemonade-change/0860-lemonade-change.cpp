class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        map<int, int> change;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            int toPay = bills[i] - 5;
            int twenty = toPay / 20;
            if(twenty > change[20]) {
                twenty = change[20];
                change[20] = 0;
            }
            else {
                change[20] -= twenty;
            }
            toPay -= 20 * twenty;
            int ten = toPay / 10;
            if(ten > change[10]) {
                ten = change[10];
                change[10] = 0;
            }
            else {
                change[10] -= ten;
            }
            toPay -= 10 * ten;
            int five = toPay / 5;
            if(five > change[5]) {
                five = change[5];
                change[5] = 0;
            }
            else {
                change[5] -= five;
            }
            toPay -= 5 * five;
            ok &= toPay == 0;
            change[bills[i]]++;
        }
        return ok;
    }
};