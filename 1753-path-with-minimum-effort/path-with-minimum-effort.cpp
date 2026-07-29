#define state tuple<int,int,int>
class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& ht) {
        int m=ht.size();
        int n=ht[0].size();
        vector<vector<int>> eff(m,vector<int>(n,INT_MAX));
        eff[0][0]=0;
        priority_queue<state,vector<state>,greater<state>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [d,x,y]=pq.top();
            pq.pop();
            if(d>eff[x][y])continue;
            for(int i=0;i<4;i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int nw=max(d,abs(ht[nx][ny]-ht[x][y]));
                    if(nw<eff[nx][ny]){
                        eff[nx][ny]=nw;
                        pq.push({nw,nx,ny});
                    }
                }
            }
        }
        return eff[m-1][n-1];

    }
};