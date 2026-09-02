class State {
    public:
    int x, y, mask;
    State(int a, int b, int c) {
        x = a;
        y = b;
        mask = c;
    }
};
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> pos(m, vector<int>(n, -1));
        int key = 0;
        int lock = 6;
        unordered_map<char, int> lock_key;
        int sx = -1, sy = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    sx = i;
                    sy = j;
                }
                if (isalpha(c)) {
                    if (islower(c)) {
                        char lock_ = toupper(c);
                        pos[i][j] = key;
                        lock_key[lock_] = key++;
                    }
                }
            }
        }
        int final_state=(1<<key)-1;
        cout<<final_state;
        int visited[m + 1][n + 1][final_state+1];
        memset(visited,false , sizeof(visited));
        queue<State> q;
        q.push(State(sx, sy, 0));
        visited[sx][sy][0]=1;
        int mov = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto st = q.front();
                q.pop();
                int x = st.x, y = st.y, mask = st.mask;
                cout<<mask<<" ";
                // visited[x][y][mask]=1;
                
                char c = grid[x][y];
                if (isalpha(c)) {
                    if (isupper(c)) {
                        int key_pos = lock_key[c];
                        if(((mask) &(1<<key_pos))==0){
                            continue;
                        }
                        
                    } else {
                        int pos_ = pos[x][y];
                        mask = mask | (1 << pos_);
                    }
                }
                if ((mask&((1<<6)-1) )== final_state)
                    return mov;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        grid[nx][ny] != '#' && !visited[nx][ny][mask]) {
                        visited[nx][ny][mask]=true;
                        q.push(State(nx, ny, mask));
                    }
                }
            }
            mov++;
        }
        return -1;
    }
};