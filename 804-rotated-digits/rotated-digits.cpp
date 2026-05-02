class Solution {
public:
    bool isGood(int n) {
        bool hasDiff = false;
        while (n > 0) {
            int digit = n % 10;
            // 1. If it contains any of these, it's invalid
            if (digit == 3 || digit == 4 || digit == 7) return false;
            
            // 2. Check if at least one digit causes the whole number to change
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasDiff = true;
            }
            n /= 10;
        }
        // It's "good" only if it's valid AND different from the original
        return hasDiff;
    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) cnt++;
        }
        return cnt;
    }
};