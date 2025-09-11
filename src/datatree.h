
#include <iostream>
#include <string>


class Node{
    public:
    std::string data;
    Node* left;
    Node* right;
    Node(std::string val);
};

class filetree{
    public:
    Node *root;
    filetree();
    const bool isEmpty(Node* r);
    Node* To_insert(Node* r,std::string val);
    void To_insert(std::string val);
    void save();
    void print_preorder(Node* r);
    void print_inorder(Node* r);
    void print_postorder(Node* r);
};
extern filetree Manage_Data_Tree;
