//
// Created by Liu on 2023/7/12.
// Description: 
//

#include <iostream>
#include<vector>
#include<algorithm>
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


/*
 * 正常版本
 */
void post(Node * root, vector<int> & res){
    if(root == nullptr){
        return ;
    }

    for(Node* node : root->children){
        post(node, res);
    }

    res.push_back(root->val);
}

vector<int> postorder(Node* root) {
    vector<int> res;

    post(root, res);

    return res;
}


/*
 * 我的奇思妙想
 * didn't work sad...
 */
//void post(Node * root, vector<int> & res){
//    if(root == nullptr){
//        return ;
//    }
//
//    res.push_back(root->val);
//    cout << (*(root->children.end()-1))->val << endl;
//
//    if(root->children.size() != 0) {
//        for (auto it = root->children.end() - 1; it >= root->children.begin(); --it) {
//            post((*it), res);
//        }
//    }else{
//        return;
//    }
//
//}

vector<int> postorder(Node* root) {
    vector<int> res;

    post(root, res);

    reverse(res.begin(), res.end());

    return res;
}
int main() {

    Node * root = new Node(1);

    vector<Node *> children1;
    Node * l1_1 = new Node(3);
    children1.push_back(l1_1);
    Node * l1_2 = new Node(2);
    children1.push_back(l1_2);
    Node * l1_3 = new Node(4);
    children1.push_back(l1_3);

    vector<Node *> children2;
    Node * l2_1 = new Node(5);
    children2.push_back(l2_1);
    Node * l2_2 = new Node(6);
    children2.push_back(l2_2);

    root->children = children1;
    l1_1->children = children2;

    for(auto it = root->children.end()-1; it >= root->children.begin(); --it){
        cout << (*it)->val << endl;
    }

    vector<int> res = postorder(root);

    for(int val : res){
        cout << val << " " <<  endl;
    }


}
