#define db double
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int cnt=0;
            db ratio=(db)a/(db)b;
        for(int i=0;i<n;i++){
            int x=0,y=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)x++;
                else y++;
                if(y>0){
                    db r=(db)x/(db)y;
                    if(r<=ratio)cnt++;
                }
            }
        }
        return cnt;
    }
};