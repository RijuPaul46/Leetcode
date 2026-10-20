
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int mn = nums[start];
                int mx = nums[start];
                int descents = 0;

                for (int i = start; i <= end; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);

                    int next = (i == end) ? start : i + 1;
                    if (nums[i] > nums[next]) {
                        descents++;
                    }
                }

                if (descents > 1 || prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
