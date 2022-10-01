//HW 35

/* 
 * Filename:        main.cpp
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 24, 2017, 1:40 PM
 */

//Preprocessor Directives
#include <iostream>
#include <cstdlib>
#include "binaryTreeNode.h"
#include "binaryTreeType.h"
#include "bSearchTreeType.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//
//
//Main Function
//
//Inputs:       int argc, char** argv
//Outputs:      int
//
//Purpose:      Main program file. Other necessary files are included here 
//              in order to be run

const int loopFLAG = -999;

int main(int argc, char** argv) 
{
    bSearchTreeType<int>* tree_ONE;
    bSearchTreeType<int>* tree_TWO;
    bSearchTreeType<int>* tree_THREE;
    
    tree_ONE = new bSearchTreeType<int>;
    tree_TWO = new bSearchTreeType<int>;
    tree_THREE = new bSearchTreeType<int>;
    
    int input = 0;
    
    
//    Enter numbers ending with -999 
//68 43 10 56 77 82 61 82 33 56 72 66 99 88 12 6 7 21
// -999 
    
    cout << "Enter numbers ending with -999: " << endl;
    while(input != loopFLAG)
    {
        cin >> input;
        tree_ONE->insert(input);
        tree_TWO->insert(input);
        tree_THREE->insert(input);
    }
    
    
    
    cout << "Tree Nodes in Inorder: " << endl;
    tree_ONE->inorderTraversal();
    cout << endl << endl;
    
    cout << "Tree Nodes in Postorder: " << endl;
    tree_TWO->postorderTraversal();
    cout << endl << endl;
    
    cout << "Tree Nodes in Preorder: " << endl;
    tree_THREE->preorderTraversal();
    cout << endl << endl;
    
    
    
    
    
    cout << "Tree 1 Height: " << tree_ONE->treeHeight() << endl;
    cout << "Tree 1 Leaves: " << tree_ONE->treeLeavesCount() << endl;
    
    cout << "Tree 2 Height: " << tree_TWO->treeHeight() << endl;
    cout << "Tree 2 Leaves: " << tree_TWO->treeLeavesCount() << endl;
    
    cout << "Tree 3 Height: " << tree_THREE->treeHeight() << endl;
    cout << "Tree 3 Leaves: " << tree_THREE->treeLeavesCount() << endl;

    //Terminate program upon successful execution
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

