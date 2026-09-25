//range max segment tree 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class segmentTree{
    vector<int> tree;
    int n;
    void buildTree(vector<int> &nums, int start, int end, int node){
        if(start==end){
            tree[node]=nums[start];
            return;
        }
        int mid = start + (end-start)/2;

        buildTree(nums, start, mid, 2*node+1);
        buildTree(nums, mid+1, end, 2*node+2);

        tree[node]= max(tree[2*node+1], tree[2*node+2]);
    }

    void updateUtil(int idx, int newValue, int start, int end, int node){
        if(start==end){
            tree[node]=newValue;
            return;
        }
        int mid= start +(end-start)/2;
        if(idx>=start && idx<=mid){
            updateUtil(idx, newValue, start, mid, 2*node+1);
        }
        else{
            updateUtil(idx, newValue, mid+1, end, 2*node+2);
        }
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }
public:
    segmentTree(vector<int> &nums){
        n=nums.size();
        tree.resize(4*n);
        buildTree(nums, 0, n-1, 0);
    }
     void printTree(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
    int maxQuery(int qi, int qj, int si, int sj, int node){
        if(qi>sj || qj<si){
            return INT_MIN;
         }
         if(qi<=si && qj>=sj){
            //complete
            return tree[node];

         }
         else{
            //partial
            int mid = si + (sj-si)/2;
            int leftmax= maxQuery(qi, qj, si, mid, 2*node+1);
            int rightmax= maxQuery(qi, qj, mid+1, sj, 2*node+2);

            return max(leftmax, rightmax);
         }

    }
    int rangeQuery(int qi, int qj){
        return maxQuery(qi, qj, 0, n-1,0);
    }
    void updateQuery(int idx, int newValue){
        updateUtil(idx, newValue, 0, n-1, 0);
    }
};
int main(){
    vector<int> nums={6, 8, -1, 2, 17, 1, 3, 2, 4};
    segmentTree st(nums);
    // st.printTree();
    // cout<<st.rangeQuery(2,5)<<endl;
    st.updateQuery(4,8);
    cout<<st.rangeQuery(0,8);

}