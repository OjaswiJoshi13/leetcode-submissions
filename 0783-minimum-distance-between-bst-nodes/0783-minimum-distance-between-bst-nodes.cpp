class Solution {
public:
    int diff = INT_MAX;
    TreeNode* prev = nullptr;

    void minDiffBST(TreeNode* root) {
        if (!root) return;

        minDiffBST(root->left);

        if (prev != nullptr) {
            diff = min(diff, root->val - prev->val);
        }

        prev = root;

        minDiffBST(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        minDiffBST(root);
        return diff;
    }
};