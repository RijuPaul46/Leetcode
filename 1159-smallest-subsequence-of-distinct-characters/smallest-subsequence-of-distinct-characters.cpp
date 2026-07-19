class Solution {
public:
    //keep a monotonic stack ... smaller char can knock out some char if the freq[ch] is >1 ... it can come later ... so knock this out ... only smaller char can knock higher ... vice versa not true
    string smallestSubsequence(string s) {
        vector<int>freq(26);
        vector<int>used(26);
        for(auto &x:s)freq[x-'a']++;
        string t="";
        for(auto &x:s){
            freq[x-'a']--;
            while(t.size()>0 && x<t.back() && freq[t.back()-'a']>0 &&!used[x-'a']){
                
                    used[t.back()-'a']=false;
                    t.pop_back();
                
                
            }
            if(!used[x-'a']){
            t+=x;
            used[x-'a']=true;}
            
        }
        return t;
    }
};