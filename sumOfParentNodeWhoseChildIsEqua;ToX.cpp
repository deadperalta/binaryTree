int sumOfParent(Node* root)
{
  int sum=0;
  queue<Node*>q;
  q.push(root);
  
  while(!q.empty())
  {
    Node* curr=q.front();
    q.pop();
    
    if((curr->left && curr->left->data == x) || (curr->right && curr->right->data == x))
    {
      sum+=curr->data;
    }
    if(curr->left)
    {
      q.push(curr->left);
    }
    if(curr->right)
    {
      q.push(curr->right);
    }
  }
  return sum;
  
}
