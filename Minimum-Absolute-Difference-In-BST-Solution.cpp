########################################################################################  Question  ############################################################################################################################


Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

Example 1:

Input:
Input tree

Output:
10
Explanation:
There are no two nodes whose absolute difference is smaller than 10.
Example 2:

Input:
Input tree

Output:
20
Explanation:
There are no two nodes whose absolute difference is smaller than 20.
Your Task:
You don't have to take any input. Just complete the function absolute_diff() , that takes root as input and return minimum absolute difference between any two nodes.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(Height of tree)

Constraints:
2 <= n <= 105
1 <= Node->data <= 109





########################################################################################  Solution  ############################################################################################################################



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}
// Function to Build Tree
Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}


// } Driver Code Ends
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    public:
     void inorder(Node *root,vector<int> &v)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int absolute_diff(Node *root)
    {
        int min = INT_MAX;
        vector<int> v;
        inorder(root, v);
        for(int i = 0; i < v.size()-1; i++)
        {
            if(std::abs(v[i+1] - v[i]) < min)
                min = std::abs(v[i+1] - v[i]);
        }
        return min;
        //Your code here
        
    }
};


//{ Driver Code Starts.

int main()
{

  int t;
  scanf("%d ", &t);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    // getline(cin, s);
    if (root == NULL)
      continue;
    if (root->left == NULL and root->right == NULL)
      continue;
      Solution ob;
    cout << ob.absolute_diff(root) << '\n';
    // cout << s << '\n';
  }
  return 1;
}
// } Driver Code Ends
