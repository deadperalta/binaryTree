vectorv<vector<int>>changeLevel(Node* root)
{
  queue<Node*>q;
  q.push(root);
  
  int level=0;
  while(!q.empty())
  {
    int n=q.size();
    vector<int>temp;
    
    while(n--)
    {
      Node* curr=q.front();
      q.pop();
      temp.push_back(curr->data);
      
      if(curr->left)
      {
        q.push(curr->left);
      }
      if(curr->right)
      {
        q.push(curr->right);
      }
    }
    
    if((level/2)%2 == 1)
    {
      reverse(temp.begin(),temp.end());
    }
    
    ans.push_back(temp);
  } 
}
