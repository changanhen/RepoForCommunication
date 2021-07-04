template <class T>
class BinaryTree{
protected:
    BinaryTreeNode <T> * root;
public:
    BinaryTree() {root = NULL;}
    BinaryTree(BinaryTreeNode <T> * r){root = r};
    ~ BinaryTree(){DeleteBinaryTree(root);};
    bool isEmpty() const;
    void visit (const T& data) {cout << data << " ";}
    BinaryTreeNode <T> * & Root() {return root;};
    BinaryTreeNode <T> * Parent(BinaryTreeNode <T> * current);
    BinaryTreeNode <T> * LeftSibling(BinaryTreeNode <T> * current);
    BinaryTreeNode <T> * RightSibling(BinaryTreeNode <T> * current);
    void CreateTree(BinaryTreeNode <T> * &r);
    void DeleteBinaryTree(BinaryTreeNode <T> * root);
    void PreOrder(BinaryTreeNode <T> * root);
    void InOrder(BinaryTreeNode <T> * root);
    void PostOrder(BinaryTreeNode <T> * root);
    void PreOrderWithoutRecusion(BinaryTreeNode <T> * root);
    void InOrderWithoutRecusion(BinaryTreeNode <T> * root);
    void PostOrderWithoutRecusion(BinaryTreeNode <T> * root);
    void LevelOrder(BinaryTreeNode <T> * root);
};
