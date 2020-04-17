// C++ program to find celebrity 
#include <bits/stdc++.h> 
#include <list> 
using namespace std; 
  
// Max # of persons in the party 
#define N 8 
  
// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 
  
bool knows(int a, int b) { 
    return MATRIX[a][b]; 
} 


int findCelebrity(int n) {
    stack<int> s;

    int c;
    
    for (int i=0; i<N; i++){
        s.push(i);
    }

    int a = s.top();
    s.pop();

    int b = s.top();
    s.pop();

    while (s.size() > 1){
        if(knows(a,b)){
            a = s.top();
            s.pop();
        }
        else{
            b = s.top();
            s.pop();
        }
    }

    c = s.top();
    s.pop();


    if (knows(c, b)){
        c = b;
    }
    if (knows(c, a)){
        c = a;
    }
    
    for (int i = 0; i < N; i++){
        if (i != c && (knows(c, i) || !knows(i, c))){
            return -1;
        }
    }
    
    return c+1;
}

int findCelebrity_ex(int n) 
{ 
    // Handle trivial  
    // case of size = 2 
  
    stack<int> s; 
  
    int C; // Celebrity 
  
    // Push everybody to stack 
    for (int i = 0; i < n; i++) 
        s.push(i); 
  
    // Extract top 2 
    int A = s.top(); 
    s.pop(); 
    int B = s.top(); 
    s.pop(); 
  
    // Find a potential celevrity 
    while (s.size() > 1) 
    { 
        if (knows(A, B)) 
        { 
            A = s.top(); 
            s.pop(); 
        } 
        else
        { 
            B = s.top(); 
            s.pop(); 
        } 
    } 
  
    // Potential candidate? 
    C = s.top(); 
    s.pop(); 
  
    // Last candidate was not  
    // examined, it leads one  
    // excess comparison (optimize) 
    if (knows(C, B)) 
        C = B; 
  
    if (knows(C, A)) 
        C = A; 
  
    // Check if C is actually 
    // a celebrity or not 
    for (int i = 0; i < n; i++) 
    { 
        // If any person doesn't  
        // know 'a' or 'a' doesn't  
        // know any person, return -1 
        if ( (i != C) && 
                (knows(C, i) ||  
                 !knows(i, C)) ) 
            return -1; 
    } 
  
    return C; 
} 

int findCelebrity_twopointer(int n){
    int a = 0;
    int b = n-1;
    while(a < b){
        if (knows(a, b))
            a++;
        else 
            b--;
    }

    for (int i = 0; i < n; i++) 
    { 
        // If any person doesn't  
        // know 'a' or 'a' doesn't  
        // know any person, return -1 
        if ( (i != a) && 
                (knows(a, i) ||  
                 !knows(i, a)) ) 
            return -1; 
    } 
    return a;
}

int main() 
{ 
    int n = 4; 
    int id = findCelebrity_ex(n); 
    id == -1 ? cout << "No celebrity" : 
               cout << "Celebrity ID " << id; 
    return 0; 
} 