//
// Created by _edd.ie_ on 25/05/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <string>
#include <sstream>

/**
 * LinkedList class
 * @author _edd.ie_
 */
class LinkedList
{
    struct Node
    {
        explicit Node(const int data)
        {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }

        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    explicit LinkedList(const int data)
    {
        head = new Node(data);
        tail = head;
    }

    /**
     * Add a element to the end of the list
     * @param data value to be adde to list
     * @return true if added
     */
    bool add(const int data)
    {
        if(head == nullptr)
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            if(tail == head)
            {
                tail = new Node(data);
                head->next = tail;
                tail->prev = head;
            }
            else
            {
                tail->next = new Node(data);
                tail->next->prev = tail;
                tail = tail->next;
            }
        }
        return true;
    }

    /**
     * Removes the last element
     * @exception invalid_argument If list is empty
     * @return The removed element
     */
    int remove()
    {
        int element;
        if(head == nullptr)
        {
            throw std::invalid_argument("List is empty!");
        }
        if(head == tail)
        {
            element = head->data;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            element = tail->data;
            tail = tail->prev;
            tail->next = nullptr;
        }
        return element;
    }

    /**
     * Removes the first element
     * @exception invalid_argument If list is empty
     * @return The removed element
     */
    int removeFirst()
    {
        int element;
        if(head == nullptr)
        {
            throw std::invalid_argument("List is empty!");
        }
        if(head == tail)
        {
            element = head->data;
            head = nullptr;
            tail = nullptr;
        }
        else if(head->next == tail)
        {
            element = head->data;
            tail->prev = nullptr;
            head = tail;
        }
        else
        {
            element = head->data;
            head = head->next;
            head->prev = nullptr;
        }
        return element;
    }

    /**
     *
     * @return Textual representation of the List
     */
    std::string toString()
    {
        std::string text;
        const Node* holder = head;


        while (holder != nullptr)
        {
            std::stringstream ss;
            ss << holder->data;
            text +=  ss.str()+"\n";
            holder = holder->next;
        }
        return text;
    }



};

#endif //LINKEDLIST_H
