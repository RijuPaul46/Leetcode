class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto & num:nums){
            vector<int> digit;
            while(num>0){
                int d=num%10;
                digit.push_back(d);
                num/=10;
            }
            reverse(digit.begin(),digit.end());
            for(auto &x: digit)ans.push_back(x);
        }
        return ans;
    }
};