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
    int ans;
    pair<int,int> solve(TreeNode* root){
        if (root==nullptr) return {0,0};
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);

        int total_sum=left.first+right.first+root->val;
        int total=left.second+right.second+1;

        int avg=total_sum/total;
        if (avg==root->val) ans++;

        return {total_sum,total};
    }
    int averageOfSubtree(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};