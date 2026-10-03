class Solution {
public:
    //observation ... for each elm either left half or right half is sorted 
    // for sure 
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target)return mid;
            if(nums[l]<=nums[mid]){
                // left half sorted
                if(target<nums[mid] && target>=nums[l])h=mid-1;
                else l=mid+1;
            }
            else{
                // right half sorted fs
                if(target>nums[mid] && target<=nums[h]){
                    l=mid+1;
                }
                else h=mid-1;
            }
        }
        return -1;
    }
};