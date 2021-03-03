class Solution {
public:
//    // Recursive (8ms, 18.9MB), similar to DFS
//     int maxDepth(TreeNode* root) {
//         int max = 0;
//         if(root == nullptr)
//             return 0;
        
//         // if root is not empty
//         max = 1;
//         int leftDepth = maxDepth(root->left);
//         int rightDepth = maxDepth(root->right);
        
//         if(leftDepth < rightDepth)
//             max += rightDepth;
//         else
//             max += leftDepth;
        
//         return max;
//     }
    
    // Iterative, (8ms, 18.9MB), BFS
    int maxDepth(TreeNode* root){
        int max = 0;
        
        if(root == nullptr)
            return max;
        
        // keep nodes at the same level in a queue -> BFS
        queue<TreeNode*> level;
        level.push(root);
        
        while(!level.empty()){
            max++;
            
            // There can be 0, 1, 2 children
            int levelSize = level.size();
            for(int i=0 ; i<levelSize ; i++){
                TreeNode* node = level.front();
                level.pop();
                
                if(node->left)
                    level.push(node->left);
                if(node->right)
                    level.push(node->right);
            }
                
        }
        
        return max;
    }
    
};