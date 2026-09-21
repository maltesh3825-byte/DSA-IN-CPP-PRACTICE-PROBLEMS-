//weakest soldier
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Row{
public:
        int idx;
        int count;
        Row(int idx,int count){
            this->idx=idx;
            this->count=count;
        }

        bool operator < (const Row &obj) const{
            if(this->count==obj.count){
                return this->idx > obj.idx;
            }
                return this->count > obj.count;
           
        }
};
void weakestSoldier(vector<vector<int>>mat,int k){
    vector<Row> rows;
    for(int i=0;i<mat.size();i++){
        int count=0;
        for(int j=0;j<mat.size();j++){
            
            if(mat[i][j]==1){
                count++;
            }
        }
            rows.push_back(Row(i,count));

    }
    priority_queue<Row> pq(rows.begin(),rows.end());
    for(int i=0;i<k;i++){
        cout<<"Row"<<pq.top().idx<<endl;
        pq.pop();
    }

}
int main(){
    vector<vector<int>> mat ={ {1,0,0,0},
                               {1,1,1,1},
                               {1,0,0,0},
                               {1,0,0,0}    };
    weakestSoldier(mat,2);
    return 0;
}
