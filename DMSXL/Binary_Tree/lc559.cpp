//
// Created by Liu on 2023/7/14.
// Description: 
//

#include<iostream>
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

int maxDepth(Node * root){
    if(root == nullptr){
        return 0;
    }

    if(root->children.size() == 0){
        return 1;
    }

    int maxD = 0;
    for(auto node : root->children){
        maxD = max(maxD, maxDepth(node));
    }
    return 1 + maxD;
}

int main(){

}
