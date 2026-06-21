class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = *max_element(costs.begin(), costs.end());

        vector<int> freq(mx + 1, 0);

        for(int c : costs)
            freq[c]++;

        int ans = 0;

        for(int cost = 1; cost <= mx && coins > 0; cost++) {
            if(freq[cost] == 0) continue;

            long long total = 1LL * freq[cost] * cost;

            if(total <= coins) {
                ans += freq[cost];
                coins -= total;
            } else {
                ans += coins / cost;
                break;
            }
        }

        return ans;
    }
};