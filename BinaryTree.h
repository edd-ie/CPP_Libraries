//
// Created by _edd.ie_ on 26/05/2024.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

/**
 * BinaryTree class
 * @author _edd.ie_
 */
class BinaryTree
{
    struct Node
    {
        int data;
        Node* left;
        Node* right;

        explicit Node(const int data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    //TODO A function theat take a node and finds if it's children are the one to be removed
    // Returns a boolean if found and removed

    //TODO a function to shift a removed nodes children to a different branch

public:
    /**
     * Constructor for The BinaryTree class
     */
    BinaryTree()
    {
        root = nullptr;
    }

    /**
     * Constructor for The BinaryTree class
     * @param data value of the root node
     * @overload
     */
    explicit BinaryTree(const int data)
    {
        root = new Node(data);
    }

    /**
     * Insert Nodes to the tree
     * @param data The value to be added to tree
     * @warning Duplicate values will not be added to the tree
     */
    void insert(const int data)
    {
        if(root == nullptr)
        {
            root = new Node(data);
        }
        else
        {
            bool inserted = false;
            Node* current = root;
            while (!inserted)
            {
                if(current->data > data)
                {
                    if(current->left == nullptr)
                    {
                        current->left = new Node(data);
                        inserted = true;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else if(current->data < data)
                {
                    if(current->right == nullptr)
                    {
                        current->right = new Node(data);
                        inserted = true;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
                else
                {
                    inserted = true;
                }
            }
        }
    }

    /**
     * Remove a value from the tree
     * @param value Data to be removed
     * @return True if found false if not in the tree
     */
    bool remove(const int value)
    {
        bool removed =  false;

        Node* current = root;
        if(root!= nullptr)
        {
            //Todo: recursive call to the private removal function which assigns return to removed variable
        }
        // while(current != nullptr && !removed)
        // {
        //     if(current->data == value)
        //     {
        //         // if(current->left == nullptr && current->right == nullptr)
        //     }
        // }

        return removed;
    }


};

#endif //BINARYTREE_H
