#include<bits/stdc++.h>
using namespace std;


class BinarySearchTree{
    public:
        class BinarySearchNode{
            public:
                //constructor for BinarySearchNode which creates a leaf node with a value of type T but no parent or children
                BinarySearchNode(int const & value){
                    node_value = value;
                    parent_node = nullptr;
                    left_child = nullptr;
                    right_child = nullptr;
                }  

                //getter for node value
                int value() const{
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

                int depth(){
                    if(this == nullptr){
                        return 0;
                    }
                    return 1 + max(left_child->depth(), right_child->depth());
                }
                
                //find the minimum element in the BST
                int front() const{
                    if(empty()){
                        return -1;
                    }

                    const BinarySearchNode* current_node = this;
                    while(current_node->left() != nullptr){
                        current_node = current_node->left_child;
                    }
                    return current_node->node_value;
                };    
                 
                
                //traverse to the appropriate location of the BST and create new BinarySearchNode with value of type T
                bool insert(int const &value, BinarySearchNode* &node){
                    if(node->empty()){
                        node = new BinarySearchNode(value);
                        return true;
                    }
                    else if(value == node->value()){
                        return false;
                    }
                    else if (value <= node->value()){
                        return insert(value, node->left_child);
                    }
                    else{
                        return insert(value, node->right_child);
                    }
                    
                };          
                

            private:
                int node_value;
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
        int rootValue() const{
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
        int depth(){
            return root_node->depth();
        }
                

	  
        //simply call the insert function of the BinarySearchNode class
        bool insert(int const &value){
            return root_node->insert(value, root_node);
        };  
     
         


    private:
        BinarySearchNode* root_node;

};

int main(){
    int a;
    BinarySearchTree tree;
    while(true){
        cin>>a;
        if(a == -1){
            break;
        }
        tree.insert(a);
    }

    cout<<tree.depth() - 1;
    
}