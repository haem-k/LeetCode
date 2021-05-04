class Solution {
public:
    
    // M1) Uses too much memory (0ms, 6.6MB)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> row{1};
        result.push_back(row);
        
        for(int i=0 ; i<numRows-1 ; i++){
            vector<int> prev = result[i];
            vector<int> row{1};
        
            // Calculate row from previous row
            for(int j=0 ; j<prev.size()-1 ; j++){
                row.push_back(prev[j]+prev[j+1]);
            }
            row.push_back(1);
            result.push_back(row);   
        }
        
        return result;
    }
    
    // M2) Reuse what we are going to return as a result
    // Dynamic Programming ! (0ms, 6.2MB)
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> result(numRows);
        
        for(int i=0; i<numRows ; i++){
            result[i].resize(i+1);
            result[i][0] = 1;
            result[i][i] = 1;
            
            for(int j=1 ; j<result[i].size()-1 ; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        
        return result;
    }
};