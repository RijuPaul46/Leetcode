class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target)nums[i]=1;
            else nums[i]=-1;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int sm=0;
            for(int j=i;j<n;j++){
                sm+=nums[j];
                if(sm>0)cnt++;
            }
        }
        return cnt;
    }
};