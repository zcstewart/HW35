/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nodeType.h
 * Author: scooby
 *
 * Created on April 24, 2017, 1:43 PM
 */

#ifndef NODETYPE_H
#define NODETYPE_H

template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode <elemType> *lLink;
    binaryTreeNode <elemType> *rLink;
};

#endif /* NODETYPE_H */

