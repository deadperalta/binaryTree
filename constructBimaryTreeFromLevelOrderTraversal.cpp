Node* createTree(vector<int>&nodes)
{
  Node* root=new Node(nodes[0]);
  queue<Node*>q;
  q.push(root);
  
  int i=1;
  while(i < nodes.size())
  {
    if(q.front()->left)
    {
      q.front()->right=new Node(nodes[i]);
      q.push(q.front()->right);
    }
    else
    {
      q.front()->left=new Node(nodes[i]);
      q.push(q.front()->left);
    }
    
    if(q.size() > 2)
    {
      q.pop();
    }
    i++;
  }
  return root;
}
