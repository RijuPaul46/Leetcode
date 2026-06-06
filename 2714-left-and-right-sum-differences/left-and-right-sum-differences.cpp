class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        vector<int>ans(n);
        int sum=0;
        for(int i=n-1;i>=0;i--){
            ans[i]=abs(pre[i]-sum);
            sum+=nums[i];
        }
        return ans;
    }
};