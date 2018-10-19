#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main() {
   int n,m,v;
   std::cin >> n >> m >> v;
    vector<int> iv;
    vector<int> jv;
    vector<int> ij(2*m);
    vector<int> hv(n);
    vector<int> lv(2*m);
    vector<int> hp(n);
    vector<int> way;
    stack<int> vs;
    for (int i=0; i < n; i++){
        hv[i]= hp[i]= -1;
    }
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;

        ij[i]=a-1; ij[2*m-1-i]=b-1;
    }
    for (int k=0; k < 2*m; k++){
        int i = ij[k];
        lv[k] = hv[i];
        hv[i] = k;
    }
    vector<int> hn = hv;
    vs.push(v-1);
    //way.push_back(v);
    while (!vs.empty()){
        int cur_vertex = vs.top();
        way.push_back(cur_vertex);
        int k;
        hp[cur_vertex] = 1;
        for (k=hn[cur_vertex]; k != -1; k = lv[k]){
            if (hp[ij[2*m-1-k]] == -1)
                break;
        }
        if (k != -1){
            hn[cur_vertex] = lv[k];
            vs.push(ij[2*m-1-k]);
            //way.push_back(ij[2*m-1-k]);
        }
        else{
            if (!vs.empty())
                vs.pop();
        }
    }
    cout << way.size() << endl;
    for (int i = 0; i<way.size();i++)
    {
        cout << way[i] +1<< " ";
    }
    cout << endl;
    /*for (int i = 0; i < n; i++)
        for (int k = hv[i]; k != -1; k=lv[k]){
            int j = ij[2*m-1-k];
            printf("from  vertex %d to vertex %d by %d \n",i,j,k);
        }*/
    return 0;
}