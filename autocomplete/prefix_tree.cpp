#include "prefix_tree.h"

#include <iostream>

namespace ds
{

    TreeNode::TreeNode()
    {
        for (int i = 0; i < mAlphabetSize; i++)
            mChildren.push_back(NULL);
    }

    TreeNode::~TreeNode()
    {
        for (int i = 0; i < mAlphabetSize; i++)
            delete mChildren[i];
    }

    void TreeNode::insert(TreeNode *root, const string& key)
    {
        if (root == NULL || key.empty())
            return;

        TreeNode *node = root;
        int length = key.length();
        for (int i = 0; i < length; i++)
        {
            int index = key[i] - 'a';
            if (node->mChildren[index] == NULL)
            {
                node->mChildren[index] = new TreeNode();
            }
            node = node->mChildren[index];
        }
        node->mEndOfWord = true;
    }

    vector<string> TreeNode::getAutoComplete(TreeNode *root, const string& key)
    {
        vector<string> result;
        if (root == NULL || key.empty())
            return result;

        TreeNode *node = root;
        int length = key.length();
        for (int i = 0; i < length; i++)
        {
            int index = key[i] - 'a';
            node = node->mChildren[index];
        }

        string k = key;
        readSuggestions(node, result, k);

        return result;
    }

    void TreeNode::readSuggestions(TreeNode *node, vector<string>& res, string &key)
    {
        if (node->mEndOfWord)
            res.push_back(key);

        for (int i = 0; i < mAlphabetSize; i++)
        {
            if (node->mChildren[i] != NULL)
            {
                key.push_back((char)(i + 'a'));
                readSuggestions(node->mChildren[i], res, key);
                key.pop_back();
            }
        }
    }

} // ds
