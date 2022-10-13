void convert(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  
  convert(root->left);
  convert(root->right);
  
  if(root->left == NULL)
  {
    root->left=root->right;
  }
  else
  {
    root->left->right=root->right;
  }
  root->right=NULL;
}

void downRight(Node* root)
{
  convert(root);
}
