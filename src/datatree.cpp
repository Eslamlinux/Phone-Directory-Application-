#include "datatree.h"
#include <iostream>
#include <fstream>

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

    void filetree::Save(Node* r){
        
        if(isEmpty(r)){
            return;
        }
        
        std::ofstream file;
        file.open("data/myPhoneData.txt", std::ios::app);

        if(file.is_open()) {
            file << r->data;
            file.close();
            
            Save(r->left);
            Save(r->right);
        }
    }
     void filetree::SaveToFile(){
        // Clear the file first
        std::ofstream file;
        file.open("data/myPhoneData.txt", std::ios::trunc);
        if(file.is_open()) {
            file.close();
        }
        
        // Save all data using in-order traversal
        Save(root);
    }
    
    std::string filetree::SearchInsideTree(Node* r, const std::string& val) {
        if (r == nullptr) {
            return val + " Not found"; // Not found
        }
        if (r->data.find(val) != std::string::npos) { // Check if 'val' is a substring of 'r->data'
            return r->data; // Found
        }
        else if (val < r->data) {
            return SearchInsideTree(r->left, val); // Search in left subtree
        }
        else {
            return SearchInsideTree(r->right, val); // Search in right subtree
        }
    } 
    std::string filetree::SearchInsideTree(const std::string& val) {
        return SearchInsideTree(Manage_Data_Tree.root, val);
    }


    Node* filetree::MiniData(Node* r) {
            if (isEmpty(r) ) {
                return r;
            }
            else if (isEmpty(r->left)) {
                return r;
            }
        return MiniData(r->left);
    }
    Node* filetree::MiniData() {
        return MiniData(root);
    }


    Node* filetree::MaxmumData(Node* r) {
            if (isEmpty(r)) {
                return r;
            }
            else if (isEmpty(r->right)) {
                return r;
            }
        return MaxmumData(r->right);
    }
    Node* filetree::MaxmumData() {
        return MaxmumData(root);
    }




    Node* filetree::Delete_Contact(Node* r ,std::string val) {        
        if (isEmpty(r)) {
            std::cout << "The contact list is empty. No contacts to delete.\n";
            return nullptr;
        }
        else if(val == "") {
            std::cout << "Invalid contact name. Please provide a valid name.\n";
            return nullptr;
        }
        else if(val < r->data) {
            r->left = Delete_Contact(r->left, val);
        }
        else if(val > r->data) {
            r->right = Delete_Contact(r->right, val);
        }
         else{   // Node with only one child or no child
            if (r->left == nullptr && r->right == nullptr) {
                if(r->data.find(val) != std::string::npos) {
                    delete r;
                    r = nullptr;
                } 
                else {
                    std::cout << "Contact not found. No contacts were deleted.\n";
                }

            } 
            else if (r->left != nullptr && r->right == nullptr) {
                if(r->data.find(val) != std::string::npos) {
                    Node* temp = r->left;
                    delete r;
                    r = temp;
                } 
                else {
                    std::cout << "Contact not found. No contacts were deleted.\n";
                }
            }
        else if (r->left == nullptr && r->right != nullptr) {
            if(r->data.find(val) != std::string::npos) {
                Node* temp = r->right;
                delete r;
                r = temp;
            } 
            else {
                std::cout << "Contact not found. No contacts were deleted.\n";
            }
        }
        else { // Node with two children: Get the inorder successor (smallest in the right subtree)
            if(r->data.find(val) != std::string::npos) {
            Node* temp = r->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }
        }
}
         }
        return r;
    }



    Node* filetree::Delete_All_Contacts(Node* r) {
        if (isEmpty(r)) {
            std::cout << "The contact list is already empty. No contacts to delete.\n";
            return nullptr;
        }
        r->left = Delete_All_Contacts(r->left);
        r->right = Delete_All_Contacts(r->right);
        delete r;
        r = nullptr;        
        std::cout << "All contacts have been deleted successfully.\n";
        return r;
    }
    Node* filetree::Delete_All_Contacts() {
        root = Delete_All_Contacts(root);
        return root;
    }

