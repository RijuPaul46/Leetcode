class Solution {
public:
    vector<string>ans;
    void solve(int start,string &s,set<string>&st,string str){
        int n=s.size();
        if(start==n){
            str.pop_back();
            ans.push_back(str);
            return ;
        }
        for(int i=start;i<n;i++){
            string sub=s.substr(start,i-start+1);
            if(st.count(sub)){
                string nstr=str+sub+" ";
                solve(i+1,s,st,nstr);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string str="";
        set<string>st;
        for(auto &x:wordDict)st.insert(x);
        solve(0,s,st,str);
        return ans;
    }
};