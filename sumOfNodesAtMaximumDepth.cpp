int sumAtMaxDepth(Node* root)
{
  int sum=0;
  queue<Node*>q;
  q.push(root);
  
  while(!q.empty())
  {
    sum=0;
    int n=q.size();
    while(n--)
    {
      Node* curr=q.front();
      q.pop();
      
      sum+=curr->data;
      
      if(curr->left)
      {
        q.push(curr->left);
      }
      if(curr->right)
      {
        q.push(curr->right);
      }
    }
  }
  return sum;
}
