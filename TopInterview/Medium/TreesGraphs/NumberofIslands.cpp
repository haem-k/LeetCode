class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0 ; i<m ; i++)
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == '1'){
                    ++count;
                    dfs(grid, i, j, m, n);
                }
            }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c, int& m, int& n){
        if(r<0 || c<0 || r==m || c==n || grid[r][c] == '0'){
            return;
        }
        
        grid[r][c] = '0';
        dfs(grid, r+1, c, m, n);
        dfs(grid, r-1, c, m, n);
        dfs(grid, r, c-1, m, n);
        dfs(grid, r, c+1, m, n);
    }






    // BFS
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int count = 0;
        int offsets[] = {0, 1, 0, -1, 0};
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == '1'){
                    count++;
                    grid[i][j] = '0';
                    
                    // go through connected elements using queue (BFS)
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while(!todo.empty()){
                        pair<int, int> p = todo.front();
                        todo.pop();
                        // move on to connected elements in grid
                        for(int k=0 ; k<4 ; k++){
                            int r = p.first + offsets[k];
                            int c = p.second + offsets[k+1];
                            // check if new row and column are valid
                            if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == '1'){
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};