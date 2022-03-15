#include "AugmentedIntervalTree.h"

using namespace std;

// This file is designed to perform tests on our functions to make sure that they're working properly

int main(){
    AugmentedIntervalTree<int> tree;
    test("Empty Check", tree.is_empty(), false);
    return 0;
}

