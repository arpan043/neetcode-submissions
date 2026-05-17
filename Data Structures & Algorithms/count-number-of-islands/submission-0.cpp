class Solution {
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int islands = 0;
        for(int i = 0; i < ROWS ; i++){
            for(int j = 0;j < COLS; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i , j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() ||
            col >= grid[0].size() || grid[row][col] == '0'){
                return;
            }

            grid[row][col] = '0';
            for(int i = 0; i <=4;i++){
                dfs(grid, row+directions[i][0], col+directions[i][1]);
            }
    }
};
