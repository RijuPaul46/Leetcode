class Solution {
public:
    int maxSatisfaction(vector<int>& stf) {
        int n=stf.size();
        sort(stf.begin(),stf.end());
        int ans=0;
        int sum=0;
        int total=0;
        int carry=0;
        for(int i=0;i<n;i++){
            total+=stf[i];
            sum+=stf[i]*(i+1);
        }
        cout<<sum<<" ";
        ans=max(ans,sum);
        for(int i=1;i<n;i++){
            sum=sum-total+carry;
            cout<<sum<<" ";
            ans=max(ans,sum);
            carry+=stf[i-1];
        }
        return ans;
    }
};