bool are_identical(
  BinaryTreeNode* root1,
  BinaryTreeNode* root2) {

  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }
  
  if (root1 != nullptr && root2 != nullptr) {
    return ((root1->data == root2->data) &&
            are_identical(root1->left, root2->left) &&
            are_identical(root1->right, root2->right));
  }

  return false;
}

int main() {
  BinaryTreeNode *root1 = new BinaryTreeNode(100);
  insert_bst(root1, 50);
  insert_bst(root1, 200);
  insert_bst(root1, 25);
  insert_bst(root1, 125);
  insert_bst(root1, 350);

  display_level_order(root1);
  
  BinaryTreeNode *root2 = create_random_BST(15);

  display_level_order(root2);
  
  // Try changing the roots being passed
  if(are_identical(root1, root2)) {
    cout<< " the trees are identical" << endl;
  } else {
    cout<< "the trees are not identical" << endl;
  }
}
