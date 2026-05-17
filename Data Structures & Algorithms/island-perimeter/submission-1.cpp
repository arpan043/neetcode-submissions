class Solution {
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int rows, cols;
    int dfs(int row, int col){
        if(row < 0 || row >= rows || col >= cols
        || grid[row][col] == 0){
            return 1;
        }

        if(visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;

        return dfs(row, col+1) + dfs(row+1,col) + dfs(row,col-1) + dfs(row-1,col);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        rows = grid.size();
        cols = grid[0].size();

        visited = vector<vector<bool>>(rows,vector<bool>(cols,false));

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(grid[i][j] == 1)
                {
                    return dfs(i,j);
                }
            }
        }
        return 0;
    }
};