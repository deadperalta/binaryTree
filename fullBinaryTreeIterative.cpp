bool isFull(Node* root)
{
  queue<Node*>q;
  q.push(root);
  
  while(!q.empty())
  {
    Node* curr=q.front();
    q.pop();
    
    if((curr->left && curr->right == NULL) || (curr->right && curr->left == NULL))
    {
      return false;
    }
    
    if(curr->left)
    {
      q.push(curr->left);
      q.push(curr->right);
    }
  }
  return true;
}
