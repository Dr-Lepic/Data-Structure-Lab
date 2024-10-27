#include<iostream>
using namespace std;

template <typename T>
class BinaryTree{
    public:
        class BinaryNode{
            public:
                BinaryNode(T const &value){
                    node_value = value;
                    parent = nullptr;
                    left = nullptr;
                    right = nullptr;
                }
                  
                T value() const{         
                    return node_value;
                }

                BinaryNode* getParent() const{     
                    return parent;
                }

                BinaryNode* getLeft() const{
                    return left;
                }
                   
                BinaryNode* getRight() const{
                    return right;
                }

                bool isLeaf() const{
                    return (left == nullptr) && (right == nullptr);
                }

                bool isRoot() const{
                    return parent == nullptr;
                }

                void insertLeft(T value){
                    left = new BinaryNode(value);
                    left->parent = this;
                }     

                void insertRight(T value){
                    right = new BinaryNode(value);
                    right->parent = this;
                }    

                

            private:
                T node_value;
                BinaryNode* parent;
                BinaryNode* left;
                BinaryNode* right;
        };

        BinaryTree(){
            root = nullptr;
        }   

        void createRoot(T value){
            root = new BinaryNode(value);
            
        }  

        BinaryNode* getRoot() const{
            return root;
        }   
        T rootValue() const{
            return root->value();
        }    
        bool empty() const{
            return root == nullptr;
        }    

	
        //Task2
        void clear(BinaryNode* node){
            if(node == nullptr){
                return;
            }
            clear(node->getLeft());
            clear(node->getRight());
            delete node;
            
        }   //recursively delete all children and also the current node itself
        

        //Task3
        int size(BinaryNode* node) const{
            if(node == nullptr){
                return 0;
            }
            return 1 + size(node->getLeft()) + size(node->getRight());

        } 

        int size() const{
            return size(root);
        }

        int height(BinaryNode* node) const{
            if(node == nullptr){
                return -1;
            }
            return 1 + max(height(node->getLeft()), height(node->getRight())) ;
        }

        int height() const{
            return height(root);
        }  
        

        //Task 4
        void DFS_traversal(BinaryNode* node) const {
        if (!node) return;

            cout << node->value() << " ";

   
            DFS_traversal(node->getLeft());
            DFS_traversal(node->getRight());
        }

        void DFS_traversal() const {
            DFS_traversal(root);
        }
        


    private:
        BinaryNode* root;

};



// int main(){
//     return 0;
// }
