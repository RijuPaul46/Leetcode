class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int m = box.size();
        int n = box[0].size();

        // STEP 1: Apply gravity
        for(int i = 0; i < m; i++) {

            int empty = n - 1;

            for(int j = n - 1; j >= 0; j--) {

                // obstacle
                if(box[i][j] == '*') {
                    empty = j - 1;
                }

                // stone
                else if(box[i][j] == '#') {

                    swap(box[i][j], box[i][empty]);

                    empty--;
                }
            }
        }

        // STEP 2: Rotate clockwise
        vector<vector<char>> ans(n, vector<char>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                ans[j][m - 1 - i] = box[i][j];
            }
        }

        return ans;
    }
};