class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
        int even=0,odd=0;
        for(auto &x:nums1){
            if(x%2==0)even++;
            else odd++;
        }
        int n=nums1.size();
    }
};