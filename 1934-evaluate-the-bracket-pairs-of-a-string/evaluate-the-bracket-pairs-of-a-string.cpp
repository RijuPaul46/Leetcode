class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &v:knowledge){
            mp[v[0]]=v[1];
        }
        string ans="";
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(str.size()>0)ans+=str;
                str="";
                int j=i+1;
                while(j<n && isalpha(s[j]))str+=s[j++];
                string val="?";
                if(mp.count(str))val=mp[str];
                ans+=val;
                str="";
                i=j;
            }
            else str+=s[i];
        }
        if(str.size()>0)ans+=str;
        return ans;
    }
};