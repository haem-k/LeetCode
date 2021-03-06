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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> level;
        
        if(root == nullptr)
            return result;
        
        level.push(root);
        
        while(!level.empty()){
            int levelSize = level.size();
            vector<int> levelVals;
            
            for(int i=0; i<levelSize ; i++){
                TreeNode* node = level.front();
                level.pop();
                
                // save value to vector
                levelVals.push_back(node->val);
                
                if(node->left) level.push(node->left);
                if(node->right) level.push(node->right);
            }
            
            result.push_back(levelVals);
        }
        
        return result;
    }
};