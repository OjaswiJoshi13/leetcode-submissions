class Solution {
public:
    int count = 0;

    pair<int, int> fun(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto left = fun(root->left);

        auto right = fun(root->right);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        if (root->val == sum / nodes)
            count++;

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return count;
    }
};