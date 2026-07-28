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
    int cnt;
    int dfs(TreeNode* root){
        if (root==nullptr) return 0;
        if (root->left==nullptr && root->right==nullptr){
            cnt++;
            return root->val;
        }
        int leftval=dfs(root->left);
        int rightval=dfs(root->right);
        int currval=root->val;
        if (currval>=max(leftval,rightval)) cnt++;
        return max({leftval,rightval,currval});
    }
    int countDominantNodes(TreeNode* root) {
        cnt=0;
        dfs(root);
        return cnt;
    }
};