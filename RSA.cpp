#include<iostream>
#include<math.h>

using namespace std;

int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
        return b;
      a = b;
      b= t;
   }
}

int main() {
   double p;
   double q;
   double e;
   double message;
   cout << "P=";
   cin >> p;
   cout << "Q=";
   cin >> q;
   cout << "E=";
   cin >> e;
   cout << "Message=";
   cin >> message;

   double n=p*q;
   double track;
   double phi= (p-1)*(q-1);
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }

   double d1=1/e;
   double d=fmod(d1,phi);

   double c = pow(message,e);
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout << "========Detail=========";
   cout << endl << "Original Message = "<<message;
   cout << endl << "p = "<<p;
   cout << endl << "q = "<<q;
   cout << endl << "n = pq = "<<n;
   cout << endl << "phi = "<<phi;
   cout << endl << "e = "<<e;
   cout << endl << "d = "<<d;
   cout << endl << "Encrypted message = "<<c;
   cout << endl << "Decrypted message = "<<m;
   return 0;
}
