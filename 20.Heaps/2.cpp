#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int > vec;
public:
    void push(int val){
        vec.push_back(val);
    
    int ci=vec.size()-1;
    int  pi=(ci-1)/2;
    while(pi>=0 && vec[ci] > vec[pi]){
        swap(vec[ci],vec[pi]);
        ci=pi;
        pi=(ci-1)/2;
    }
    }

    void heapify(int i){
        if(i>=vec.size()){
            return;
        }
        int l=2*i + 1;
        int r=2*i + 2;

        int maxI=i;
        if(l<vec.size() && vec[l]>vec[maxI]){
            maxI=l;
        }
        
        if(r<vec.size() && vec[r]>vec[maxI]){
            maxI=r;
        }
        swap(vec[i],vec[maxI]);
        if(maxI!=i){
            heapify(maxI);
        }


    }
    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();

        heapify(0);
    }

    int top(){
        return vec[0];
    }

    bool empty(){
        return vec.size()==0;
    }

};
int main(){
    Heap h;
    h.push(5);
    h.push(4);
    h.push(2);
    h.push(8);
   
    while(!h.empty()){ 
    cout<<h.top();
    h.pop();
    }
   
    return 0;
    

}