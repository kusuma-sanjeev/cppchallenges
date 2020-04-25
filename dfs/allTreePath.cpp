using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
    public:
        int val = 0;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) {
            val = x;
            left = right = nullptr;
        }
};

class FindAllTreePaths {
    public:
        static vector<vector<int>> findPaths(TreeNode *root, int sum) {
            vector<vector<int>> allPaths;
            vector<int> currentPath;
            findPathsRecursive(root, sum, currentPath, allPaths);
            return allPaths;
        }

    private:
        static void findPathsRecursive(TreeNode *currentNode, int sum, vector<int> &currentPath,
                vector<vector<int>> &allPaths) {
            if (currentNode == nullptr) {
                return;
            }

            // add the current node to the path
            currentPath.push_back(currentNode->val);

            // if the current node is a leaf and its value is equal to sum, save the current path
            if (currentNode->val == sum && currentNode->left == nullptr && currentNode->right == nullptr) {
                allPaths.push_back(vector<int>(currentPath));
            } else {
                // traverse the left sub-tree
                findPathsRecursive(currentNode->left, sum - currentNode->val, currentPath, allPaths);
                // traverse the right sub-tree
                findPathsRecursive(currentNode->right, sum - currentNode->val, currentPath, allPaths);
            }

            // remove the current node from the path to backtrack,
            // we need to remove the current node while we are going up the recursive call stack.
            currentPath.pop_back();
        }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    int sum = 23;
    vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
    cout << "Tree paths with sum " << sum << ": " << endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

