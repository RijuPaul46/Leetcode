class Solution {
public:
    // we can eliminate portion where elm are present in pair and starting point is odd ... mean left has that elm and the right part is useless ..
    //if pair starting point is even ...mean left has no such elm .. discard that portion
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int x=nums[mid];
            int sp=-1;
            if(mid-1>=0 && nums[mid-1]==nums[mid]){
                sp=mid-1;
            }
            if(mid+1<n && nums[mid+1]==nums[mid]){
                sp=mid;
            }
            if(sp==-1)return x;
            if(sp%2==0){
                l=mid+1;
            }
            else h=mid-1;
        }
        return -1;
    }
};