using namespace std;

#include <iostream>
#include <queue>
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

class ZigzagTraversal {
    public:
        static vector<vector<int>> traverse(TreeNode *root) {
            vector<vector<int>> result;
            if (root == nullptr) {
                return result;
            }

            queue<TreeNode *> queue;
            queue.push(root);
            bool leftToRight = true;
            while (!queue.empty()) {
                int levelSize = queue.size();
                vector<int> currentLevel(levelSize);
                for (int i = 0; i < levelSize; i++) {
                    TreeNode *currentNode = queue.front();
                    queue.pop();

                    // add the node to the current level based on the traverse direction
                    if (leftToRight) {
                        currentLevel[i] = currentNode->val;
                    } else {
                        currentLevel[levelSize - 1 - i] = currentNode->val;
                    }

                    // insert the children of current node in the queue
                    if (currentNode->left != nullptr) {
                        queue.push(currentNode->left);
                    }
                    if (currentNode->right != nullptr) {
                        queue.push(currentNode->right);
                    }
                }
                result.push_back(currentLevel);
                // reverse the traversal direction
                leftToRight = !leftToRight;
            }

            return result;
        }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(20);
    root->right->left->right = new TreeNode(17);
    vector<vector<int>> result = ZigzagTraversal::traverse(root);
    cout << "Zigzag traversal: ";
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
    }
}

