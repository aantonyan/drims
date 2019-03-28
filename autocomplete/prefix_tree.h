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
    void readSuggestions(TreeNode *node, vector<string> &result, int curIndex, string &suggestion);

private:
    int mAlphabetSize   = 256;
    bool mEndOfWord     = false;
    int mNumPathWords   = 0;
    vector<TreeNode *> mChildren;
};

} // ds
