#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;


/* ----------------------------------------------------------------------------
---- Below is declaration of BST class, referring to textbook, Figure 4.16 ----
---------------------------------------------------------------------------- */

template <typename Comparable>
class BST
{
public:
	BST();
	~BST();
	void makeEmpty();

	const Comparable & findMin() const;
	const Comparable & findMax() const;

	bool contains(const Comparable & x) const;
	void insert(const Comparable & x);
	void remove(const Comparable & x);
	int treeSize() const;
	int treeHeight() const;
	void printInOrder() const;
	void printLevels() const;
	void printMaxPath() const;

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt): element(theElement), left(lt), right(rt) {}
		BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt): element(move(theElement)), left(lt), right(rt) {}
	};

	BinaryNode *root;

	BinaryNode * findMin( BinaryNode * t ) const;
	BinaryNode * findMax( BinaryNode * t ) const;
	void makeEmpty( BinaryNode * & t );

	void insert( const Comparable & x, BinaryNode * & t );
	void insert( Comparable && x, BinaryNode * & t );
	bool contains( const Comparable & x, BinaryNode *t ) const;
	void remove( const Comparable & x, BinaryNode * & t );

};


/* --------------------------------------------------------------
---- Below is implementation of public and private functions ----
-------------------------------------------------------------- */

// constructor
template<typename Comparable>
BST<Comparable>::BST() : root(NULL) {}

// destructor, refer to textbook, Figure 4.27
template<typename Comparable>
BST<Comparable>::~BST() {
	makeEmpty();
}

// public makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty(BinaryNode *& t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// // public findMin
template <typename Comparable>
const Comparable & BST<Comparable>::findMin() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMin(root)->element;
}

// private findMin: refer to textbook, Figure 4.20
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMin(BinaryNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax
template <typename Comparable>
const Comparable & BST<Comparable>::findMax() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMax(root)->element;
}

// private findMax: refer to textbook, Figure 4.21
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMax(BinaryNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMin(t->right);
    }
}

// public contains: refer to textbook, Figure 4.17, Line 4 - 7
template<typename Comparable>
bool BST<Comparable>::contains( const Comparable & x ) const {
	return contains(x,root);
}

//private contains
template<typename Comparable>
bool BST<Comparable>::contains( const Comparable & x, BinaryNode *t ) const {
	if( t == nullptr ) return false;
	else if( x < t->element ) return contains( x, t->left );
	else if( t->element < x ) return contains( x, t->right );
	else return true;
}

// public insert: refer to textbook, Figure 4.17, Line 12 - 15
template<typename Comparable>
void BST<Comparable>::insert(const Comparable & x) {
	insert(x,root);
}

//private inserts
//insert by creating a node
template<typename Comparable>
void BST<Comparable>::insert( const Comparable & x, BinaryNode *&t) {
	if( t == nullptr ) t = new BinaryNode{ x, nullptr, nullptr };
	else if( x < t->element ) insert( x, t->left );
	else if( t->element < x ) insert( x, t->right );
}
//insert by moving
template<typename Comparable>
void BST<Comparable>::insert( Comparable && x, BinaryNode *&t) {
	if( t == nullptr ) t = new BinaryNode{ std::move( x ), nullptr, nullptr };
	else if( x < t->element ) insert( std::move( x ), t->left );
	else if( t->element < x ) insert( std::move( x ), t->right );
}

// public remove: refer to textbook, Figure 4.17, Line 20 - 23
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x ) {
	remove(x,root);
}

//private remove
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x, BinaryNode *&t) {
	if( t == nullptr ) return; // Item not found; do nothing
	if( x < t->element ) remove( x, t->left );
	else if( t->element < x ) remove( x, t->right );
	else if( t->left != nullptr && t->right != nullptr ) {
	t->element = findMin( t->right )->element;
	remove( t->element, t->right );
	}
	else {
	BinaryNode *oldNode = t;
	t = ( t->left != nullptr ) ? t->left : t->right;
	delete oldNode;
	}
}

// public treeSize
template <typename Comparable>
int BST<Comparable>::treeSize() const {
	cout << "**TODO**: treeSize function" << endl;
	return 0;
}

// public treeHeight
template <typename Comparable>
int BST<Comparable>::treeHeight() const {
	cout << "**TODO**: treeHeight function" << endl;
	return 0;
}

// public printInOrder: refer to textbook, Figure 4.60
template<typename Comparable>
void BST<Comparable>::printInOrder() const {
	cout << "**TODO**: printInOrder function" << endl;
}

// public printLevels
template <typename Comparable>
void BST<Comparable>::printLevels() const {
	cout << "**TODO**: printLevels function" << endl;
}

// public printMaxPath
template <typename Comparable>
void BST<Comparable>::printMaxPath() const {
	cout << "**TODO**: printMaxPath function" << endl;
}

#endif
