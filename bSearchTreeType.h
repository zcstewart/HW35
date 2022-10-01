//Homework XX

/* 
 * Filename:        bSearchTreeType.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 24, 2017, 2:09 PM
 */

#ifndef BSEARCHTREETYPE_H
#define BSEARCHTREETYPE_H

//Preprocessor Directives
#include <cstdlib>
#include "binaryTreeType.h"
#include "binaryTreeNode.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
    bool search(const elemType &searchItem) const;
    void insert(const elemType &insertItem);
    void deleteNode(const elemType &deleteItem);
    // Calls insertPost() to perform a postorder traversal of a  
    // binary search tree and copies the nodes into a new tree 
    void insertPostorder(bSearchTreeType<elemType> &otherTree);
    // Calls insertPre() to perform a preorder traversal of a  
    // binary search tree and copies the nodes into a new tree
    void insertPreorder(bSearchTreeType<elemType> &otherTree);
    bSearchTreeType();
    ~bSearchTreeType();
private:
    void deleteFromTree(binaryTreeNode<elemType>* &p);
    // Performs the postorder traversal of otherTree and  
    // inserts the nodes into a new tree 
    void insertPost(bSearchTreeType<elemType> &otherTree, binaryTreeNode<elemType> *p);
    // Performs the preorder traversal of otherTree and
    // inserts the nodes into a new tree 
    void insertPre(bSearchTreeType<elemType> &otherTree, binaryTreeNode<elemType> *p);
};

//--------------------------------------------------------------------------//

//Function:     search(const elemType &searchItem) const
//
//Inputs:       const elemType &searchItem
//Outputs:      Return type bool
//Purpose:      
template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType &searchItem) const
{
    binaryTreeNode<elemType> *current;
    bool found = false;
    if(this->root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else
    {
        current = this->root;
        while(current != nullptr && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
    }//end else
    return found;
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType &insertItem)
{
    binaryTreeNode<elemType> *current; //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *newNode; //pointer to create the node
    newNode = new binaryTreeNode<elemType>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    if (this->root == nullptr)
        this->root = newNode;
    else
    {
        current = this->root;
        while (current != nullptr)
        {
            trailCurrent = current;
            if (current->info == insertItem)
            {
                cout << "The item to be inserted is already ";
                cout << "in the tree -- duplicates are not "
                << "allowed." << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
        if (trailCurrent->info > insertItem)
        trailCurrent->lLink = newNode;
        else
        trailCurrent->rLink = newNode;
    }
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType &deleteItem)
{
    binaryTreeNode<elemType> *current; //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    bool found = false;
    if (this->root == nullptr)
        cout << "Cannot delete from an empty tree." << endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;
        while (current != nullptr && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                if (current->info > deleteItem)
                    current = current->lLink;
                else
                    current = current->rLink;
            }
        }//end while
        if (current == nullptr)
            cout << "The item to be deleted is not in the tree." << endl;
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        else
            cout << "The item to be deleted is not in the tree." << endl;
    }
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template <class elemType>
void bSearchTreeType<elemType>::insertPostorder(bSearchTreeType<elemType> &otherTree)
{
    binaryTreeNode<elemType> *p = new binaryTreeNode<elemType>;
    p = this->root;
    insertPost(otherTree, p);
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template <class elemType>
void bSearchTreeType<elemType>::insertPreorder(bSearchTreeType<elemType> &otherTree)
{
    binaryTreeNode<elemType> *p = new binaryTreeNode<elemType>;
    p = this->root;
    insertPre(otherTree, p);
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(binaryTreeNode<elemType>* &p)
{
    binaryTreeNode<elemType> *current; //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *temp;
    //pointer to delete the node
    if (p == nullptr)
        cout << "Error: The node to be deleted does not exist."
        << endl;
    else if (p->lLink == nullptr && p->rLink == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lLink == nullptr)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = nullptr;
        while (current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }//end while
        p->info = current->info;
        if (trailCurrent == nullptr) //current did not move;
            //current == p->lLink; adjust p
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;
        delete current;
    }//end else
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template <class elemType>
void bSearchTreeType<elemType>::insertPost(bSearchTreeType<elemType> &otherTree, binaryTreeNode<elemType> *p)
{
    if (p != nullptr)
    {
        insertPost(otherTree, p->lLink);
        insertPost(otherTree, p->rLink);
        otherTree->insert(p->info);
    }
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template <class elemType>
void bSearchTreeType<elemType>::insertPre(bSearchTreeType<elemType> &otherTree, binaryTreeNode<elemType> *p)
{
    if (p != nullptr)
    {
        otherTree->insert(p->info);
        insertPre(otherTree, p->lLink);
        insertPre(otherTree, p->rLink);
    }
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      
template<class elemType>
bSearchTreeType<elemType>::bSearchTreeType()
{
    this->root = nullptr;
}
 
template <class elemType>
bSearchTreeType<elemType>::~bSearchTreeType()
{
    binaryTreeType<elemType>::destroy(this->root);
}

//--------------------------------------------------------------------------//

#endif /* BSEARCHTREETYPE_H */

