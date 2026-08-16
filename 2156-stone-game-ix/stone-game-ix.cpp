class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);
        for (int x : stones) cnt[x % 3]++;

        // If the number of 0-remainder stones is even:
        // Alice wins if both 1s and 2s are present (> 0).
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }
        
        // If the number of 0-remainder stones is odd:
        // Alice wins if the absolute difference between count(1) and count(2) is > 2.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};