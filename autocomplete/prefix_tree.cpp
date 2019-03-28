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
            if (node->mEndOfWord)
                node->mNumPathWords++;
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

        vector<string> tails;
        string tail;
        readSuggestions(node, tails, -1, tail);

        for (auto i : tails)
        {
            string w = key + i;
            result.push_back(w);
        }

        return result;
    }

    void TreeNode::readSuggestions(TreeNode *node, vector<string>& tails, int curIndex, string &suggestion)
    {
        if (curIndex >= 0)
            suggestion.push_back((char)(curIndex + 'a'));

        if (node->mEndOfWord)
        {
            tails.push_back(suggestion);
            if (node->mNumPathWords == 0)
                return;
            node->mNumPathWords--;
        }

        int idx = 0;
        while (idx < mAlphabetSize)
        {
            if (node->mChildren[idx] != NULL)
            {
                readSuggestions(node->mChildren[idx], tails, idx, suggestion);
                cout << "Suggestion: " << suggestion << endl;
                if (curIndex >= 0)
                    suggestion = (char)(curIndex + 'a');
                else
                    suggestion = "";
            }
            idx++;
        }
    }

} // ds
