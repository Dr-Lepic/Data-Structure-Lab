template <typename T>
class BinaryHeap{
    public:
        BinaryHeap(){
            currentsize = 0;
        };   //constructor for BinaryHeap which creates an empty heap

        bool empty() const{
            return currentsize == 0;
        };    //return true if the heap has no nodes, otherwise false

        int size() const{
            return currentsize;
        }; //return the currentsize of the heap

        T top() const{
            return arr[0];
        };    //getter for min/max value


        bool insert(T const &value){
            arr.push_back(value);
            percolateUp(currentsize);
            currentsize++;
            return true;
        }; //insert the value passed as parameter into the end of the heap and percolate up to its appropriate location, also update currentsize

        bool erase(){
            if(currentsize == 0){
                return false;
            }
            arr[0] = arr[currentsize - 1];
            arr.pop_back();
            currentsize--;
            percolateDown(0);
            return true;
        }; //delete the highest priority (top) element from the heap and fill the hole with the last element of the heap and percolate down, also update currentsize

        // Task 2
        void decrease_key(int p, int k){
            arr[p] -= k;
            percolateDown(p);
        };    //decrease the value at  p-th position by an amount of k and makes necessary changes
        void increase_key(int p, int k){
            arr[p] += k;
            percolateUp(p);
        };    //increase the value at  p-th position by an amount of k and makes necessary changes
        

    private:
        int currentsize;
        std::vector<T> arr;

        void percolateUp(int current){
            //int current = currentsize - 1;
            while(current > 0 && arr[((current+1)/2) - 1] < arr[current]){
                std::swap(arr[current], arr[((current+1)/2) - 1]);
                current = ((current+1)/2) -1;
            }
        }; //private functions to be called by other functions like insert and delete, should not be called from outside the class
        void percolateDown(int current){
            //int current = 0;
            while(current*2 + 1 < currentsize){
                int left = current*2 + 1;
                int right = current*2 + 2;
                int smaller = left;
                if(right < currentsize && arr[right] < arr[left]){
                    smaller = right;
                }
                if(arr[current] < arr[smaller]){
                    std::swap(arr[current], arr[smaller]);
                    current = smaller;
                }
                else{
                    break;
                }
            }
        };   //private functions to be called by other functions like insert and delete, should not be called from outside the class

};
