#define ll long long
class Solution {
public:
    const ll inf=1e9+7;
    int findMaxVal(int n, vector<vector<int>>& rst, vector<int>& diff) {
        sort(rst.begin(),rst.end());
        vector<ll>ht(n,inf);
        int j=0;
        if(rst[0][0]==0)j++;
        int r=rst.size();
        ht[0]=0;
        for(int i=1;i<n;i++){
            if(j<r&&i==rst[j][0]){
                ht[i]=min(1ll*rst[j++][1],ht[i-1]+diff[i-1]);
            }
            else ht[i]=min(ht[i],ht[i-1]+diff[i-1]);
        }
        ll mx=ht[n-1];
        for(int i=n-2;i>=0;i--){
            ht[i]=min(ht[i+1]+diff[i],ht[i]);
            mx=max(mx,ht[i]);
        }
        return (int)mx;


    }
};