#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Matrix.h"
#include "MatrixFunctions.h"

unsigned int totalNode = 0;

class BST_Node
{
    public:
        BST_Node* left;
        BST_Node* right;
        Matrix key;
        long value; // Determinant of key matrix is value

        BST_Node();
        BST_Node(Matrix A, long detA);

        bool key_exists(Matrix A);
        long search(Matrix A);
        void insert(Matrix A, long detA);

        BST_Node* getNodePtr(Matrix A);

        long determinantBT(Matrix matr, int sizeOfMatrix, BST_Node* root);

};


BST_Node::BST_Node() // Default constructor. Initialize key value as a 0x0 default empty matrix.
{
    this->key = Matrix(); // You should initialize as empty Matrix();
    this->value = NULL; // Set value as NULL;
    this->left = nullptr;
    this->right = nullptr;
}


BST_Node::BST_Node(Matrix A, long detA) // Constructor with an initialization parameters.
{
    this->key = A;
    this->value = detA;
    this->left = nullptr;
    this->right = nullptr;
}


bool BST_Node::key_exists(Matrix A)
{
    BST_Node* currentNode = this;

    while (currentNode != nullptr && !(currentNode->key == A))
    {
        if (A < (currentNode->key))
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    if (currentNode != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


long BST_Node::search(Matrix A)
{
    BST_Node* currentNode = this;

    while (currentNode != nullptr)
    {
        if (currentNode->key == A)
        {
            return currentNode->value;
        }
        else if (A < currentNode->key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    return NULL;
}


void BST_Node::insert(Matrix A, long detA)
{
    if (!this->key_exists(A))
    {
        BST_Node* currentNode = this;
        BST_Node* newNode = new BST_Node(A, detA);

        while (currentNode != nullptr)
        {
            if (A < currentNode->key)
            {
                if (currentNode->left)
                {
                    currentNode = currentNode->left;
                }
                else
                {
                    currentNode->left = newNode;
                    break;
                }
            }
            else
            {
                if (currentNode->right != nullptr)
                {
                    currentNode = currentNode->right;
                }
                else
                {
                    currentNode->right = newNode;
                    break;
                }
            }
        }
        totalNode += 1;
    }
    else
    {
        this->getNodePtr(A)->value = detA; // Get location of the key inside the tree with getNodePtr() function. Change its value.
    }
}


// If key exists inside the tree, get the location of the key inside tree.
BST_Node* BST_Node::getNodePtr(Matrix A)
{
    BST_Node* currentNode = this;

    while (currentNode != nullptr)
    {
        if (currentNode->key == A)
        {
            return currentNode;
        }
        else if (A < currentNode->key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    return nullptr;
}


long BST_Node::determinantBT(Matrix matr, int sizeOfMatrix, BST_Node* root)
{

    Matrix temp_matr(sizeOfMatrix - 1);

    int i_sub_mtr = 0;
    int j_sub_mtr = 0;
    long det = 0;

    if (root->key_exists(matr))
    {
        return root->search(matr);
    }
    else if (sizeOfMatrix == 1)
    {
        long det = matr.getter(1, 1);
        root->insert(matr, det);
        return det;
    }
    else
    {
        for (int i = 0; i < sizeOfMatrix; i++)
        {
            i_sub_mtr = 0;
            for (int j = 1; j < sizeOfMatrix; j++)
            {
                j_sub_mtr = 0;
                for (int k = 0; k < sizeOfMatrix; k++)
                {
                    if (k == i) // If closed column and travelling column are meet, pass current loop.
                    {
                        continue;
                    }
                    temp_matr.setter(i_sub_mtr + 1, j_sub_mtr + 1, matr.getter(j + 1, k + 1)); // Give index values as incremented by 1. Since minimum number of row || column number should be 1.
                    j_sub_mtr += 1;
                }
                i_sub_mtr += 1;
            }
            det += (long)(determinantBT(temp_matr, sizeOfMatrix - 1, root) * matr.getter(1, i + 1) * pow(-1, i));
        }
        root->insert(matr, det);
        return det;
    }
}

#endif
