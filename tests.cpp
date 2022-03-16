#include "AugmentedIntervalTree.h"

using namespace std;

// This file is designed to perform tests on our functions to make sure that they're working properly

int main(){
    AugmentedIntervalTree<int> tree;
    test("Empty Check", tree.is_empty(), true);
    test("Add Check", tree.add(1,5), true);
    test("Add Check", tree.add(2,5), true);
    test("Remove Check", tree.remove(2,5), true);
    test("Dupe Remove Check", tree.remove(2,5), false);
    auto items = tree.query(3);
    test("Query for 3",(int) items.size(), 1);
    items = tree.query(1000);
    test("Failed Query for 1000", (int) items.size(), 0); 
    return 0;
}

