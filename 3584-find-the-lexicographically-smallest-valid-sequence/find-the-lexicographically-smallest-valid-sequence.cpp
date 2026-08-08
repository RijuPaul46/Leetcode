class Solution {
public:
    // bool solve(string &word1,string &word2,int i,int j,int avail,vector<int>&arr,vector<vector<vector<int>>> &dp){
    //     int m=word1.size();
    //     int n=word2.size();
    //     if(j==n)return true;
    //     if(i==m)return false;
    //     auto &ref=dp[i][j][avail];
    //     if(ref!=-1)return ref;
    //     if(word1[i]==word2[j]){
    //         arr.push_back(i);
    //         bool equal=solve(word1,word2,i+1,j+1,avail,arr,dp);
    //         return ref=equal;            
    //     }
    //     if(avail){
    //             arr.push_back(i);
    //            bool swapped= solve(word1,word2,i+1,j+1,0,arr,dp);
    //            if(swapped)return ref=swapped;
    //            arr.pop_back();
               
    //     }
    //     bool skip=solve(word1,word2,i+1,j,avail,arr,dp);
    //     return ref=skip;
    // }
    void subseq(string &word1,string &word2,int i,int j,vector<int>&arr){
        int m=word1.size();
        int n=word2.size();
        if(j==n)return;
        if(i==m)return;
        if(word1[i]==word2[j]){arr.push_back(i);subseq(word1,word2,i+1,j+1,arr);}
        subseq(word1,word2,i+1,j,arr);
    }
    vector<int> validSequence(string word1, string word2) {
        vector<int>arr;
        int m=word1.size();
        int n=word2.size();
        // vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(-1)));
        // bool ans=solve(word1,word2,0,0,1,arr,dp);
        // if(ans)return arr;
        vector<int> dp(m+1,0);
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                dp[i]=dp[i+1]+1;
                i--;
                j--;
            }
            else {
                dp[i]=dp[i+1];
                i--;
            }
        }
        while(i>=0){
            dp[i]=dp[i+1];
            i--;
        }
        bool canbe=false;
        i=0;
        j=0;
        while(i<m && j<n){
            if(word1[i]==word2[j]){
                i++;
                j++;
            }
            else {
                // try replacing 
                if(dp[i+1]>=n-j-1){
                    word1[i]=word2[j];
                    canbe=true;
                    break;
                }
                else {
                    i++;
                }
            }
        }
        if(j==n)canbe=true;
        // now find the subseq;
        if(!canbe)return {};
        i=0;
        j=0;
        while(i<m && j<n){
            if(word1[i]==word2[j]){
                arr.push_back(i);
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        // subseq(word1,word2,0,0,arr);
        return arr;

    }
};