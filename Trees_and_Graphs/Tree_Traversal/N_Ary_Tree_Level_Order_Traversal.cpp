#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        Node* dummyNode = new Node(-1);
        q.push(dummyNode);
        vector<int> curr;
        while(!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            if(tmp->val != -1) {
                curr.push_back(tmp->val);
                for(auto n: tmp->children)
                    q.push(n);
            }
            else {
                ans.push_back(curr);
                curr.clear();
                if(!q.empty()) q.push(tmp);
            }
        }
        return ans;
    }
};