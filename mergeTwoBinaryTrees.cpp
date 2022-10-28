Node* merged(Node* a,Node* b)
{
  if(a == NULL)
  {
    return b;
  }
  if(b == NULL)
  {
    return a;
  }
  
  a->data+=b->data;
  a->left=merged(a->left,b->left);
  b->right=merged(a->right,b->right);
  
  return a;
}
