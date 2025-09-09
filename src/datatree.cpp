#include <iostream>
#include <fstream>
#include <string>

// دالة التحكم في التعديل والحذف والبحث باستخدام الباينري تري

class Node{
    public:
    std::string data;
    Node* left;
    Node* right;
    Node(std::string val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class filetree{
    public:
    Node *root;
    filetree(){
        root = NULL;
    }
    bool isEmpty(Node* r){
        return r == NULL;
    }
    Node* To_insert(Node* r,std::string val){
        Node *newNode = new Node(val);
        if(isEmpty(r)){
            r = newNode;
        }
        else if(val < r->data){
            r->left = To_insert(r->left,val);
        }
        else if(val > r->data){
            r->right = To_insert(r->right,val);
        }
        return r;
                }

    void insert(std::string val){
        root = To_insert(root,val);
    }
    void print_inorder(Node* r){
        if(r == NULL){
            return;
        }
        else{
            print_inorder(r->left);
            std::cout << r->data << " ";
            print_inorder(r->right);
        }
    }
    
};