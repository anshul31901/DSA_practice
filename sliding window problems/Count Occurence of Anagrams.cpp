https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
// Gist of the logic:

// 1.	Create an unordered map for the given pattern. The map stores all the distinct characters of the pattern as keys, and their frequencies as values. Create a variable count, which has the count of all the distinct characters in the pattern, which is the size of the map. Create another variable for storing the actual answer.
// 2.	Inside the while loop, compare the jth character with the keys of the map. If this character is found in the map, decrement its corresponding value. If the value of any of the keys becomes 0, decrement the value of count. It means that you’ve found one character in its required quantity in your current window. Like this if for every character in the map, the value becomes 0, then the value of count becomes 0, and it signifies that the current window is an anagram of the pattern. We’re using this count variable to signify whether the window is an anagram or not(in O(1) time), otherwise we have to traverse the whole map for checking if every corresponding value has become 0 or not, and it would have taken O(K) time. 
// 3.	When you’ve reached the window size, you need to do 2 things:-
// a)	Retrieving the answer- if the count becomes 0, anagram is found, increment the value of ans variable.
// b)	Sliding the window- before sliding the window, we need to remove all the calculations regarding the first element in the current window. If it exists in the map, then we need to increment the corresponding value in the map. Why we’re incrementing its value because, this character is not going to be there in our next window, so if it has contributed in making an anagram for our previous window, we need to delete its appearance or significance in the map, which tells that there’s a gap which needs to be filled by the next incoming character to complete this incomplete anagram. And only if the corresponding value in the map has become 1, we’ll increment the value of count, and not for any other case.
// For eg:-
// Pattern- aaba
// Current state of Map – a->3
// 	      			     b->1
// count=2

// window has:- acbe
// Current state of Map – a->2 
// 	      			          b->0
// count=1 (what current state of the map signifies is, we need 2 more a's to complete an anagram)
// We have to remove this 'a', as it is the first element of the current window, because we need to move ahead now:-
// window is: cbe_
// Current state of the map- a->3
//                                               b->0
// count=1  (this state of the map signifies that we need 3 a's to find an anagram)


// In such case we’re removing this ‘a’ from the window, so we increment its value to 3, we shouldn’t increment the value of count in this case. Increment the count only if the corresponding value becomes 1 after incrementing it. Because the whole part of ‘a’ is not gone by removing the first element of the previous window, some part of it is gone with it. When the whole part is gone, then we can say that okay, there’s one more character which needs to be found in the next window in its whole quantity.
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char,int> m;
    //first store very element of pattern in the map and its frequency
	    for(int i=0;i<pat.size();i++){
	        if(m.find(pat[i])==m.end())m.insert({pat[i],1});
	        else m[pat[i]]++;
	    }
    //count is the number of distinct characters in the map
	    int count=m.size();
	    int ans=0;
	    int i=0;
	    int j=0;
	    while(j<txt.size()){
        //j'th character is entering the window.
      //while j is less than the size of pattern if the jth index contains a character that is present in attern decrement its freq from map 
      //and if its freq becomes 0 decrement count (means we got all occurences of that character in our  sliding window).
	        if(m.find(txt[j])!=m.end()){
	            m[txt[j]]--;
	            if(m[txt[j]]==0)count--;
	        }
        //when our sliding wiondow reaches pattern.size() count==0 indicates that our sliding window has all occurences of all distinct characters present in pattern so we increment ans by one.
        
        if(j-i+1==pat.size()){
	            if(count==0)ans++;
        //now we want to move the window ,i's case is opposite of j, incrementing i means the ith char is leaving the window.
        //so if ith character is present in the map(or in the pattern).we increment its freq in the map,and if its being incremented by 0 means we got count++. i.e. we got new character that isn't present in window.
	            if(m.find(txt[i])!=m.end()){
	                if(m[txt[i]]==0)count++;
	               
	                m[txt[i]]++;
	            }
      //incrementing i
	            i++;
	            
	        }
      //incrementing j
	        j++;
	    }
	    return ans;
	    
	    // code here
	}

};
