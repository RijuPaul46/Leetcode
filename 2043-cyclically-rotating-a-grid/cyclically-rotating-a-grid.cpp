class Solution {
public:
    void rotateLayer(int i,int j,vector<vector<int>>& grid, int k){
        int m=grid.size();
        int n=grid[0].size();
        int r=n-1-j;
        int d=m-1-i;
        int peri = 2*(d-i) + 2*(r-j);
        k=k%peri;
        vector<int> arr;
        //down
        for(int x=i;x<=d;x++){
            arr.push_back(grid[x][j]);
        }
        for(int x=j+1;x<=r;x++){
            arr.push_back(grid[d][x]);
        }
        for(int x=d-1;x>=i;x--){
            arr.push_back(grid[x][r]);
        }
        for(int x=r-1;x>=j+1;x--){
            arr.push_back(grid[i][x]);
        }
        int idx=(peri-k)%peri;
        for(int x=i;x<=d;x++){
            grid[x][j]=arr[idx];
            idx=(idx+1)%peri;
        }
        for(int x=j+1;x<=r;x++){
            grid[d][x]=arr[idx];
            idx=(idx+1)%peri;
        }
        for(int x=d-1;x>=i;x--){
            grid[x][r]=arr[idx];
            idx=(idx+1)%peri;
        }
        for(int x=r-1;x>=j+1;x--){
            grid[i][x]=arr[idx];
            idx=(idx+1)%peri;
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<=min((m-1)/2,(n-1)/2);i++){
            rotateLayer(i,i,grid,k);
        }
        return grid;
    }
};