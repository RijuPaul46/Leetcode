class Solution {
public:
    //ans could be 1 2 or -1
    //if first or last .... any of them is in correct pos and is 1
    bool balanced(vector<int>&freq){
        for(auto &x:freq)if(x!=0)return false;
        return true;
    }
    int minOperations(string s) {
        int n=s.size();
        string str=s;
        sort(str.begin(),str.end());
        if(s==str)return 0;
        if((s[0]==str[0]) || s[n-1]==str[n-1])return 1;
        if(n==2){
            return -1;
        }
        char mn=str[0],mx=str[n-1];
        bool mni=true,mxi=true;
        for(int i=0;i<n;i++){
            if(i<n-1){
                if(s[i]==mn){
                    mni=false;
                    break;
                }
            }
            if(i>0){
                if(s[i]==mx){
                    mxi=false;
                    break;
                }
            }
        }
        if(mxi && mni)return 3;
        // if(str[0]==s[n-1] && str[n-1]==s[0])return 3;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            freq[str[i]-'a']--;
            if(balanced(freq))return 2;
        }
        return -1;
    }
};