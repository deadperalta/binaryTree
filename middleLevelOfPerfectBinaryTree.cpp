void print(Node* a,Node* b)
{
  if(a == NULL || b == NULL)
  {
    return;
  }
  if(b->left == NULL && b->right == NULL)
  {
    cout<<a->data<<" ";
  }
  
  if(b->left->left)
  {
    print(a->left,b->left->left);
    print(a->right,b->left->left);
  }
  else
  {
    print(a->left,b->left);
    print(a->right,b->left);
  }
}

void printMid(Node* root)
{
  print(root,root);
}
