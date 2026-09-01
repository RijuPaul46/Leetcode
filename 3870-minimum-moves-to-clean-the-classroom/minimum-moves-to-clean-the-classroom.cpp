// there are atmost 10 L in the cell 
// i can store them in bitmask 
// but each state must be visited once to get answer
// but i will visit state for many time if we get fewer move 
// so conceptually okay but tle 
// we can optimise it : BFS will ensure that move is already min ... 
// we will visit a state iff we have better energy 
// so same state is being already visited with lower energy and it is also exploring next state ... we will only visit that state again iff we have greater energy .... higher possibiity .... if at any state we come across final state .. we immediately return the mov .. because bfs ensure that the mov is min
class State{
    public:
    int x,y,mask,energy;
    State(int a,int b,int c,int d){
        x=a;
        y=b;
        mask=c;
        energy=d;
    }
} ;
class Solution {
public:
    int best[21][21][1<<10];
    vector<vector<int>> pos;
    // we have to make min move ... for x,y,same mask,energy
    // try storing min number of move to reach there
    int final_state;
    int mx_energy;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int xx,int yy,int ee,int maskk,int mov,vector<string>& cr){
        int m=cr.size();
        int n=cr[0].size();
        queue<State>q;
        q.push(State(xx,yy,maskk,ee));
        
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
            auto st=q.front();
            q.pop();
            int x=st.x,y=st.y,mask=st.mask,e=st.energy;
            if(cr[x][y]=='R')e=mx_energy;
            if(cr[x][y]=='L'){
                int ps=pos[x][y];
                mask=mask|(1<<ps);
            }
            if(mask==final_state)return mov;
                if(e>0){
                    for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && cr[nx][ny]!='X' && best[nx][ny][mask]<e-1){
                        best[nx][ny][mask]=e-1;
                        // cout<<"hi";
                        q.push(State(nx,ny,mask,e-1));
                        }
                    }
                }
            }
            mov++;

        }
        return -1;
        
    }
    
    int minMoves(vector<string>& cr, int e) {
        int m=cr.size();
        int n=cr[0].size();
        mx_energy=e;
        fill(&best[0][0][0],
     &best[0][0][0] + 21*21*(1<<10),
     INT_MIN);
        pos.resize(m,vector<int>(n,-1));
        int cnt=0;
        int sx=-1,sy=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(cr[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
                if(cr[i][j]=='L'){
                    pos[i][j]=cnt++;

                }
            }
        }
        final_state=(1<<cnt)-1;
        cout<<final_state<<endl;
        // max val = 2^10
        // all one if collected
        best[sx][sy][0]=e;
        int ans=dfs(sx,sy,e,0,0,cr);
        return ans;

        
    }
};