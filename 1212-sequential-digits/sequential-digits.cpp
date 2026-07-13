#define ll long long
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            ll num=i;
            for(int j=i+1;j<=9;j++){
                num=(num)*10+j;
                if(num>=low && num<=high)ans.push_back((int)num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};