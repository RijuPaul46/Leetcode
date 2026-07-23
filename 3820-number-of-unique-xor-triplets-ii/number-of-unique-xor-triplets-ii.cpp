class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st1.insert(nums[i]^nums[j]);
            }
        }
        for(auto &x:nums){
            for(auto &y:st1){
                st2.insert(x^y);
            }
        }
        return st2.size();
    }
};