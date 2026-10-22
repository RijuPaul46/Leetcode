class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool sorted=true;
        bool reversed=true;
        int idx=-1;
        if(nums[0]==0)idx=0;
        for(int i=1;i<n;i++){
            int x=nums[i];
            int y=nums[i-1];
            if(x==0)idx=i;
            if(((y+1)%n) !=x){
                sorted=false;
            }
            if(((y-1+n)%n)!=x){
                reversed=false;
            }
        }
        if(!sorted && !reversed)return -1;
        if(sorted){
            return min(idx,n-idx+2);
        }
        return min(idx+2,n-idx);

    }
};