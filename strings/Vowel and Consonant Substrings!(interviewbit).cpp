https://www.interviewbit.com/problems/vowel-and-consonant-substrings/
int Solution::solve(string A) {
    int vowels=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'){
            vowels++;
        }
    }
    int consonents=A.size()-vowels;
    return(vowels*consonents)%((int)1e9+7);
}
