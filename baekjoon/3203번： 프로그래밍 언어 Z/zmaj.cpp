#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MOD 10000
inline int mod( int x ) { return (x%MOD+MOD)%MOD; }

struct matrica {
   vector<int> v;
   int n, m;
   int & operator () ( int r, int s ) { return v[r*m+s]; }
   matrica( int N, int M ) {
      n=N; m=M;
      v.resize( n*m );
      for( int i = 0; i < n; ++i )
         for( int j = 0; j < m; ++j )
            v[i*m+j] = 0;
   }
   
   void pr() {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cout << v[i*m+j] << ' ';
         }
         cout << '\n';
      }
      cout << '\n';
   };

   friend matrica operator * ( matrica A, matrica B ) {
      matrica C( A.n, B.m );
      for( int i = 0; i < C.n; ++i )
         for( int j = 0; j < C.m; ++j ) {
            C(i,j) = 0;
            for( int k = 0; k < A.m; ++k ) {
               C(i,j) += A(i,k) * B(k,j);
               C(i,j) %= MOD;
            }
         }
      return C;
   }

   friend matrica operator ^ ( matrica A, int k ) {
      if( k == 1 ) return A;
      if( k%2 == 1 ) return A * (A ^ (k-1));
      matrica ret = A ^ (k/2);
      return ret * ret;
   }
};

vector<string> program;
int line;

pair<matrica, int> solve( matrica matrix ) {
   matrica trans( 27, 27 );
   for( int i = 0; i < 27; ++i ) trans(i,i) = 1;
   int print = 0;

   for( ;; ) {
      istringstream iss( program[line++] );
      string s;
      iss >> s;
      if( s == "STOP" ) break;
      else if( s == "REPEAT" ) {
         int n;
         iss >> n;

         int pamti = line;
         pair<matrica, int> t = solve( trans*matrix );
         // cout << "line: " << pamti - 1 << '\n';
         // t.first.pr();
         print |= t.second;

         if( t.second == 1 ) {
            trans = t.first * trans;
            for( int i = 1; i < n; ++i ) {
               line = pamti;
               trans = solve( trans*matrix ).first * trans;
            }
         } else {
            trans = (t.first ^ n) * trans;
         }
      } else if( s == "PRINT" ) {
         // continue;
         print = 1;
         string var;
         iss >> var;
         cout << var << " = " << mod( (trans*matrix)(var[0]-'a',0) ) << endl;
      } else {
         matrica izraz( 27, 27 );
         for( int i = 0; i < 27; ++i ) izraz(i,i) = 1;
         izraz(s[0]-'a',s[0]-'a') = 0;

         string op, var;
         while( iss >> op >> var ) {
            int k = 1;
            int v = 26;
            if( isalpha( var[var.size()-1] ) ) v = var[var.size()-1]-'a';
            if( var[0] == '-' || isdigit( var[0] ) ) sscanf( var.c_str(), "%d", &k );
            if( op == "-" ) k *= -1;
            izraz( s[0]-'a', v ) += k;
         }
         trans = izraz * trans;
      }
   }
   return make_pair( trans, print );
}

int main( void ) {
   matrica matrix( 27, 1 );
   matrix(26,0) = 1;

   for( string s; getline( cin, s ); program.push_back( s ) );

   line = 1;
   solve( matrix );

   return 0;
}
