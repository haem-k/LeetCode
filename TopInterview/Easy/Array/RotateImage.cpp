class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> temp(4, 0);
        
        for(int i=0; i<n/2 ; i++){
            for(int j=i; j<(n-i-1); j++){
                temp[0] = matrix[i][j];
                temp[1] = matrix[j][n-i-1];
                temp[2] = matrix[n-i-1][n-j-1];
                temp[3] = matrix[n-j-1][i];
                
                matrix[j][n-i-1] = temp[0];
                matrix[n-i-1][n-j-1] = temp[1];
                matrix[n-j-1][i] = temp[2];
                matrix[i][j] = temp[3];
                
            }
        }
    }
};