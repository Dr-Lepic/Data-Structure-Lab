#include<bits/stdc++.h>
#include "SingleList.h"

SingleList::Node::Node(char a)
{
    this->node_value = a;
    this->next_node = nullptr;
}

char SingleList::Node::value() const
{
    return node_value;
}

SingleList::Node *SingleList::Node::next() const
{
    return next_node;
}

SingleList::SingleList()
{
    this->head = nullptr;
    this->size = 0;
}

bool SingleList::empty() const
{
    return (head->next() == nullptr);
}

char SingleList::front() const
{
    return head->value();
}

SingleList::Node *SingleList::begin() const
{
    return head;
}

SingleList::Node *SingleList::end() const
{
    return nullptr;
}

void SingleList::push_front(char data)
{
  Node *n1 = new Node(data);
  n1 = head->next();
  head = n1;
}

char SingleList::pop_front()
{
    Node *n1 = head->next();
    char  data = n1->value();
    head = n1->next();
    delete n1;
    return data;
}
