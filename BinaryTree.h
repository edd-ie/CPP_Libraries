//
// Created by _edd.ie_ on 26/05/2024.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

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

    /**
     * Node finder
     * @param node Starting node
     * @param value The value to be found
     * @param action what to do with the result (find = return node, remove = return parent node)
     * @return found node
     */
    Node* nodeFinder(Node* node, const int value, const std::string& action = "find")
    {
        Node* found = nullptr;

        if(value < node->data && node->left != nullptr)
        {
            if(node->left->data == value)
            {
                found = (action =="find")? node->left : node;
            }
            else
            {
                found = nodeFinder(node->left, value, action);
            }
        }
        else if(node->right != nullptr)
        {
            if(node->right->data == value)
            {
                found = (action =="find")? node->right : node;
            }
            else
            {
                found = nodeFinder(node->right, value, action);
            }
        }


        return found;
    }

    //TODO a function to shift a removed nodes children to a different branch
    bool removeNode(Node* node, const std::string& side)
    {
        bool removed = false;

        if(node != nullptr)
        {
            Node* toBeRemoved = (side == "left") ? node->left : node->right;
            Node* replacement = toBeRemoved->left;

            // if(replacement != nullptr)
            // {
            //     while (replacement->left != nullptr)
            //     {
            //         replacement = replacement->left;
            //     }
            //     (side == "left")?node->left = replacement : node->right = replacement;
            //
            //     if(toBeRemoved->left != replacement)
            //     {
            //         replacement->left = toBeRemoved->left;
            //     }
            //
            //     replacement->right = toBeRemoved->right;
            // }
        }



        return removed;
    }

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
        Node* current = root;
        if(root!= nullptr)
        {
            //Todo: recursive call to the private removal function which assigns return to removed variable
        }


        return removed;
    }


};

#endif //BINARYTREE_H
