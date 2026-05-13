class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> dat(2*limit+2,0);
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            int maxVal=max(a,b)+limit;
            int minVal=min(a,b)+1;
            dat[2]+=2;
            dat[minVal]+=-2;
            dat[minVal]+=1;
            dat[a+b]+=-1;
            dat[a+b+1]+=1;
            dat[maxVal+1]+=-1;
            dat[maxVal+1]+=2;
            dat[2*limit+1]+=-2;
        }
        int mn=INT_MAX;
        int curr=0;
        for(int i=2;i<=2*limit;i++){
            curr+=dat[i];
            mn=min(mn,curr);
        }
        return mn;
    }
};