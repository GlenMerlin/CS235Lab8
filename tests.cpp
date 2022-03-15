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
    return 0;
}

