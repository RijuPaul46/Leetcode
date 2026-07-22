class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=s.size();
        vector<int>s_one(n);
        int one=0,zero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
            }else one++;
            s_one[i]=one;
        }
        vector<bool>ans(strs.size(),true);
        for(int i=0;i<strs.size();i++){
            int o=0,z=0;
            for(int j=0;j<n;j++){
                char c=strs[i][j];
                if(c=='0')z++;
                if(c=='1')o++;
            }
            if(o>one || z>zero){
                ans[i]=false;
            }
            else{
                int rem_o=one-o;
                int rem_z=zero-z;
                int on=0;
                for(int j=0;j<n;j++){
                    if(strs[i][j]=='?'){
                        if(rem_z==0){
                            on++;
                            if(on>s_one[j]){
                                ans[i]=false;
                                break;
                            }
                        }
                        else rem_z--;
                    }
                    if(strs[i][j]=='1'){
                        on++;
                        if(on> s_one[j]){
                            ans[i]=false;
                            break;
                        }
                    }
                }   
            }
        }
        return ans;
    }
};