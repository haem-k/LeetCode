/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // 4ms, 12.2MB
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool leftRight = true;
        vector<vector<int>> result;
        queue<TreeNode*> level;
        
        // Check if root is NULL
        if(root == NULL)
            return result;
        
        // Put root first
        level.push(root);
        
        while(!level.empty()){
            int levelSize = level.size();
            vector<int> levelValue;
            
            for(int i=0 ; i<levelSize ; i++){
                TreeNode* node = level.front();
                level.pop();
                
                if(leftRight){
                    levelValue.push_back(node->val);
                }
                else{
                    levelValue.insert(levelValue.begin(), node->val);
                }
                
                // TLE error because I was pushing children of root everytime
                if(node->left) level.push(node->left);
                if(node->right) level.push(node->right);
            }
            
            result.push_back(levelValue);
            leftRight = !leftRight;                    
        }
        
        return result;
    }
};