int maxSum(Node* root)
{
  int oddSum=0,evenSum=0;
  queue<Node*>q;
  q.push(root);
  
  int level=0;
  
  while(!q.empty())
  {
    int n=q.size();
    while(n--)
    {
      Node* temp=q.front();
      q.pop();
      
      if(level % 2 == 0)
      {
        evenSum+=temp->data;
      }
      else
      {
        oddSum+=temp->data;
      }
    }
    level++;
  }
  return max(oddSum,evemSum);
}
