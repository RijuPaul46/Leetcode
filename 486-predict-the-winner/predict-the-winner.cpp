class Solution {
public:
    pair<int,int> game(vector<int>&nums,int a,int b, int i,int j,int turn){
        if(i>j)return {a,b};
        if(turn==1){
            auto [lefta,leftb]=game(nums,a+nums[i],b,i+1,j,2);
            auto [righta,rightb]=game(nums,a+nums[j],b,i,j-1,2);
            if(lefta>righta)return {lefta,leftb};
            else if(lefta==righta){
                if(leftb<rightb)return {righta,rightb};
                else return {lefta,leftb};
            }
            else return {righta,rightb};
        }
        auto [lefta,leftb]=game(nums,a,b+nums[i],i+1,j,1);
        auto [righta,rightb]=game(nums,a,b+nums[j],i,j-1,1);
        if(leftb>rightb)return {lefta,leftb};
            else if(leftb==rightb){
                if(lefta<righta)return {righta,rightb};
                else return {lefta,leftb};
            }
         return {righta,rightb};
    }
    bool predictTheWinner(vector<int>& nums) {
        int i=0;int j=nums.size()-1;
        auto [a,b]=game(nums,0,0,i,j,1);
        if(a>=b)return true;
        return false;
    }
};