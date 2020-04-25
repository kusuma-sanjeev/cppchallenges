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

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
    vector<int> currentPath;
    return countPathsRecursive(root, S, currentPath);
  }

 private:
  static int countPathsRecursive(TreeNode *currentNode, int S, vector<int> &currentPath) {
    if (currentNode == nullptr) {
      return 0;
    }

    // add the current node to the path
    currentPath.push_back(currentNode->val);
    int pathCount = 0, pathSum = 0;
    // find the sums of all sub-paths in the current path list
    for (vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend();
         ++itr) {
      pathSum += *itr;
      // if the sum of any sub-path is equal to 'S' we increment our path count.
      if (pathSum == S) {
        pathCount++;
      }
    }

    // traverse the left sub-tree
    pathCount += countPathsRecursive(currentNode->left, S, currentPath);
    // traverse the right sub-tree
    pathCount += countPathsRecursive(currentNode->right, S, currentPath);

    // remove the current node from the path to backtrack,
    // we need to remove the current node while we are going up the recursive call stack.
    currentPath.pop_back();

    return pathCount;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}

