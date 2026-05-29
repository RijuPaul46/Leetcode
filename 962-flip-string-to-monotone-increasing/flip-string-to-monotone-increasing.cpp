class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int>one(n+1,0);
        vector<int> zero(n+1,0);
        for(int i=0;i<n;i++){
            one[i+1]=one[i]+(s[i]=='1');
        }
        for(int i=n-1;i>=0;i--){
            zero[i]=zero[i+1]+(s[i]=='0');
        }
        int mn=INT_MAX;
        for(int i=0;i<=n;i++){
            mn=min(mn,one[i]+zero[i]);
        }
        return mn;
    }
};