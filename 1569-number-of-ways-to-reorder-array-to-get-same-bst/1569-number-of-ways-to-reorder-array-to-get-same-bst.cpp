class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    struct TreeNode {
        int val;
        int count = 1; 
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        TreeNode(int v) : val(v) {}
    };

    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        root->count++;
        return root;
    }

    long long countWays(TreeNode* root) {
        if (!root || root->count <= 2) return 1;

        long long leftWays = countWays(root->left);
        long long rightWays = countWays(root->right);

        int leftSize = root->left ? root->left->count : 0;
        int rightSize = root->right ? root->right->count : 0;

        long long ways = (comb[leftSize + rightSize][leftSize] * leftWays) % MOD;
        return (ways * rightWays) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        TreeNode* root = nullptr;
        for (int x : nums) {
            root = insert(root, x);
        }
        return (countWays(root) - 1 + MOD) % MOD;
    }
};