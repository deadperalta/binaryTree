void convert(Node* root)
{
  if(root == NULL)
  {
    return 0;
  }
  
  if(root->left == NULL && root->right == NULL)
  {
    return root->data;
  }
  
  int left=convert(root->left);
  int right=convert(root->right);
  
  root->data+=left;
  return root->data+right;
}

void addLeft(Node* root)
{
  convert(root);
}
