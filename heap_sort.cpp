#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// To heapify a subtree rooted with node i which is
// Heapify:- A process which helps regaining heap properties in tree after removal 
void heapify(vector<int> &A, int n, int i)
{
   int par = i; // Initialize largest as root
   int left_child = 2 * i + 1; // left = 2*i + 1
   int right_child = 2 * i + 2; // right = 2*i + 2
   int swap_with=-1;

   // If left child is larger than root
   if (left_child < n && A[left_child] > A[par])
       swap_with = left_child;

   // If right child is larger than largest so far
   if (right_child < n && A[right_child] > A[par])
       if(swap_with==-1)swap_with=right_child;
       else if(A[left_child]<A[right_child])swap_with=right_child;

   // If it's children are not samller than parent 
   if (swap_with!=-1) {
       swap(A[par], A[swap_with]);

       // Recursively heapify the affected sub-tree
       heapify(A, n, swap_with);
   }
}

// main function to do heap sort
void heap_sort(vector<int> &A, int n)
{
   // Build heap (rearrange array)
   for (int i = n - 1; i >= 0; i--)
       heapify(A, n, i);

   // One by one extract an element from heap
   for (int i = n - 1; i >= 0; i--) {
       // Move current root to end
       swap(A[0], A[i]);

       // call max heapify on the reduced heap
       heapify(A, i, 0);
   }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    vector<int> a={3,2,1,7,456,87,5,4};
    heap_sort(a,a.size());
    for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
}