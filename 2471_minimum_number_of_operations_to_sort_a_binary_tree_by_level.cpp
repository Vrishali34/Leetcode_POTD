class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int totalOps = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            totalOps += minSwapsToSort(level);
        }

        return totalOps;
    }

private:
    int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> valIdx(n);
        for (int i = 0; i < n; i++) {
            valIdx[i] = {arr[i], i};
        }
        
        sort(valIdx.begin(), valIdx.end());
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || valIdx[i].second == i) continue;

            int cycleSize = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = valIdx[j].second;
                cycleSize++;
            }
            if (cycleSize > 1) swaps += cycleSize - 1;
        }

        return swaps;
    }
};
