#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class AVLTree{
    public:
        class AVLNode{
            public:
                AVLNode(T const &value){
                    node_value = value;
                    parent_node = nullptr;
                    left_child = nullptr;
                    right_child = nullptr;
                    node_height = 1;
                };  //constructor for AVLNode which creates a leaf node with a value of type T but no parent or children
                
                T value() const{
                    return node_value;
                };        //getter for node value
                
                int height(){
                    return node_height;
                };   //getter for height of the AVLTree (do not recalculate by recursion)
                // void updateHeight(){
                //     if(this == nullptr){
                //         return 0;
                //     }
                //     else{
                //         int left_height = left_child->height();
                //         int right_height = right_child->height();
                //         if(left_height>right_height){
                //             node_height = 1 + left_height;
                //         }
                //         else{
                //             node_height = 1 + right_height;
                //         }
                //         this->node_height = node_height;
                //     }
                // };  //recursively calculate height of the AVLTree   
                
                AVLNode* parent() const{
                    return parent_node;
                };     //getter for parent pointer
                
                AVLNode* left() const{
                    return left_child;
                };   //getter for left_child pointer
                
                AVLNode* right() const{
                    return right_child;
                };  //getter for right_child pointer
                
                bool empty() const{
                    return (this == nullptr);
                };     //return true if the node is null
                
                bool isLeaf() const{
                    return (left_child == nullptr && right_child == nullptr);
                };        //return true if node has no children (both left and right is null), otherwise false
                
                bool isRoot() const{
                    return parent_node == nullptr;
                };        //return true if node has no parent, otherwise false
                
                T front() const{
                    if(empty()){
                        return -1;
                    }
                    const AVLNode* current_node = this;
                    while(current_node->left() != nullptr){
                        current_node = current_node->left_child;
                    }
                    return current_node->node_value;
                };    //find the minimum element in the AVLTree
                
                T back() const{
                    if(empty()){
                        return -1;
                    }
                    const AVLNode* current_node = this;
                    while(current_node->right_child != nullptr){
                        current_node = current_node->right_child;
                    }
                    return current_node->node_value;
                };    //find the maximum element in the AVLTree
                
                bool find(T const &value, AVLNode* &node){
                    if(node->empty()){
                        return false;
                    }
                    else if(value == node->value()){
                        return true;
                    }
                    else if(value < node->value()){
                        return find(value, node->left_child);
                    }
                    else{
                        return find(value, node->right_child);
                    }
                };     //return true if the node with value of type T exists in the AVLTree
                
                bool insert(T const &value, AVLNode* &node){
                    if(node->empty()){
                        node = new AVLNode(value);
                        return true;
                    }
                    else if(value == node->value()){
                        return false;
                    }
                    else if (value < node->value()){
                        return insert(value, node->left_child);
                    }
                    else{
                        return insert(value, node->right_child);
                    }
                    node->node_height = 1+ max(node->left_child->height(), node->right_child->height());
                    balance(node);
                };     //traverse to the appropriate location of the AVLTree and create new AVLNode with value of type T, and subsequently update height and balance the tree after insertion
                
                bool erase(T const &value, AVLNode* &node){
                    if(node->empty()){
                        return false;
                    }
                    else if(value == node->value()){
                        if(node->isLeaf()){
                            delete node;
                            node = nullptr;
                            return true;
                        }
                        else if(node->left() == nullptr){
                            AVLNode* temp = node;
                            node = node->right();
                            delete temp;
                            return true;
                        }
                        else if(node->right() == nullptr){
                            AVLNode* temp = node;
                            node = node->left();
                            delete temp;
                            return true;
                        }
                        else{
                            node->node_value = node->right()->front();
                            erase(node->node_value, node->right());
                        }
                    }
                    else if(value < node->value()){
                        return erase(value, node->left());
                    }
                    else{
                        return erase(value, node->right());
                    }

                    node->node_height = 1 + max(node->left()->height(), node->right()->height());
                    balance(node);                
                };     //delete the node having value of type T from the AVLTree (do not clear subtree), and subsequently update height and balance the tree after deletion
                
                void balance(AVLNode* &node){
                    if(node->empty()){
                        return;
                    }
                    int balance = balanceFactor(node);
                    if(balance > 1){
                        if(balanceFactor(node->left()) < 0){
                            node->left_child = leftRotate(node->left());
                        }
                        node = rightRotate(node);
                    }
                    else if(balance < -1){
                        if(balanceFactor(node->right()) > 0){
                            node->right_child = rightRotate(node->right());
                        }
                        node = leftRotate(node);
                    }
                    
                }; //check the difference of left subtree height and right subtree height and perform appropriate rotation
                
                int balanceFactor(AVLNode* node){
                    if(node->empty()){
                        return 0;
                    }
                    return node->left()->height() - node->right()->height();
                };  //return the difference of left subtree height and right subtree height
                
                AVLNode* rightRotate(AVLNode* y){
                    AVLNode* x = y->left();
                    AVLNode* temp = x->right();

                    x->right_child = y;
                    y->left_child = temp;

                    y->node_height = 1 + max(y->left()->height(), y->right()->height());
                    x->node_height = 1 + max(x->left()->height(), x->right()->height());

                    return x;
                }; //perform right rotation

                AVLNode* leftRotate(AVLNode* x){
                    AVLNode* y = x->right();
                    AVLNode* temp = y->left();

                    y->left_child = x;
                    x->right_child = temp;

                    y->node_height = 1+ max(y->left()->height(), y->right()->height());
                    x->node_height = 1 + max(x->left()->height(), x->right()->height());

                    return y;
                }; //perform left rotation
            
            private:
                T node_value;
                int node_height;
                AVLNode* parent_node;
                AVLNode* left_child;
                AVLNode* right_child;
        };

        AVLTree(){
            root_node = nullptr;
        };   //constructor for AVLTree which creates an empty tree
        
        AVLNode* root() const{
            return root_node;
        };   //getter for root_node pointer
        
        T rootValue() const{
            return root_node->value();
        };    //getter for root_node value
        
        bool empty() const{
            return root_node->empty();
        };    //return true if the AVLTree has no nodes, otherwise false

        int height(){
            return root_node->height();
        };   //simply call the height function of the AVLNode class
        T front() const{
            if(empty()){
                return -1;
            }
            return root_node->front();
        };    //handle any exceptions, then simply call the front function of the AVLNode class
        T back() const{
            if(empty()){
                return -1;
            }
            return root_node->back();
        };    //handle any exceptions, then simply call the back function of the AVLNode class


        bool find(T const &value){
            return root_node->find(value, root_node);
        };  //simply call the find function of the AVLNode class
        bool insert(T const &value){
            return root_node->insert(value, root_node);
        };  //simply call the insert function of the AVLNode class
        bool erase(T const &value){
            return root_node->erase(value, root_node);
        }; //simply call the erase function of the AVLNode class
        void level_order_traversal(){
            if(root_node->empty()){
                return;
            }
            std::queue<AVLNode*> node_queue;
            node_queue.push(root_node);
            while(!node_queue.empty()){
                AVLNode* current_node = node_queue.front();
                node_queue.pop();
                std::cout<<current_node->value()<<" ";
                if(current_node->left() != nullptr){
                    node_queue.push(current_node->left());
                }
                if(current_node->right() != nullptr){
                    node_queue.push(current_node->right());
                }
            }
        };    //print the whole AVLTree recursively in the Breadth-First order


    private:
        AVLNode* root_node;

};
