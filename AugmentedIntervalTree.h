#include "IntervalTree.h"

using namespace std;
template<class T>
class AugmentedIntervalTree : public IntervalTree<T> {
    public: 
        AugmentedIntervalTree(){};
        
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
            Interval<T> interval(lower, upper);
            return updateData(this->root, interval);
        };

        bool updateData(Node<T>*& currentNode, Interval<T> interval){
            if (currentNode == nullptr){
                currentNode = new Node<T>(interval);
                updateMinMax(currentNode);
                return true;
            }
            if (interval == currentNode->interval){
                return false;
            }
            else if (interval < currentNode->interval){
                bool added = updateData(currentNode->left, interval);
                if (added) {
                    updateMinMax(currentNode);
                }
                return added;
            }
            else {
                bool added = updateData(currentNode->right, interval);
                if (added) {
                    updateMinMax(currentNode);
                }
                return added;
            }
        }

        void updateMinMax(Node<T>*& currentNode){
            if (currentNode == nullptr){
                return;
            }
            T lower, upper;
            if (currentNode->left != nullptr){
                lower = currentNode->left->min_max.lower;
            }
            else {
                lower = currentNode->interval.lower;
            }
            if (currentNode->right != nullptr){
                upper = currentNode->right->min_max.upper;
            }
            else{
                upper = currentNode->interval.upper;
            }
            Interval<T> minMax(lower, upper);
            currentNode->min_max = minMax;
            return;
        }
        
        vector<Interval<T>> query(T const& point) const override{
            vector<Interval<T>> nodes;
            queryHelper(this->root, point, nodes);
            return nodes;
        };

        void queryHelper(Node<T> *currentNode, T const &point, vector<Interval<T>>& nodes) const{
            if (currentNode == nullptr){
                return;
            }
            
            queryHelper(currentNode->left, point, nodes);

            if(currentNode->interval.contains(point)){
                nodes.push_back(currentNode->interval);
            }

            queryHelper(currentNode->right, point, nodes);
        }
        
        bool remove(T const& lower, T const& upper) override{
            Interval<T> interval(lower, upper);
            return deleteData(this->root, interval);
        };
        
        bool deleteData(Node<T>*& currentNode, Interval<T> interval){
            if (currentNode == nullptr){
                cout << "value: " << interval << " not found, failed to delete" << endl;
                return false;
            }
            if (currentNode->interval == interval){
                if (currentNode->left != nullptr && currentNode->right != nullptr){
                    // find the highest left value and replace it, then move the right child's pointer
                    Node<T>* largestChild = currentNode->left;
                    while (largestChild->right != nullptr){
                        largestChild = largestChild->right;
                    }
                    currentNode = largestChild;
                    deleteData(currentNode->left, currentNode->interval);
                    updateMinMax(currentNode);
                    return true;
                }
                else if (currentNode->left != nullptr && currentNode->right == nullptr){
                    // find the highest left value and replace it
                    Node<T>* temp = currentNode->left;
                    delete currentNode;
                    currentNode = temp;
                    updateMinMax(currentNode);
                    return true;
                }
                else if (currentNode->right != nullptr && currentNode->left == nullptr){
                    // replace the current value with the right child
                    Node<T>* temp = currentNode->right;
                    delete currentNode;
                    currentNode = temp;
                    updateMinMax(currentNode);
                    return true;
                }
                else if (currentNode->left == nullptr && currentNode->right == nullptr){
                    delete currentNode;
                    currentNode = nullptr;
                    updateMinMax(currentNode);
                    return true;
                }
            }
            else if (interval < currentNode->interval){
                return deleteData(currentNode->left, interval);
            }
            else {
                return deleteData(currentNode->right, interval);
            }
            return false;
        }
};