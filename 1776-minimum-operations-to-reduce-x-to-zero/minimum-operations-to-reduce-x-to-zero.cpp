class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int>pre;
        int n=nums.size();
        pre[0]=-1;
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            pre[sm]=i;
        }
        sm=0;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int rem=x-sm;
            if(pre.count(rem)){
                int idx=pre[rem];
                if(idx<=i){
                    ans=min(ans,idx+n-i);
                }
            }
            sm+=nums[i];
        }
        return ans==INT_MAX?-1:ans;
    }
};