class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string t="";
        int n=s.size();
        vector<int>freq(26);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++; 
        }
        int a=freq[x-'a'];
        int b=freq[y-'a'];
        for(int i=0;i<b;i++){
            t+=y;
            freq[y-'a']--;
        }
        for(int i=0;i<26;i++){
                for(int j=0;j<freq[i];j++){
                    t=t+char('a'+i);
                }
            
        }
        return t;
        
    }
};
