// problem source: https://www.hackerrank.com/challenges/30-more-exceptions/problem
// discussion reference: https://www.hackerrank.com/challenges/30-more-exceptions/forum/comments/141662
#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Calculator {
    public:
        int power(int n, int p)  {
            if (n > -1 && p > -1) {
                int result = 1;
                while (p-->0) {
                    result *= n;
                }
                return result;
            } else
                throw runtime_error("n and p should be non-negative");
        }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl;
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }

}
