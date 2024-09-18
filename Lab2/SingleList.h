#include<iostream>
using namespace std;

class SingleList{
    public:
        class Node{
            public:
                Node(char = ' ');
                Node();
                char value() const;
                Node* next() const;


            
                char node_value;
                Node* next_node;
        };

        SingleList();
        bool empty() const;
        char front() const;
        Node* begin() const;
        Node* end() const;
        void push_front(char);
        char pop_front();
        void show();


    private:
        Node* head;
        int size;

};

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
    return (head == nullptr);
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
  n1->next_node = head;
  head = n1;
}

char SingleList::pop_front()
{
    Node *n1 = head;
    char  data = n1->value();
    head = head->next();
    delete n1;
    return data;
}

void SingleList::show()
{
    Node *n1 = head;
    while(n1 != nullptr){
        cout<<n1->value()<<" ";
        n1 = n1->next();
    }
}
