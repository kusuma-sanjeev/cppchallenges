using namespace std;

#include <iostream>
#include <queue>

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

class LevelAverage {
    public:
        static vector<double> findLevelAverages(TreeNode *root) {
            vector<double> result;
            if (root == nullptr) {
                return result;
            }

            queue<TreeNode *> queue;
            queue.push(root);
            while (!queue.empty()) {
                int levelSize = queue.size();
                double levelSum = 0;
                for (int i = 0; i < levelSize; i++) {
                    TreeNode *currentNode = queue.front();
                    queue.pop();
                    // add the node's value to the running sum
                    levelSum += currentNode->val;
                    // insert the children of current node to the queue
                    if (currentNode->left != nullptr) {
                        queue.push(currentNode->left);
                    }
                    if (currentNode->right != nullptr) {
                        queue.push(currentNode->right);
                    }
                }
                // append the current level's average to the result array
                result.push_back(levelSum / levelSize);
            }

            return result;
        }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    vector<double> result = LevelAverage::findLevelAverages(root);
    cout << "Level averages are: ";
    for (auto num : result) {
        cout << num << " ";
    }
}

