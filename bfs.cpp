#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int main() {
   int n,m,v;
   std::cin >> n >> m >> v;
    vector<int> iv(m);
    vector<int> jv(m);
    vector<int> ij(2*m);
    vector<int> hv(n);
    vector<int> lv(m);
    vector<int> hp(n);
    vector<int> way(n); // way to vertex i
    vector<int> dist(n);
    queue<int> labeled;

    for (int i=0; i < n; i++){
        hv[i]= -1;
        dist[i] = n;
        way[i]= -2;
    }
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        iv[i]=a ;
        jv[i]=b;
        lv[i]=hv[a];
        hv[a]=i;
        //ij[i]=a-1; ij[2*m-1-i]=b-1;

    }
    labeled.push(v);
    dist[v] = 0;
    way[v] = -1;
    while (!labeled.empty()){
        int cur_vertex = labeled.front();
        labeled.pop();
        for (int k = hv[cur_vertex]; k != -1; k = lv[k]){
            int j = jv[k];
            if (dist[j] == n){
                dist[j] = dist[cur_vertex]+1;
                labeled.push(j);
                way[j] = k;
            }
        }
    }
    for (int i = 0; i < n; i ++)
        printf("Dist to %d from %d is %d \n",i,v,dist[i]);
    /*for (int k=0; k < 2*m; k++){
        int i = ij[k];
        lv[k] = hv[i];
        hv[i] = k;
    }
    vector<int> hn = hv;
    vs.push(v-1);*/

    return 0;
}