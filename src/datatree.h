
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
    void Save(Node* r);
    void SaveToFile();
    Node* MiniData(Node* r);
    Node* MiniData();
    Node* MaxmumData(Node* r);
    Node* MaxmumData();
    std::string SearchInsideTree(Node* r, const std::string& val);
    std::string SearchInsideTree(const std::string& val);
    Node* Delete_Contact(Node* r, std::string ci); // Declaration of Delete_Contact method
    Node* Delete_All_Contacts(Node* r); // Declaration of Delete_All_Contacts method
    Node* Delete_All_Contacts(); // Declaration of Delete_All_Contacts method
    void print_preorder(Node* r);
    void print_inorder(Node* r);
    void print_postorder(Node* r);
};
extern filetree Manage_Data_Tree;
