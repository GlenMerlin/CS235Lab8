#include "AugmentedIntervalTree.h"

using namespace std;

// This file is designed to perform tests on our functions to make sure that they're working properly

int main(){
    AugmentedIntervalTree<int> tree;
    test("Empty Check", tree.is_empty(), true);
    test("Add Check", tree.add(1,5), true);
    test("Add Check", tree.add(2,5), true);
    test("Add Check", tree.add(5,10), true);
    test("Add Check", tree.add(10,15), true);
    test("Add Check", tree.add(20,50), true);
    test("Remove Check", tree.remove(10,15), true);
    test("Remove Check", tree.remove(2,5), true);
    test("Dupe Remove Check", tree.remove(2,5), false);
    auto items = tree.query(3);
    test("Query for 3",(int) items.size(), 1);
    items = tree.query(1000);
    test("Failed Query for 1000", (int) items.size(), 0);
    test("Additional Add Check", tree.add(2,5), true);
    items = tree.query(3);
    test("Query for 3 with multiple results", (int) items.size(), 2); 
    return 0;
}

