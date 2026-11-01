class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int move=0;
        for(auto &x:nums){
            move+=(x-mn);
        }
        return move;
    }
};