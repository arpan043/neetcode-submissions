class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int noOfRows = grid.size();
        int noOfCols = grid[0].size();
        int perimeter = 0;
        for(int i=0;i<noOfRows; i++)
        {
            for(int j=0;j<noOfCols;j++ ){
                if(grid[i][j] == 1)
                {
                    if(i-1 < 0 || grid[i-1][j]==0){
                        perimeter = perimeter + 1;
                    }
                    if(j+1>=noOfCols || grid[i][j+1]==0){
                        perimeter = perimeter + 1;
                    }
                    if(i+1>=noOfRows || grid[i+1][j]==0){
                        perimeter = perimeter + 1;
                    }
                    if(j-1<0 || grid[i][j-1]==0){
                        perimeter = perimeter + 1;
                    }
                }
            }
        }
        return perimeter;
    }
};