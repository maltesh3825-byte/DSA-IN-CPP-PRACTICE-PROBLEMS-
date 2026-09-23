#include<iostream>
#include<vector>
using namespace std;
class segmentTree{
    vector<int> tree;
    int n;
public:
    segmentTree(vector<int> &arr){
        n= arr.size();
        tree.resize(4*n);
        buildTree(arr, 0, n-1, 0);
    }

    void buildTree(vector<int> & arr, int start, int end, int node){
        if(start==end){
            tree[node]=arr[start];
            return ;
        }

        int mid = start + (end-start)/2;
        buildTree(arr, start, mid, 2*node+1);//left child
        buildTree(arr, mid+1, end, 2*node+2);//right child

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    void printTree(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
    int rangeSum(int qi, int qj, int si, int sj, int node){
        if(qj <si || qi>sj){
            return 0;
        }
        if(qi<=si && sj <=qj){
            return tree[node];
        }

        else{
            //partial overlap

            int mid = si+(sj-si)/2;
            return  rangeSum(qi, qj, si, mid, 2*node+1)+
            rangeSum(qi, qj, mid+1, sj, 2*node+2);
        }
    }

    int rangeQuery(int qi, int qj){
        return rangeSum(qi, qj, 0, n-1,0);
    }
};
int main(){
    vector<int> arr ={1,2,3,4,5,6,7,8};
    segmentTree st(arr);
    // st.printTree();
    cout<<st.rangeQuery(2,5);
    return 0;
}