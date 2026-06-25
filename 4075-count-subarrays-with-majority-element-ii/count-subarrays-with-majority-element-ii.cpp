#define ll long long
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,ll> mp;
        int n=nums.size();
        ll sm=0;
        mp[sm]++;
        ll ans=0;
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                cnt=cnt+mp[sm];
                sm+=1;
                ans+=cnt;
            }
            else {
                sm-=1;
                cnt=max(0ll,cnt-mp[sm]);
                ans+=cnt;
            }
            mp[sm]++;
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();