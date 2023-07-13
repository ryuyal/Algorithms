//
// Created by Liu on 2023/7/12.
// Description: 
//

#include <iostream>
#include<vector>
using namespace std;

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

// N叉树前序遍历
void pre(Node * root, vector<int> & res){
    if(root == nullptr){
        return;
    }

    res.push_back(root->val);

    for(auto node : root->children){
        pre(node, res);
    }

}


vector<int> preorder(Node* root) {
    vector<int> res;
    pre(root, res);

    return res;
}

int main() {

}
