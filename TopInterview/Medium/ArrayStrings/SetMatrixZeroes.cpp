// M1) Save the location of the zeros
// (vector arrays) 16ms, 13.3MB
// (set) 12ms, 13.5MB
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    

    // vector<int> row;
    // vector<int> column;
    set<int> row;
    set<int> column;
    
    // Propagate through rows, and save the location of the zeroes
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(matrix[i][j] == 0){
                row.insert(i);
                column.insert(j);
                // row.push_back(i);
                // column.push_back(j);    
            }
        }   
    }
    
    // Set zero in the matrix
    set<int>::iterator it;
    for(it = row.begin() ; it != row.end() ; it++){
        for(int j=0 ; j<n ; j++)
            matrix[*it][j] = 0;
    }
    for(it = column.begin() ; it != column.end() ; it++){
        for(int j=0 ; j<m ; j++)
            matrix[j][*it] = 0;
    }
    
}


// Trying to get O(1) solution.. failed
// M2) Save the location of the zeros - 
// O(1) space solution, you can use one of the rows and and one of the columns to keep track of this information.
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Position of the first zero
    int row = -1;
    int col = -1;
    
    // Find the position of the first zero
    for(int i=0 ; i<m ; i++){
        if(row != -1 && col != -1)
            break;
        
        for(int j=0 ; j<n ; j++){
            if(matrix[i][j] == 0){
                if(row == -1 && col == -1){
                    row = i;
                    col = j;
                    break;
                }
            }
        }   
    }
    
    
    int rowIndex = 0;
    int colIndex = 0;
    
    // Propagate through rows, and save the location of the zeroes
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(i == row && j == col)
                continue;
            
            if(matrix[i][j] == 0){
                // Save row
                // if not duplicate, save the index
                if(matrix[row][rowIndex] != i){
                    rowIndex++;
                    if(rowIndex == col)
                        rowIndex++;
                    matrix[row][rowIndex] = i;
                }
                
                // Save col
                // if not duplicate, save the index
                if(matrix[colIndex][col] != j){
                    colIndex++;
                    if(colIndex == row)
                        colIndex++;
                    matrix[colIndex][col] = j;
                }
            }
        }   
    }
    
    // Reset indices to go through positions of the zeroes
    rowIndex = 0;
    colIndex = 0;
    
    // Set zero in the row of matrix
    for(int i=0; i<m; i++){
        if(i == row)
            continue;
        
        if(i == matrix[row][rowIndex]){
            for(int j=0 ; j<n ; j++){
                matrix[i][j] = 0;
            }
            matrix[row][rowIndex] = 0;
            rowIndex++;
        }
    }
    
    // Set zero in the column of matrix
    for(int i=0; i<n; i++){
        if(i == col)
            continue;
        
        if(i == matrix[colIndex][col]){
            for(int j=0 ; j<m ; j++){
                matrix[j][i] = 0;
            }
            matrix[colIndex][col] = 0;
            colIndex++;
        }
    }
}


// The better solution
// 8ms, 13.1MB
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix[0].size();
    int n = matrix.size();
        
    bool row_flag = false;
    bool col_flag = false;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    row_flag = true;
                if (j == 0)
                    col_flag = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero each column
    for (int i=1; i<m; i++)
    {
        if (matrix[0][i] == 0)
        {
            for (int j=1; j<n; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    // Zero each row
    for (int i=1; i<n; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j=1; j<m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (row_flag)
    {
        for (int i=0; i<m; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (col_flag)
    {
        for (int i=0; i<n; i++)
        {
            matrix[i][0] = 0;
        }
    }

}
