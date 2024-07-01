#define ll long long 
// if a%b is +ve its the and 
// but is a%b is negative real ans is b+a%b

int Solution::pow(int x, int n, int d) {
if(d==1)return 0; 
  ll ans = 1;
  ll base = 1ll*x%d;
  if(n==0)ans = base%d;
  while(n>0){
    if(n&1)ans =(ans*base)%d;

    base = (base*base)%d;
    n=n>>1;
  }
  if (ans>=0) return ans ;
  else return d +ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
