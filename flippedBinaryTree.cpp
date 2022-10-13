Node* flipBinaryTree(Node* root)
{
  if(root == NULL)
  {
    return root;
  }
  if(root->left == NULL && root->right == NULL)
  {
    return root;
  }
  
  Node* flippedTree=flipBinaryTree(root);
  
  root->left->left=root->right;
  root->left->right=root;
  root->left=NULL;
  root->right=NULL;
  
  return flippedTree;
}
