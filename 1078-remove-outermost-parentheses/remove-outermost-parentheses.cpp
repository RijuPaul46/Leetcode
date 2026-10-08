class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int cnt=0;
        int si=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')cnt++;
            else cnt--;
            if(cnt==0){
                ans+=s.substr(si+1,i-si-1);
                si=i+1;
            }
        }
        return ans;
    }
};