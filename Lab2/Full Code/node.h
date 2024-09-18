/*
ID: 220042162
Data Struct Lab 2
*/

#pragma once
template <typename T> class Node
{
  public:
    T data;
    Node *next;

    Node(const T &val) : data(val), next(nullptr)
    {
    }

};