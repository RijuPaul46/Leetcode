class Solution {
public:
    int minsum(vector<int>&nums,int sz){
        int ans=INT_MAX,sm=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sm+=nums[i];
            if(i>=sz){
                sm-=(nums[i-sz]);
            }
            if(i>=(sz-1) && sm>0)ans=min(ans,sm);
        }
        return ans;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        // t.c = n*(r-l) ... n2
        //
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            ans=min(ans,minsum(nums,i));
        }
        return ans==INT_MAX?-1:ans;

    }
};