https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
//you can do the non optimal code yourself but if you want to do the problem in the optimised way you need to use sliding window protocol

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
//first we create a queue data structure and while iterating what we will do is initially increase j till the sliding window raches the desired length.
  //all this time one operation is common if we discover a negative element we push it inside a queue
  //when the sliding window reaches the size of k we know that if the front element of queue will be its first negative integer and if the queue is empty it has none.
  //as we are goint to increment i and j in order to move to the next window if q.front()==A[i] means q.front()will nt exist in next window so we pop it.
  //and then we increment i. Time complecity is O(N).
    queue<long long>q;
    vector<long long>ans;
    
    int i=0;
    int j=0;
    while(j<N){
        if(A[j]<0)q.push(A[j]);
        if(j-i+1==K){
            if(q.empty())ans.push_back(1ll*0);
            else{
                ans.push_back(q.front());
                if(A[i]==q.front())q.pop();
            }
            
            i++;
        }
        j++;
    }
    return ans;

 }
