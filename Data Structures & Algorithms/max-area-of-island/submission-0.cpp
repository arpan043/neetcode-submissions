class Solution {
	int directions[4][2] = {{0,1}, {0,-1},{1,0},{-1,0}};													  
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int area = 0;

        for(auto i = 0; i < rows;i++){
            for(auto j = 0; j < cols;j++){
                if(grid[i][j] == 1){
                    area = max(area, dfs(grid, i, j));
                }
            }
        }

        return area;
    }

    int dfs(vector<vector<int>> & grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() ||
            col >= grid[0].size() || grid[row][col] == 0){
                return 0;
            }

            grid[row][col] = 0;
            int res = 1;
            for(int i = 0; i < 4; i++){
                res += dfs(grid,row+directions[i][0],col+ directions[i][1]);
												   
            }
        return res;
    }
};
