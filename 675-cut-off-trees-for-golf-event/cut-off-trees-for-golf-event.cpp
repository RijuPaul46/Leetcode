class Solution {
public:
    #define pr pair<int,int>
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int step(pr src,pr dst,vector<vector<int>>&forest){
    int m=forest.size();
    int n=forest[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    auto [sr,sc]=src;
    if(forest[sr][sc]==0)return -1;
    visited[sr][sc]=1;
    queue<pr>q;
    
    q.push(src);
    
    int cnt=0;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto nd=q.front();
            auto [x,y]=nd;
            if(nd==dst){
                forest[x][y]=1;
                return cnt;}
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && forest[nx][ny]!=0 && !visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
        cnt++;
    }
    return -1;
}
    int cutOffTree(vector<vector<int>>& forest) {
         int m=forest.size();
    int n=forest[0].size();
    vector<pair<int,pr>> arr;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int val=forest[i][j];
            if(val>1){
                arr.push_back({val,make_pair(i,j)});
            }
        }
    }
    sort(arr.begin(),arr.end());
    pr src={0,0};
    int stp=0;
    for(int i=0;i<(int)arr.size();i++){
        pr dst=arr[i].second;
        int st=step(src,dst,forest);
        if(st==-1)return -1;
        stp+=st;
        src=arr[i].second;
    }
    return stp;
    }
};