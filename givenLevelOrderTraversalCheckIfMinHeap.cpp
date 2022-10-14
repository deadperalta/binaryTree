bool isMinHeap(vector<int>&arr)
{
  int n=arr.size();
  
  for(int i=(n/2-1);i>=0;i--)
  {
    if(2*i+1 < n)
    {
      if(arr[i] < arr[2*i+1])
      {
        return false;
      }
    }
    if(2*i+2 < n)
    {
      if(arr[i] < arr[2*i+2])
      {
        return false;
      }
    }
  }
  return true;
}
