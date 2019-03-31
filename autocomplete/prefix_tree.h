#include <vector>
#include <string>

using namespace std;

namespace ds
{

class TreeNode
{
public:
    TreeNode();
    ~TreeNode();

    void insert(TreeNode *root, const string& key);
    vector<string> getAutoComplete(TreeNode *root, const string& key);
    void readSuggestions(TreeNode *node, vector<string> &result, string &key);

private:
    int mAlphabetSize   = 26;
    bool mEndOfWord     = false;
    vector<TreeNode *> mChildren;
};

} // ds
