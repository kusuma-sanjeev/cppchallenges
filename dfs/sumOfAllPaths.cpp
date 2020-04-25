using namespace std;

#include <iostream>

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

class SumOfPathNumbers {
    public:
        static int findSumOfPathNumbers(TreeNode *root) {
            return findRootToLeafPathNumbers(root, 0);
        }

    private:
        static int findRootToLeafPathNumbers(TreeNode *currentNode, int pathSum) {
            if (currentNode == nullptr) {
                return 0;
            }

            // calculate the path number of the current node
            pathSum = 10 * pathSum + currentNode->val;

            // if the current node is a leaf, return the current path sum.
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                return pathSum;
            }
            // traverse the left and the right sub-tree
            return findRootToLeafPathNumbers(currentNode->left, pathSum) + 
                findRootToLeafPathNumbers(currentNode->right, pathSum);
        }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}

