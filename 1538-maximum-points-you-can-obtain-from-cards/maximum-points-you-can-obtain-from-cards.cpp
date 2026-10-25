class Solution {
public:
    // dp will take O(n**2)
    // can be done using prefix sum
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>suff(n,0);
        suff[n-1]=cardPoints[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+cardPoints[i];
        }
        int sm=0;
        int curr=0;
        for(int i=0;i<=k && i<n;i++){
            int rem=k-i;
            int li=n-rem;
            int b=0;
            if(li<n)b+=suff[li];
            sm=max(sm,curr+b);
            curr+=cardPoints[i];
        }
        return sm;
    }
};