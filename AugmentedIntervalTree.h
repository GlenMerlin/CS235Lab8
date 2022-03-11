#include "IntervalTree.h"

using namespace std;
template<class T>
class AugmentedIntervalTree : public IntervalTree {
    public: 
        AugmentedIntervalTree(){
            cout << "AIT Constructor" << endl;
            // Node<T>* root = nullptr;
        };
        
        virtual ~AugmentedIntervalTree(){
            cout << "AIT Constructor" << endl;
            // delete root;
        };

        void clear(){
            // clearHelper(root);
        };

        void clearHelper(Node<T>*& currentNode){
            while (currentNode != nullptr){
                clearHelper(currentNode->leftChild);
                clearHelper(currentNode->rightChild);
                delete currentNode;
                currentNode = nullptr;
            }
        };
        
        bool is_empty(){
            // return root == nullptr
            return nullptr;
        };
        
        bool add(T const& lower, T const& upper){
            // refactor the update data function to handle upper and lower properly
            return updateData(nullptr, lower, upper);
        };

        bool updateData(Node<T>*& currentnode, T lower, T upper){
            // algorithm needs work (but should be similar to Lab7)
            return false;
        }
        
        vector<Interval<T>> query(T const& point) const{
            // This function is basically a binary search to see which of the different nodes match the query
            vector<Interval<T>> nodes = NULL;
            return nodes;
        };
        
        bool remove(T const& lower, T const& upper){
            return deleteData(nullptr, lower, upper);
        };
        
        bool deleteData(Node<T>*& currentNode, T lower, T upper){
            // algorithm needs work (but should be similar to Lab7)
            return false;
        }

        string to_string() const{
            return "";
        };
};