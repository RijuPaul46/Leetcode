class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int x=log2(n)+1;
        return 1<<x;
    }
};