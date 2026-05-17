class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int result = 0;
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> rowCnt(ROWS,0);
        vector<int> colCnt(COLS,0);

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j]==1){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j]==1 && (rowCnt[i] > 1 || colCnt[j] > 1)){
                    result++;
                }
            }
        }
        return result;
    }
};