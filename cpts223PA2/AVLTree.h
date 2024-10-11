

#include <iostream>
#include <limits>
#include <vector>
using namespace std;


template <typename Comparable>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void makeEmpty();
    const Comparable & findMin() const;
    const Comparable & findMax() const;

    bool contains(const Comparable & x) const;
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    int treeSize() const;
    int computeHeight() const;
    int readRootHeight() const;
    bool isBalanced() const;
    bool isBST() const;

    double averageDepth() const;
    void removeByRank(int rank);

    // the next line follows textbook Figure 4.42, Line 19
    static const int ALLOWED_IMBALANCE = 1;
private:
    struct AVLNode  // refer to textbook, Figure 4.40
    {
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode( const Comparable & theElement, AVLNode *lt, AVLNode *rt ): element(theElement), left(lt), right(rt) {}
        AVLNode( Comparable && theElement, AVLNode *lt, AVLNode *rt ): element(move(theElement)), left(lt), right(rt) {}
    };

    AVLNode *root;

    AVLNode * findMin( AVLNode * t ) const;
    AVLNode * findMax( AVLNode * t ) const;
    void makeEmpty( AVLNode * & t );

    void balance(AVLNode * & t);
    void rotateWithLeftChild( AVLNode * & t );
    void rotateWithRightChild( AVLNode * & t );
    void doubleWithLeftChild( AVLNode * & t);
    void doubleWithRightChild( AVLNode * & t);
    
    //my private functions
    int height(const AVLNode*ptr);
    bool contains(AVLNode*ptr,const Comparable & x) const;
    void insert(AVLNode*&ptr,const Comparable & x);
    void remove(AVLNode*&ptr,const Comparable & x);

};

// constructor
template <class Comparable>
AVLTree<Comparable>::AVLTree() : root(NULL) {}

// destructor
template <class Comparable>
AVLTree<Comparable>::~AVLTree()
{
    makeEmpty();
}

// public makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode * & t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// public findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMin() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMin(root)->element;
}

// private findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMin(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMax() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMax(root)->element;
}

// private findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMax(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMax(t->right);
    }
}

// start our implementation:
// public contains: follow the contains in BST, referring to textbook, Figure 4.17 and Figure 4.18
template<typename Comparable>
bool AVLTree<Comparable>::contains( const Comparable & x ) const {
    return contains(root,x);
}

//private contains
template<typename Comparable>
bool AVLTree<Comparable>::contains(AVLNode*ptr,const Comparable & x) const {
    if (ptr==nullptr) return false;
    else if (x<ptr->element) return contains(ptr->left,x); //go left if the element being searched is lower
    else if (x>ptr->element) return contains(ptr->right,x); //go right if the element being searched is higher
    else return true;
}

//private height - returns -1 when empty or height stored in the node otherwise
template<typename Comparable>
int AVLTree<Comparable>::height(const AVLNode*ptr) {
    return ptr==nullptr ? -1 : ptr->height;
}

// public insert: following BST, referring to textbook, Figure 4.17 and Figure 4.23
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x) {
    insert(root,x);
}

//private insert
template<typename Comparable>
void AVLTree<Comparable>::insert(AVLNode*&ptr,const Comparable & x) {
    if (ptr==nullptr) ptr = new AVLNode(x,nullptr,nullptr);
    else if (x<ptr->element) insert(ptr->left,x);
    else if (x>ptr->element) insert(ptr->right,x);
    else; // item already exists in the tree

    balance(ptr);
}

// public remove: refer to textbook, Figure 4.17 and Figure 4.26
template<typename Comparable>
void AVLTree<Comparable>::remove( const Comparable & x ) {
    remove(root,x);
}

//private remove
template<typename Comparable>
void AVLTree<Comparable>::remove(AVLNode*&ptr,const Comparable & x) {
    if (ptr==nullptr) return; // no match and at the end of tree
    
    if (x<ptr->element) remove(ptr->left,x);
    else if (x>ptr->element) remove (ptr->right,x);
    else if (ptr->left!=nullptr && ptr->right!=nullptr) {
        ptr->element=findMin(ptr->right);
        remove(ptr->right,ptr->element);
    }
    else {
        AVLNode*delNode=ptr;
        ptr = (ptr->left != nullptr) ? ptr->left : ptr->right;
        delete delNode;
    }

    balance(ptr);
}

// private balance: refer to textbook, Figure 4.42, Line 21 - 40
// assume t is the node that violates the AVL condition, and we then identify which case to use (out of 4 cases)
template<typename Comparable>
void AVLTree<Comparable>::balance(AVLNode * & t) {
    if (t==nullptr) return;

    if (height(t->left)-height(t->right)>1) { // difference of heights between subtrees are larger than 1 (not allowed in AVL trees, a balancing action is required)
        if (height(t->left->left)>=height(t->left->right)) rotateWithLeftChild(t);
        else doubleWithLeftChild(t);
    }
    if (height(t->right)-height(t->left)>1) {
        if (height(t->right->right)>=height(t->right->left)) rotateWithRightChild(t);
        else doubleWithRightChild(t);
    }

    t->height=max(height(t->left),height(t->right))+1;
}

// private rotateWithLeftChild: for case 1, referring to textbook, Figure 4.44 (code) and Figure 4.43 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode * & k2) {
    AVLNode*temp=k2->left;
    k2->left=temp->right;
    temp->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    temp->height=max(height(temp->left),k2->height)+1;
    k2=temp;
}

// private rotateWithRightChild: for case 4 (the mirrored case of case 1)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode * & k2) {
    AVLNode*temp=k2->right;
    k2->right=temp->left;
    temp->left=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    temp->height=max(height(temp->right),k2->height)+1;
    k2=temp;
}

// private doubleWithLeftChild: for case 2, see textbook, Figure 4.46 (code) and Figure 4.45 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode * & k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

// private doubleWithRightChild: for case 3 (the mirrored case of case 2)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode * & k3) {
   rotateWithLeftChild(k3->right);
   rotateWithRightChild(k3);
}

// public isBalanced
template <class Comparable>
bool AVLTree<Comparable>::isBalanced() const {
    cout << "TODO: isBalanced function" << endl;
    return false;
}

// public isBST
template <class Comparable>
bool AVLTree<Comparable>::isBST() const {
    cout << "TODO: isBST function" << endl;
    return false;
}

// public treeSize
template <typename Comparable>
int AVLTree<Comparable>::treeSize() const {
    cout << "TODO: treeSize function" << endl;
    return 0;
}

// public computeHeight. See Figure 4.61 in Textbook
template <typename Comparable>
int AVLTree<Comparable>::computeHeight() const {
    cout << "TODO: computeHeight function" << endl;
    return -1;
}

// public readRootHeight
template <typename Comparable>
int AVLTree<Comparable>::readRootHeight() const {
    cout << "TODO: readRootHeight function" << endl;
    return -1;
}

// public averageDepth
template <typename Comparable>
double AVLTree<Comparable>::averageDepth() const {
    cout << "TODO: averageDepth function" << endl;
    return 0.0;
}

// public removeByRank
template <typename Comparable>
void AVLTree<Comparable>::removeByRank(int rank) {
    cout << "TODO: removeByRank function" << endl;
}

