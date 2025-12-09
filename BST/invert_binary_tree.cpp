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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return NULL;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            TreeNode* Node = temp -> left;
            temp -> left = temp -> right;
            temp -> right = Node;

            if(temp -> left != NULL)
            {
                q.push(temp -> left);
            }

            if(temp -> right != NULL) {
                q.push(temp -> right);
            } 
        }
        return root;
    }
};