//implementation of segment tree for range query
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//function to build the segment tree
void build(vector<int> &a, vector<int> &tree, int node, int start, int end){
    if(start == end){ //if start and end are equal then it is a leaf node
        tree[node] = a[start]; //initialize value
    }
    else{ //if start and end are not equal then it is an internal node
        int mid = (start + end)/2;
        build(a, tree, 2*node, start, mid);
        build(a, tree, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

//function to update the segment tree
void update(vector<int> &tree, int node, int start, int end, int idx, int val){
    if(start == end){ // if start and end are equal then it is a leaf node
        tree[node] = val; //update value of the leaf node to val 
    }
    else{ //if start and end are not equal then it is an internal node
        int mid = (start + end)/2; //find the mid 
        if(start <= idx && idx <= mid){ //if idx is in the left child
            update(tree, 2*node, start, mid, idx, val); //go to the left child
        }
        else{ //if idx is in the right child
            update(tree, 2*node+1, mid+1, end, idx, val); //go to the right child
        }
        tree[node] = tree[2*node] + tree[2*node+1]; //update the value of the node
    } 
}

//function to query the segment tree
int query(vector<int> &tree, int node, int start, int end, int l, int r){ 
    if(r < start || end < l){ //out of range
        return 0;
    }
    if(l <= start && end <= r){ //total overlap
        return tree[node]; 
    }
    int mid = (start + end)/2; //partial overlap
    int p1 = query(tree, 2*node, start, mid, l, r); //query left child
    int p2 = query(tree, 2*node+1, mid+1, end, l, r); //query right child
    return (p1 + p2); //return the sum
}

void print(vector<int> &tree){ //function to print the segment tree
    for(int i = 0; i < tree.size(); i++){ //loop over all the nodes
        cout << tree[i] << " ";
    }
    cout << endl;
}


int main(){
    int n; 
    cin >> n;  //size of vector
    vector<int> a(n);
    for(int i = 0; i < n; i++){ //input vector
        cin >> a[i];
    }
    int h = (int)ceil(log2(n)); //height of segment tree
    int tree_size = 2*(int)pow(2, h); //size of segment tree
    vector<int> tree(tree_size); //segment tree
    build(a, tree, 1, 0, n-1); //build the segment tree
    int q; //number of queries
    cin >> q;
    while(q--){ //loop over all the queries
        char c; //c for character
        cin >> c;
        if(c == 'u'){   //u for update
            int idx, val;  //idx for index, val for value
            cin >> idx >> val;
            update(tree, 1, 0, n-1, idx-1, val); //idx-1 because indexing starts from 0
        }
        else{
            int l, r; //l for left, r for right
            cin >> l >> r;
            cout << query(tree, 1, 0, n-1, l-1, r-1) << endl; //l-1 and r-1 because indexing starts from 0
        }
    }
    return 0;
}
