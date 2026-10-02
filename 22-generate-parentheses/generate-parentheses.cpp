class Solution {
public:
    vector<string> ans;
    void solve(int n,int open,int close,string str){
        if(open==n && close==n){
            ans.push_back(str);
            return;
        }
        // keep opening if open<n 
        string nstr=str+"(";
        if(open<n)solve(n,open+1,close,nstr);
        str.push_back(')');
        if(close<open)solve(n,open,close+1,str);
        return ;
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return ans;
    }
};