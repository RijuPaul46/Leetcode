class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int mx=nums[0];
        int mx1=nums[1];
        if(nums[1]>nums[0]){
            mx=nums[1];
            mx1=nums[0];
        }
        int n=nums.size();
        for(int i=2;i<n;i++){
            int x=nums[i];
            if(x>=mx){
                mx1=mx;
                mx=x;
            }
            else if(x<mx && x>=mx1){
                mx1=x;
            }

        }
        return (mx-1)*(mx1-1);
    }
};