#include "datatree.h"
#include <iostream>

filetree Manage_Data_Tree;



Node::Node(std::string val){
        data = val;
        left = nullptr;
        right = nullptr;
    };


    filetree::filetree(){
        root = nullptr;
    }


    const bool filetree::isEmpty(Node* r){
        return r == nullptr;
    }


    Node* filetree::To_insert(Node* r,std::string val){
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

    void filetree::To_insert(std::string val){
        root = To_insert(root,val);
    }


    void filetree::print_preorder(Node* r){
        
        if(isEmpty(r)){
            return;
        }
        else{
            std::cout << r->data << " ";
            print_preorder(r->left);
            print_preorder(r->right);
        }
    }
    
    
    void filetree::print_inorder(Node* r){
        if(isEmpty(r)){
            return;
        }
        else{
            print_inorder(r->left);
            std::cout << r->data << " ";
            print_inorder(r->right);
        }
    }

    
    void filetree::print_postorder(Node* r){
        if(isEmpty(r)){
            return;
        }
        else{
            print_postorder(r->left);
            print_postorder(r->right);
            std::cout << r->data << " ";
        }
    }

