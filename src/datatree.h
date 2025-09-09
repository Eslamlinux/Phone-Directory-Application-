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
    bool isEmpty(Node* r);
    Node* To_insert(Node* r,std::string val);
    void insert(std::string val);
    void print_preorder(Node* r);
    void print_inorder(Node* r);
    void print_postorder(Node* r);
};