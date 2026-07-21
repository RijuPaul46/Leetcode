class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int>left(n);
        vector<int>right(n);
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
            }
            else{
                one++;
                left[i]=zero;
                zero=0;
            }
        }
        zero=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                zero++;
            }
            else {
                right[i]=zero;
                zero=0;
            }
        }
        int si=-1;
        int ei=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                si=i;
                ei=i;
                while(ei+1<n && s[ei+1]!='0')ei++;
                int l=left[si];
                int r=right[ei];
                int one=ei-si+1;
                if(l>0 && r>0) ans=max(ans,l+r);
                i=ei;
            }
        }
        return ans+one;
    }
};