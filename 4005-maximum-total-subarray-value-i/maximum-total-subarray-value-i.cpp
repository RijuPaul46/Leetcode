#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mn=1ll*(*min_element(nums.begin(),nums.end()));
        ll mx=1ll*(*max_element(nums.begin(),nums.end()));
        return k*(mx-mn);

    }
};