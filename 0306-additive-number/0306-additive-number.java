class Solution {
    public boolean recurse(String num, int currentIndex, long firstNum, long secondNum, int count) {
        if (currentIndex == num.length()) {
            return count > 2;
        }

        long currentNum = 0;
        for (int i = currentIndex; i < num.length(); i++) {
            if (currentNum > Math.pow(10, 17)) {
                break;
            }
            currentNum = currentNum * 10 + (num.charAt(i) - '0');

            boolean isValidAdditiveNumber = false;
            if (count < 2) {
                isValidAdditiveNumber = recurse(num, i + 1, secondNum, currentNum, count + 1);
            } else if (firstNum + secondNum == currentNum) {
                isValidAdditiveNumber = recurse(num, i + 1, secondNum, currentNum, count + 1);
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
    public boolean isAdditiveNumber(String num) {
        return recurse(num, 0, 0, 0, 0);
    }
}