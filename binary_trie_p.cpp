#include<iostream>
#include<bits/stdc++.h> 
//#include<conio>
#include<sstream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std; 
class Trie
{
    public:
Trie *left;
Trie *right;
};
Trie *init()
{
    Trie* root=new Trie();
    root->left=NULL;
    root->right=NULL;
    return root;
}
Trie * insert(Trie*root,string x)
{
    Trie* node=root;
    if(node==NULL)
    node=init();
    root=node;
    for(long long int i=0;i<x.length();i++)
    {
      
      if(x[i]==0)
      {
          if(node->left==NULL)
          node->left=init();
          node=node->left;
      }
      else
      {
          if(node->right==NULL)
          node->right=init();
          node=node->right;
      }
    }
    return root;
}
Trie * upgrade(Trie *root1,Trie *root2,string s)
{
    if(root2==NULL)
    root2=init();
     Trie *node=root2;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]==0)
         {
             if(root1!=NULL)
             {
                 root2->right=root1->right;
                 root1=root1->right;
             }
          root2->left=init();
          root2=root2->left;
          
         }
         else 
         {
             if(root1!=NULL)
             {
                 root2->left=root1->left;
                 root1=root1->left;
             }
          root2->right=init();
          root2=root2->right;
         }
     }
return node;

}
int find(Trie*root,string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==0)
        {
            if(root!=NULL)
            root=root->left;
            else 
            return 0;
        }
        else 
        {
            if(root!=NULL)
            root=root->right;
            else 
            return 0;
        }
    }
    return 1;
}

int main()
{
   // Trie*root=NULL;
    long long int n,q;
    cin>>n;

  vector<Trie*> arr(10,NULL);
      string x;
    
    while(n--)
    {
    cin>>x;
    arr[0]=insert(arr[0],x);
    }
   
    cout<<"do u want to upgrade";
    string s;

    cin>>s;
    cin>>x;
    arr[1]=upgrade(arr[0],arr[1],x);
    int version;
    cin>>version;
    cin>>x;
    cout<<find(arr[version],x);

    return 0;
}
