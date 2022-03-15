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
                return true;
            }
            else {
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
                    bool added = updateData(currentNode->left, interval);
                    if (added) {
                        updateMinMax(currentNode);
                    }
                    return added;
                }
            }
            return false;
        }

        void updateMinMax(Node<T>*& currentNode){
            // if (currentNode == nullptr){
            //     return;
            // }
            // currentNode->min_max = 1 + max(
            //     currentNode->left == nullptr ? -1 : currentNode->left->min_max,
            //     currentNode->right == nullptr ? -1 : currentNode->right->min_max
            // )
            return;
        }
        
        vector<Interval<T>> query(T const& point) const{
            vector<Interval<T>> nodes;
            // queryHelper(this->root, point, nodes);
            return nodes;
        };

        void queryHelper(Node<T>* const& node, T point, vector<T>& nodes){
            if (node == nullptr){
                return;
            }
            return;

            // queryHelper(node->left, point, nodes);
            // definitely wrong check but fix later
            // if(abs(item - node->interval) <= 3){
            //     nodes.push_back(node);
            // }

            // queryHelper(node->right, point, items_found);
        }
        
        bool remove(T const& lower, T const& upper){
            Interval<T> interval(lower, upper);
            return deleteData(this->root, interval);
        };
        
        bool deleteData(Node<T>*& currentNode, Interval<T> interval){
            // if (currentNode == NULL){
            //     cout << "value: " << interval << " not found, failed to delete" << endl;
            //     return false;
            // }
            // else if (currentNode->interval == interval){
            //     if (currentNode->left != nullptr && currentNode->right != nullptr){
            //         // find the highest left value and replace it, then move the right child's pointer
            //         Node* largestChild = currentNode->left;
            //         while (largestChild->right != nullptr){
            //             largestChild = largestChild->right;
            //         }
            //         currentNode->interval = largestChild->interval;
            //         deleteData(currentNode->left, currentNode->interval);
            //         return true;
            //     }
            //     else if (currentNode->left != nullptr && currentNode->right == nullptr){
            //         // find the highest left value and replace it
            //         Node* temp = currentNode->left;
            //         delete currentNode;
            //         currentNode = temp;
            //         return true;
            //     }
            //     else if (currentNode->right != nullptr && currentNode->left == nullptr){
            //         // replace the current value with the right child
            //         Node* temp = currentNode->right;
            //         delete currentNode;
            //         currentNode = temp;
            //         return true;
            //     }
            //     else if (currentNode->left == nullptr && currentNode->right == nullptr){
            //         delete currentNode;
            //         currentNode = NULL;
            //         return true;
            //     }
            // }
            // else {
            //     if (interval < currentNode->interval){
            //         return deleteData(currentNode->left, interval);
            //     }
            //     else if (interval > currentNode->interval){
            //         return deleteData(currentNode->right, interval);
            //     }
            //     else {
            //         return false;
            //     }
            // }
            return false;
        }

        string to_string() const{
            return "";
        };
};