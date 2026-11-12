class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        int type=-1;
        int streak=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                //it is increasing sec
                if(type!=0){
                    // mean it was not decreasing 
                    streak++;
                    type=1;
                    ans=max(ans,streak);
                }
                else{
                    streak=2;
                    type=1;
                }
            }
            else if(nums[i]<nums[i-1]){
                if(type!=1){
                    type=0;
                    streak++;
                    ans=max(ans,streak);
                }
                else{
                    streak=2;
                    type=0;
                }
            }
            else{
                streak=1;
                type=-1;
            }
        }
        return ans;
    }
};