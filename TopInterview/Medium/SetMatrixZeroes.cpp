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