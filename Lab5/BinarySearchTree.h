#include<queue>
#include<iostream>
using namespace std;
template <typename T>

class BinarySearchTree{
    public:
        class BinarySearchNode{
            public:
                //constructor for BinarySearchNode which creates a leaf node with a value of type T but no parent or children
                BinarySearchNode(T const & value){
                    node_value = value;
                    parent_node = nullptr;
                    left_child = nullptr;
                    right_child = nullptr;
                }  

                //getter for node value
                T value() const{
                    return node_value;
                }  

                //getter for parent pointer
                BinarySearchNode* parent() const{
                    return parent_node;
                }    

                //getter for left_child pointer
                BinarySearchNode* left() const{
                    return left_child;
                }   

                 //getter for right_child pointer
                BinarySearchNode* right() const{
                    return right_child;
                } 

                 //return true if the node is null
                bool empty() const{
                    return (this == nullptr);
                }    

                //return true if node has no children (both left and right is null), otherwise false
                bool isLeaf() const{
                    return (left_child == nullptr && right_child == nullptr);
                }    

                 //return true if node has no parent, otherwise false
                bool isRoot() const{
                    return (parent_node == nullptr);
                }     

                //recursively calculate total number of nodes in the BST
                int size(){
                    if(this == nullptr){
                        return 0;
                    }
                    else{
                        return 1 + left_child->size() + right_child->size();
                    }
                }     
                
                //recursively calculate height of the BST
                int height(){
                    if(this == nullptr){
                        return -1;
                    }
                    return 1 + std::max(left_child->height(), right_child->height());
                }   
                
                //find the minimum element in the BST
                T front() const{
                    if(empty()){
                        return -1;
                    }

                    const BinarySearchNode* current_node = this;
                    while(current_node->left() != nullptr){
                        current_node = current_node->left_child;
                    }
                    return current_node->node_value;
                };    
                
                //find the maximum element in the BST
                T back() const{
                    if(empty()){
                        return -1;
                    }
                    BinarySearchNode* current_node = this;
                    while(current_node->right_child != nullptr){
                        current_node = current_node->right_child;
                    }
                    return current_node->node_value;
                }    
                
                //return true if the node with value of type T exists in the BST
                bool find(T const &value,  BinarySearchNode* &node){
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
                    
                };     
                
                //traverse to the appropriate location of the BST and create new BinarySearchNode with value of type T
                bool insert(T const &value, BinarySearchNode* &node){
                    if(node->empty()){
                        node = new BinarySearchNode(value);
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
                    
                };     
                
                //delete the node having value of type T from the BST (do not clear subtree)
                bool erase(T const &value, BinarySearchNode* &node){
                    if(node->empty()){
                        return false;
                    }
                    else if(value == node->value()){
                        if(node->isLeaf()){
                            delete node;
                            node = nullptr;
                        }
                        else if(node->left_child == nullptr){
                            BinarySearchNode* temp = node;
                            node = node->right_child;
                            delete temp;
                        }
                        else if(node->right_child == nullptr){
                            BinarySearchNode* temp = node;
                            node = node->left_child;
                            delete temp;
                        }
                        else{
                            node->node_value = node->right_child->front();
                            return erase(node->node_value, node->right_child);
                        }
                    }
                    else if(value < node->value()){
                        return erase(value, node->left_child);
                    }
                    else{
                        return erase(value, node->right_child);
                    }
                };     
                

            private:
                T node_value;
                BinarySearchNode* parent_node;
                BinarySearchNode* left_child;
                BinarySearchNode* right_child;
        };

        //constructor for BinarySearchTree which creates an empty tree
        BinarySearchTree(){
            root_node = nullptr;
        };   
        //getter for root_node pointer
        BinarySearchNode* root() const{
            return root_node;
        };   
        //getter for root_node value
        T rootValue() const{
            return root_node->value();
        };    
        //return true if the BST has no nodes, otherwise false
        bool empty() const{
            return root_node->empty();
        };    

        //simply call the size function of the BinarySearchNode class
        int size(){
            return root_node->size();
        };     
        //simply call the height function of the BinarySearchNode class
        int height(){
            return root_node->height();
        };   
        //handle any exceptions, then simply call the front function of the BinarySearchNode class
        T front() const{
            return root_node->front();
        };    
        //handle any exceptions, then simply call the back function of the BinarySearchNode class
        T back() const{
            return root_node->back();
        };    

	
        //simply call the find function of the BinarySearchNode class
	    bool find(T const &value){
            return root_node->find(value, root_node);
        };  
        //simply call the insert function of the BinarySearchNode class
        bool insert(T const &value){
            return root_node->insert(value, root_node);
        };  
        //simply call the erase function of the BinarySearchNode class
        bool erase(T const &value){
            return root_node->erase(value, root_node);
        }; 
        //print the whole BST recursively in the Breadth-First order
        void level_order_traversal(){
            if(root_node->empty()){
                return;
            }
            std::queue<BinarySearchNode*> node_queue;
            node_queue.push(root_node);
            while(!node_queue.empty()){
                BinarySearchNode* current_node = node_queue.front();
                node_queue.pop();
                std::cout<<current_node->value()<<" ";
                if(current_node->left() != nullptr){
                    node_queue.push(current_node->left());
                }
                if(current_node->right() != nullptr){
                    node_queue.push(current_node->right());
                }
            }
        };    


    private:
        BinarySearchNode* root_node;

};
