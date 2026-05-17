class Solution {
public:
    // int mnj;
    // int mxj;
    // let say mn=1 mx= 10^4   and final ans is false 
    // so for each index i will iterate for 10^4 time 
    // O(n2) solution
    // bool dfs(int i,string &s,vector<bool>& visited,int till){
        
    //     int n=s.size();
    //     if(i==n-1)return true;
    //     visited[i]=true;
    //     for(int j=i+mnj;j<=min(i+mxj,n-1);j++){
    //         if(s[j]=='0' && !visited[j]){
    //             if(dfs(j,s,visited)) return true;
    //         }
    //     }
    //     return false;
    // }
    bool canReach(string s, int minJump, int maxJump) {
        // mnj=minJump;
        // mxj=maxJump;
        int n=s.size();
        vector<bool> visited(n,false);
        // bfs will go to each index that can be reached 
        // visited will prevent for repeated call and i will 
        // keep track of how much i scanned so far ... because
        // in queue only increasing numbers will be there 
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int till=0;
        while(!q.empty()){
            int front=q.front();
            if(front==n-1)return true;
            q.pop();
            for(int i=max(front+minJump,till+1);i<=min(front+maxJump,n-1);i++){
                if(s[i]=='0' && !visited[i]){
                    visited[i]=true;
                    q.push(i);
                    
                }
            }
            till=min(front+maxJump,n-1);
        }
        return false;


    }
};