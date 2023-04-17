class Solution {
public:
    bool checkAdditiveNumber(string& num, int currentIndex, long long firstNum, long long secondNum, int count) {
        if (currentIndex == num.length()) {
            return count > 2;
        }

        long long currentNum = 0;
        for (int i = currentIndex; i < num.length(); i++) {
            if (currentNum > pow(10, 17)) {
                break;
            }
            currentNum = currentNum * 10 + (num[i] - '0');

            bool isValidAdditiveNumber = false;
            if (count < 2) {
                isValidAdditiveNumber = checkAdditiveNumber(num, i + 1, secondNum, currentNum, count + 1);
            } else if (firstNum + secondNum == currentNum) {
                isValidAdditiveNumber = checkAdditiveNumber(num, i + 1, secondNum, currentNum, count + 1);
            }

            if (isValidAdditiveNumber) {
                return true;
            }

            if (currentNum == 0) {
                break;
            }
        }

        return false;
    }
    bool isAdditiveNumber(string num) {
        return checkAdditiveNumber(num, 0, 0, 0, 0);
    }
};