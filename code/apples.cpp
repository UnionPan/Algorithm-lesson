#include <bits/stdc++.h> 
using namespace std; 

int single_value(int n, vector<int> a){
     int single = 0;
     for (int i = 0; i < a.size(); i++){
           single = single ^ a[i];
     }
     return single;
}
    

