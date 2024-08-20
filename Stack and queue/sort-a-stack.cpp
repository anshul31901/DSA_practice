https://www.geeksforgeeks.org/problems/sort-a-stack/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */



 
  

void f(stack<int>&st){
    
    if(st.empty())return;
    
    int e = st.top();
    st.pop();
    
    //sort rest of stack
    f(st);
    
    //insert e at right position in stack
    stack<int>temp;
    while(!st.empty()&&e<st.top()){
        temp.push(st.top());
        st.pop();
    }
    st.push(e);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    return ;
    
    
    
    
}
void SortedStack :: sort()
{   
    f(s);
   //Your code here
}
