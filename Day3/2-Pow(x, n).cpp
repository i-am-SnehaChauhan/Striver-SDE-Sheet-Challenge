/*Approach1: Brute Force*/
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int limit = n;
        if(n<0){
            limit = -1 * limit;
        }
        for(int i=0; i<limit; i++){
            ans = ans*x;
        }
        if(n<0){
            ans = (double)1.0/ (double)ans;
        }
        return ans;
    }
};


/*Approach2: Using Binary Exponentiation*/


double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}