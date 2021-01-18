class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(int i=0 ; i<board.size() ; i++){
            // get each row
            vector<char> row = board[i];
            
            // return false when there is duplicate digits
            if(checkDuplicate(row))
                return false;
        }
    
        
        // check columns
        for(int i=0 ; i<board[0].size() ; i++){
            // get each column
            vector<char> col;
            for(int j=0 ; j<board.size() ; j++){
                col.push_back(board[j][i]);
            }
            
            // return false when there is duplicate digits
            if(checkDuplicate(col))
                return false;
        }   
        
        
        // check boxes
        // i : column index
        // j : row index
        vector<char> box;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                box.clear();

                box.push_back(board[3*j][3*i]);
                box.push_back(board[3*j+1][3*i]);
                box.push_back(board[3*j+2][3*i]);
                
                box.push_back(board[3*j][3*i+1]);
                box.push_back(board[3*j+1][3*i+1]);
                box.push_back(board[3*j+2][3*i+1]);
                
                box.push_back(board[3*j][3*i+2]);
                box.push_back(board[3*j+1][3*i+2]);
                box.push_back(board[3*j+2][3*i+2]);
                
                if(checkDuplicate(box))
                    return false;
            }
        }
        
        return true;
    }
    
    bool checkDuplicate(vector<char>& arr){
        vector<char> temp = arr;
        sort(temp.begin(), temp.end());
        
        for(int i=1; i<temp.size() ; i++){
            // there is a duplicate!
            if(temp[i] == temp[i-1] && temp[i] != '.')
                return true;
        }
        return false;
    }
};