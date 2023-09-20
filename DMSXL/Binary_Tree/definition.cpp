
//
// Created by Yao on 2023/9/19.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

/*
 * 二叉树节点
 */
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

/*
 * N 叉树节点
 */
struct Node{
    int val;
    vector<Node *> children;
    Node(){}

    Node(int _val):val(_val){}

    Node(int _val, vector<Node*> _children):val(_val), children(_children){}
};

int main() {

}
