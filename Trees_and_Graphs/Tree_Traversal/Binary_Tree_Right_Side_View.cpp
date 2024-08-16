#include<bits/stdc++.h>
using namespace std;

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
    void trav(TreeNode* root, vector<int> &ans, int &md, int level) {
        if(!root) return;
        //root
        if(md < level) {
            md = level;
            ans.push_back(root->val);
        }
        // rc
        trav(root->right, ans, md, level+1);
        // lc
        trav(root->left, ans, md, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int md = 0;
        trav(root, ans, md, 1);
        return ans;
    }
};