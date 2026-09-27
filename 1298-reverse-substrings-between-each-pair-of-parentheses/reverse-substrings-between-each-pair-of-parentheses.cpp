class Solution {
public:
    string solve(string &s,int l,int r,unordered_map<int,int> &mp){
        int n=s.size();
        if(l>r)return "";
        string str="";
        for(int i=l;i<=r;i++){
            if(s[i]=='('){
                int next=mp[i];
                string ans=solve(s,i+1,next-1,mp);
                reverse(ans.begin(),ans.end());
                str+=ans;
                i=next;
            }
            else str+=s[i];
        }
        // reverse(str.begin(),str.end());
        return str;
    }
    // string solve(string &s,int i,int j){
    //     int n=s.size();
    //     string str="";
    //     for(int k=i;k<=j;k++){
    //         if(s[k]=='('){
    //             // string key="";
    //             int score=1;
    //             int next=k+1;
    //             while(next<=j && score>0){
    //                 // key+=s[next];
    //                 if(s[next]=='(')score++;
    //                 if(s[next]==')')score--;
    //                 next++;
    //             }
                
    //             string ans=solve(s,k+1,next-2);
    //             str+=ans;
    //             k=next;
    //         }
    //         else str+=s[k];
    //     }
        
    //     reverse(str.begin(),str.end());
    //     return str;
    // }
    string reverseParentheses(string s) {
        int n=s.size();
        // first find all the matching pair so that it need not to be recalculated....
        vector<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push_back(i);
            else if(s[i]==')'){
                int tp=st.back();
                mp[tp]=i;
                st.pop_back();
            }
        }
        return solve(s,0,n-1,mp);
    }
};