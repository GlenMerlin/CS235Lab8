#include "IntervalTree.h"

using namespace std;
template<class T>
class AugmentedIntervalTree : public IntervalTree<T> {
    public: 
        AugmentedIntervalTree(){
            cout << "AIT Constructor" << endl;
        };
        
        virtual ~AugmentedIntervalTree(){
            cout << "AIT Constructor" << endl;
            clear();
        };

        void clear(){
            clearHelper(this->root);
        };

        void clearHelper(Node<T>*& currentNode){
            while (currentNode != nullptr){
                clearHelper(currentNode->left);
                clearHelper(currentNode->right);
                delete currentNode;
                currentNode = nullptr;
            }
        };
        
        bool is_empty() const override {
            return this->root == nullptr;
        };
        
        bool add(T const& lower, T const& upper){
            // refactor the update data function to handle upper and lower properly
            return updateData(this->root, lower, upper);
        };

        bool updateData(Node<T>*& currentNode, T lower, T upper){
            if (currentNode == NULL){
                Interval<T> tmp(lower, upper);
                currentNode = new Node<T>(tmp);
                return true;
            }
            else {
                // if (data < currentNode->){
                //     return updateData(currentNode->left, lower, upper);
                // }
                // else if (data > currentNode->data) {
                //     return updateData(currentNode->right, lower, upper);
                // }
                // else {
                    return false;
                // }
            }
        }

        // void updateMinMax(Node<T>*& node){
        //     if (node == nullptr){
        //         return;
        //     }
        //     node->min_max = 1 + max(
        //         node->left == nullptr ? -1 : node->left->min_max,
        //         node->right == nullptr? -1 : node->right->min_max
        //     )
        // }
        
        vector<Interval<T>> query(T const& point) const{
            // This function is basically a binary search to see which of the different nodes match the query
            vector<Interval<T>> nodes;
            // queryHelper(this->root, point, nodes);
            return nodes;
        };

        // void queryHelper(Node<T>* const& node, T point, vector<T>& nodes){
        //     // if (node == nullptr){
        //     //     return;
        //     // }

        //     // queryHelper(node->left, point, nodes);
        //     // // definitely wrong check but fix later
        //     // if(abs(item - node->interval) <= 3){
        //     //     nodes.push_back(node->interval)
        //     // }

        //     // queryHelper(node->right, point, items_found);
        // }
        
        bool remove(T const& lower, T const& upper){
            return deleteData(this->root, lower, upper);
        };
        
        bool deleteData(Node<T>*& currentNode, T lower, T upper){
            // algorithm needs work (but should be similar to Lab7)
            return false;
        }

        string to_string() const{
            return "";
        };
};