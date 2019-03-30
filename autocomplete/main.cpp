#include "prefix_tree.h"

#include <iostream>
#include <string>

using namespace ds;

int main()
{
    TreeNode *root = new TreeNode();
    root->insert(root, "cat");
    root->insert(root, "car");
    root->insert(root, "carz");
    root->insert(root, "carp");
    root->insert(root, "test");
    root->insert(root, "temp");
    root->insert(root, "toast");
    root->insert(root, "tort");
    root->insert(root, "toma");

    vector<string> result = root->getAutoComplete(root, "t");
    for (auto i : result)
        cout << "Found a word: " << i << endl;

    return 0;
}
