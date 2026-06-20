#define ll long long
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rst) {
        rst.push_back({1,0});
        sort(rst.begin(),rst.end());
        if(rst.back()[0]!=n){
            rst.push_back({n,n-1});
        }
        int r=rst.size();
        vector<ll>mx_per(r);
        for(int i=1;i<r;i++){
            mx_per[i]=min(1ll*rst[i][1],mx_per[i-1]+abs(rst[i-1][0]-rst[i][0]));
        }
        for(int i=r-2;i>=0;i--){
            mx_per[i]=min(mx_per[i],mx_per[i+1]+abs(rst[i+1][0]-rst[i][0]));
        }
        ll mx=0;
        for(int i=1;i<r;i++){
            ll a0=rst[i-1][0];
            ll y0=mx_per[i-1];
            ll a1=rst[i][0];
            ll y1=mx_per[i];
            ll peak=((a1-a0)+(y0+y1))/2;
            mx=max(mx,peak);
            
        }
        return (int)mx;
    }
};