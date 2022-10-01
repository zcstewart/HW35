//Homework XX

/* 
 * Filename:        binaryTreeType.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 24, 2017, 1:43 PM
 */

#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H

//Preprocessor Directives
#include <cstdlib>
#include "binaryTreeNode.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//


template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();
    virtual bool search(const elemType &searchItem) const = 0;
    virtual void insert(const elemType &insertItem) = 0;
    virtual void deleteNode(const elemType &deleteItem) = 0;
    binaryTreeType(const binaryTreeType<elemType> &otherTree);
    binaryTreeType();
    ~binaryTreeType();
protected:
    binaryTreeNode<elemType> *root;
private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot);
    void destroy(binaryTreeNode<elemType>* &p);
    void inorder(binaryTreeNode<elemType> *p) const;
    void preorder(binaryTreeNode<elemType> *p) const;
    void postorder(binaryTreeNode<elemType> *p) const;
    int height(binaryTreeNode<elemType> *p) const;
    elemType max(elemType x, elemType y) const;
    int nodeCount(binaryTreeNode<elemType> *p) const;
    int leavesCount(binaryTreeNode<elemType> *p) const;
};
//--------------------------------------------------------------------------//

//Member Function Definitions

//--------------------------------------------------------------------------//

//Function:     operator=(const binaryTreeType<elemType>& otherTree)
//
//Inputs:       const binaryTreeType<elemType>& otherTree
//Outputs:      binaryTreeType<elemType>&
//Purpose:      The purpose of this function is to overload the assignment
//              operator for the binaryTreeType class.
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=
                                (const binaryTreeType<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr) //if the binary tree is not empty,
            //destroy the binary tree
            destroy(root);
        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
        copyTree(root, otherTree.root);
    }//end else
    return *this;
}

//Function:     isEmpty() const
//
//Inputs:       None
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to determine whether the 
//              current binary tree is empty.
template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

//Function:     inorderTraversal() const
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to traverse a binary 
//              tree "in-order". This means that the left tree is traversed,
//              the node is visited, then the right tree is traversed.
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

//Function:     preorderTraversal() const
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to traverse a binary tree 
//              in "pre-order" This means that the node is visited, then the 
//              left subtree is traversed, and finally the right subtree is 
//              traversed.
template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

//Function:     postorderTraversal() const
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to traverse a binary tree in 
//              "post-order". This means that the left subtree is traversed, 
//              then the right subtree is traversed, then finally the node is 
//              visited.
template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

//Function:     treeHeight() const
//
//Inputs:       None
//Outputs:      Return type int
//Purpose:      The purpose of this function is to return the height of the
//              binary tree.
template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

//Function:     treeNodeCount() const
//
//Inputs:       None
//Outputs:      Return type int
//Purpose:      The purpose of this function is to return the number of nodes
//              in a binary tree
template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

//Function:     treeLeavesCount() const
//
//Inputs:       None
//Outputs:      Return type int
//Purpose:      The purpose of this function is to return the number of leaves
//              in the binary tree.
template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
   return leavesCount(root); 
}

//Function:     destroyTree()
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to destroy the current
//              binary tree.
template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

//Function:     COPY CONSTRUCTOR
//
//Inputs:       const binaryTreeType<elemType> &otherTree
//Outputs:      None
//Purpose:      The purpose of this function is to define the copy 
//              constructor for the binaryTreeType class.
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType> &otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

//Function:     DEFAULT CONSTRUCTOR
//
//Inputs:       None
//Outputs:      None
//Purpose:      The purpose of this function is to define the constructor for 
//              the binaryTreeType class.
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

//Function:     DESTRUCTOR
//
//Inputs:       None
//Outputs:      None
//Purpose:      The purpose of this function is to define the destructor for 
//              the binaryTreeType class.
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

//--------------------------------------------------------------------------//
//Private member functions

//Function      inorder(binaryTreeNode<elemType> *p) const
//
//Inputs:       binaryTreeNode<elemType> *p
//Outputs:      Return type void
//Purpose:      The purpose of this function is to traverse a binary 
//              tree "in-order". This means that the left tree is traversed,
//              the node is visited, then the right tree is traversed.
template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

//Function      preorder(binaryTreeNode<elemType> *p) const
//
//Inputs:       binaryTreeNode<elemType> *p
//Outputs:      Return type void
//Purpose:      The purpose of this function is to traverse a binary tree 
//              in "pre-order" This means that the node is visited, then the 
//              left subtree is traversed, and finally the right subtree is 
//              traversed.
template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

//Function      postorder(binaryTreeNode<elemType *p)
//
//Inputs:       binaryTreeNode<elemType> *p
//Outputs:      Return type void
//Purpose:      The purpose of this function is to traverse a binary tree in 
//              "post-order". This means that the left subtree is traversed, 
//              then the right subtree is traversed, then finally the node is 
//              visited.
template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

//Function      height(binaryTreeNode<elemType> *p) const
//
//Inputs:       binaryTreeNode<elemType> *p
//Outputs:      Return type int
//Purpose:      The purpose of this function is to return the "height" of the
//              binary tree. The height is the maximum number of branches
//              from the root node to the leaf node.
template<class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

//Function      max(int x, int y) const
//
//Inputs:       int x, int y
//Outputs:      Return type int
//Purpose:      The purpose of this function is to return the largest integer.
//              Two integers are passed in as formal arguments to the
//              function (x and y). The function will then return the larger
//              of the two.
template <class elemType>
elemType binaryTreeType<elemType>::max(elemType x, elemType y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

//Function      copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
//                       binaryTreeNode<elemType>* otherTreeRoot)
//
//Inputs:       binaryTreeNode<elemType>* &copiedTreeRoot, 
//              binaryTreeNode<elemType>* otherTreeRoot
//Outputs:      Return type void
//Purpose:      The purpose of this function is to make a copy of a binary
//              tree. The binary tree: binaryTreeNode<elemType>* otherTreeRoot
//              has its entire binary tree copied into:
//              binaryTreeNode,elemtype>* copiedTreeRoot
//              Both of these elements are nodes, which are copied recursively
//              The function essentially performs a preorder traversal to
//              copy the binary tree into another that is returned by
//              reference. 
template <class elemType>
void binaryTreeType<elemType>::copyTree
    (binaryTreeNode<elemType>* &copiedTreeRoot,
     binaryTreeNode<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}
//--------------------------------------------------------------------------//



#endif /* BINARYTREETYPE_H */

