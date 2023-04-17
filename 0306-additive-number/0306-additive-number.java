class Solution {
    public boolean getFibo(String s, int i, long a, long b, int n) {
        if (i == s.length())
            return n > 2;

        long num = 0;
        for (int x = i; x < s.length(); x++) {
            if (num > Math.pow(10, 17)) break;
            num = num * 10 + (s.charAt(x) - '0');
            boolean chk = false;
            if (n < 2)
                chk = getFibo(s, x + 1, b, num, n + 1);
            else if (a + b == num)
                chk = getFibo(s, x + 1, b, num, n + 1);
            if (chk)
                return true;
            if (num == 0)
                break;
        }
        return false;
    }
    public boolean isAdditiveNumber(String num) {
        return getFibo(num, 0, 0, 0, 0);
    }
}