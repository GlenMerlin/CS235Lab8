#include "IntervalTree.h"
#include "algorithm"



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
            currentNode->min_max = currentNode->interval;

            if (currentNode->left != nullptr){
                currentNode->min_max.lower = min(currentNode->min_max.lower, currentNode->left->min_max.lower);
                currentNode->min_max.upper = max(currentNode->min_max.upper, currentNode->left->min_max.upper);
            }
            if (currentNode->right != nullptr){
                
                currentNode->min_max.lower = min(currentNode->min_max.lower, currentNode->right->min_max.lower);
                currentNode->min_max.upper = max(currentNode->min_max.upper, currentNode->right->min_max.upper);
            }
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
                    Interval<T> swap = currentNode->interval;
                    currentNode->interval = largestChild->interval;
                    largestChild->interval = swap;
                    deleteData(currentNode->left, swap);
                    return true;
                }
                else if (currentNode->left != nullptr && currentNode->right == nullptr){
                    // find the highest left value and replace it
                    Node<T>* temp = currentNode->left;
                    delete currentNode;
                    currentNode = temp;
                    return true;
                }
                else if (currentNode->right != nullptr && currentNode->left == nullptr){
                    // replace the current value with the right child
                    Node<T>* temp = currentNode->right;
                    delete currentNode;
                    currentNode = temp;
                    return true;
                }
                else if (currentNode->left == nullptr && currentNode->right == nullptr){
                    delete currentNode;
                    currentNode = nullptr;
                    return true;
                }
            }
            else if (interval < currentNode->interval){
                bool removed = deleteData(currentNode->left, interval);
                if (removed){
                    updateMinMax(currentNode);   
                }
                return removed;
            }
            else {
                bool removed = deleteData(currentNode->right, interval);
                if (removed){
                    updateMinMax(currentNode);   
                }
                return removed;
            }
            return false;
        }
};