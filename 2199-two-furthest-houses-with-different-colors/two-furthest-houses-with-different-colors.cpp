class Solution {
public:
    int maxDistance(vector<int>& colors) {
       int first=colors[0];
       int n=colors.size();
       int ans=0;
       for(int i=n-1;i>=0;i--){
        if(colors[i]!=first){
           ans=i;
           break;
        }
       }
       int last=colors[n-1];
       for(int i=0;i<n;i++){
        if(colors[i]!=last){
            ans=max(ans,n-i-1);
            break;
        }
       }
       return ans;
    }
};