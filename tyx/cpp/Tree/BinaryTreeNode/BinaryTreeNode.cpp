template <class T>
class BinaryTreeNode{
    friend class BinaryTree <T>;
    friend class BinarySerchTree <T>;
private:
    T data; /* data */
    BinaryTreeNode <T> * left;
    BinaryTreeNode <T> * right;
public:
    BinaryTreeNode(/* args */);
    BinaryTreeNode(const T& ele);
    BinaryTreeNode(const T& ele, BinaryTreeNode <T> * l, BinaryTreeNode <T> * r);
    ~ BinaryTreeNode(){};
    T value() const;
    BinaryTreeNode <T>& operator = (const BinaryTreeNode <T>& Node){this = Node};
    BinaryTreeNode <T> * leftchild() const;
    BinaryTreeNode <T> * rightchild() const;
    void    setLeftchild(BinaryTreeNode <T> *);
    void    setRightchild(BinaryTreeNode <T> *);
    void    setValue(const T& val);
    bool    isLeaf() const;
};
