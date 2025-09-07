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
    bool isEmpty(){
        return root == NULL;
    }
    void To_insert(Node* r,std::string val){
        Node *newNode = new Node(val);
        if(isEmpty()){
            root = newNode;
        }
        else{
            if(val < r->data){
                if(r->left == NULL){
                    r->left = newNode;
                }
                else{
                    To_insert(r->left,val);
                }
            }
            else if(val > r->data){
                if(r->right == NULL){
                    r->right = newNode;
                }
                else{
                    To_insert(r->right,val);
                }
            }
            To_insert(root, val);
        }
    }
    void insert(Node* r, std::string val){
        To_insert(root,val);
    }
    
};