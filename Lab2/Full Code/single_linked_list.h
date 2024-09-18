#pragma once
#include <iostream>
#include <stdexcept>

#include "node.h"

using namespace std;

template <typename T> class SingleLinkedList
{
  private:
    int size;
    Node<T> *head;

  public:
    SingleLinkedList() : size(0), head(nullptr)
    {
    }

    ~SingleLinkedList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    bool is_empty() const
    {
        return (size == 0);
    }

    void push_front(const T &val)
    {
        Node<T> *new_node = new Node<T>(val);
        new_node->next = head;
        head = new_node;
        size++;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T get_front() const
    {
        if (head == nullptr) {
            throw underflow_error("list empty");
        }

        return head->data;
    }

    void push_back(const T &val)
    {
        Node<T> *new_node = new Node<T>(val);

        if (head == nullptr)
        {
            head->next = new_node;
            size++;
        }

        Node<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
        size++;
    }

    void print() const
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};