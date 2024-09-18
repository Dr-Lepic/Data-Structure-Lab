/*
ID: 220042162
Data Struct Lab 2
*/

#pragma once
#include "single_linked_list.h"

template <typename T> class my_stack
{
  private:
    SingleLinkedList<T> list;

  public:

    bool is_empty() const
    {
        return list.is_empty();
    }

    void push(const T &val)
    {
        list.push_front(val);
    }

    T top() const
    {
        return list.get_front();
    }

    void pop()
    {
        list.pop_front();
    }
};