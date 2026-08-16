#define ll long long
class Solution {
public:
    // idea is that ... fix two elements and solve two sum problem 
    // how to handle duplicate: for i,j do not process same nums[i]
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                ll tgt=1ll*target-nums[i]-nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                   ll sm=1ll*nums[l]+nums[r];
                   if(sm==tgt){
                    ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(l<r && nums[r]==nums[r+1])r--;
                   } 
                   else if(sm<tgt)l++;
                   else r--;
                }
            }
        }
        return ans;
        
    }
};