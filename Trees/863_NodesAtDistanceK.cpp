class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    void mapParents(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        mapParents(node->left, node);
        mapParents(node->right, node);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        mapParents(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int dist = 0;
        while (!q.empty() && dist < k) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                for (TreeNode* nxt : {cur->left, cur->right, parent[cur]}) {
                    if (nxt && !visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            dist++;
        }
        vector<int> res;
        while (!q.empty()) { res.push_back(q.front()->val); q.pop(); }
        return res;
    }
};