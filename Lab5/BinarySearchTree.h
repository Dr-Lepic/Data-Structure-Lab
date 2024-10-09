template <typename T>
class BinarySearchTree{
    public:
        class BinarySearchNode{
            public:
                BinarySearchNode(T const &);  //constructor for BinarySearchNode which creates a leaf node with a value of type T but no parent or children
                T value() const;        //getter for node value
                BinarySearchNode* parent() const;     //getter for parent pointer
                BinarySearchNode* left() const;   //getter for left_child pointer
                BinarySearchNode* right() const;  //getter for right_child pointer
                bool empty() const;     //return true if the node is null
                bool isLeaf() const;        //return true if node has no children (both left and right is null), otherwise false
                bool isRoot() const;        //return true if node has no parent, otherwise false
                int size();     //recursively calculate total number of nodes in the BST
                int height();   //recursively calculate height of the BST
                T front() const;    //find the minimum element in the BST
                T back() const;    //find the maximum element in the BST
                bool find(T const &,  BinarySearchNode* &);     //return true if the node with value of type T exists in the BST
                bool insert(T const &, BinarySearchNode* &);     //traverse to the appropriate location of the BST and create new BinarySearchNode with value of type T
                bool erase(T const &, BinarySearchNode* &);     //delete the node having value of type T from the BST (do not clear subtree)


            private:
                T node_value;
                BinarySearchNode* parent_node;
                BinarySearchNode* left_child;
                BinarySearchNode* right_child;
        };

        BinarySearchTree();   //constructor for BinarySearchTree which creates an empty tree
        BinarySearchNode* root() const;   //getter for root_node pointer
        T rootValue() const;    //getter for root_node value
        bool empty() const;    //return true if the BST has no nodes, otherwise false

        int size();     //simply call the size function of the BinarySearchNode class
        int height();   //simply call the height function of the BinarySearchNode class
        T front() const;    //handle any exceptions, then simply call the front function of the BinarySearchNode class
        T back() const;    //handle any exceptions, then simply call the back function of the BinarySearchNode class

	
	bool find(T const &);  //simply call the find function of the BinarySearchNode class
        bool insert(T const &);  //simply call the insert function of the BinarySearchNode class
        bool erase(T const &); //simply call the erase function of the BinarySearchNode class
        void level_order_traversal();    //print the whole BST recursively in the Breadth-First order


    private:
        BinarySearchNode* root_node;

};
