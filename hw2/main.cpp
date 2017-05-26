#include <iostream>
#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger( long value )
{
   for ( int i = 0; i < 40; ++i )
      integer[ i ] = 0;   

   for ( int j = 39; value != 0 && j >= 0; --j ) 
   {
      integer[ j ] = static_cast< short >( value % 10 );
      value /= 10;
   }
}

HugeInteger::HugeInteger( const string &string )
{
   input( string );
}

HugeInteger HugeInteger::add( const HugeInteger &op2 ) const
{
   HugeInteger temp;
   int carry = 0;

   for ( int i = 39; i >= 0; --i ) 
   {
      temp.integer[ i ] = integer[ i ] + op2.integer[ i ] + carry;

      if ( temp.integer[ i ] > 9 ) 
      {
         temp.integer[ i ] %= 10;
         carry = 1;
      }
      else
         carry = 0;
   }

   return temp;
}

HugeInteger HugeInteger::add( int op2 ) const
{ 
   return add( HugeInteger( op2 ) ); 
}
 
HugeInteger HugeInteger::add( const string &op2 ) const
{ 
   return add( HugeInteger( op2 ) ); 
}

HugeInteger HugeInteger::subtract( const HugeInteger & op2 ) const
{
   if ( isLessThan( op2 ) ) 
   {
      cout << "Error: Tried to subtract larger value from smaller value."
         << endl;
      return HugeInteger( "0" );
   }

   HugeInteger result( "0" );

   bool minusOne = false;

   for ( int i = 39; i >= 0; --i )
   {
      int topValue = integer[ i ];
      int bottomValue = op2.integer[ i ];

      if ( minusOne ) 
      {
         if ( topValue == 0 )
            topValue = 9; 
         else
         {
            topValue -= 1;
            minusOne = false;
         }
      }

      if ( topValue >= bottomValue ) 
         result.integer[ i ] = topValue - bottomValue;
      else
      {
         topValue += 10;
         minusOne = true;

         result.integer[ i ] = topValue - bottomValue;
      }
   }

   return result;
}

HugeInteger HugeInteger::subtract( int op2 ) const
{ 
   return subtract( HugeInteger( op2 ) ); 
}

HugeInteger HugeInteger::subtract( const string &op2 ) const
{ 
   return subtract( HugeInteger( op2 ) ); 
}

bool HugeInteger::isEqualTo( const HugeInteger & x ) const
{
   for ( int i = 39; i >= 0; --i ) 
      if ( integer[ i ] != x.integer[ i ] )
         return false;

   return true;   
}
 
bool HugeInteger::isNotEqualTo( const HugeInteger & x ) const
{
   return !( isEqualTo( x ) ); 
}

bool HugeInteger::isGreaterThan( const HugeInteger & x ) const
{  
   return ( x.isLessThan( *this ) );
}

bool HugeInteger::isLessThan( const HugeInteger & x ) const
{  
   for ( int i = 0; i < 40; ++i )
      if ( integer[ i ] > x.integer[ i ] )
         return false;
      else if ( integer[ i ] < x.integer[ i ] )
         return true;
         
   return false;
}

bool HugeInteger::isGreaterThanOrEqualTo( const HugeInteger & x ) const
{
   return ( !isLessThan( x ) );
}

bool HugeInteger::isLessThanOrEqualTo( const HugeInteger & x ) const
{
   return ( isEqualTo( x ) || isLessThan( x ) );
}

bool HugeInteger::isZero() const
{
   for (int i = 0; i < 40; ++i )
      if ( integer[ i ] != 0 )
         return false;
         
   return true;
}

void HugeInteger::input( const string &val )
{
   for ( int i = 0; i < 40; ++i )
      integer[ i ] = 0;

   int length = val.size();

   for ( int j = 40 - length, k = 0; j < 40; ++j, ++k )

      if ( isdigit( val[ k ] ) )
         integer[ j ] = val[ k ] - '0';
}

void HugeInteger::output() const
{
   int i;

   for ( i = 0; ( i < 40 ) && ( integer[ i ] == 0 ); ++i )
      ;

   if ( i == 40 )
      cout << 0;
   else
      for ( ; i < 40; ++i )
         cout << integer[ i ];
}

int main()
{
   HugeInteger n1( 9798585 );
   HugeInteger n2( "100000000000000" );
   HugeInteger n3;
   HugeInteger n4( 5 );
   HugeInteger n5; 
   
   n5 = n1.add( n2 );  
   n1.output();               
   cout << " + ";         
   n2.output(); 
   cout << " = "; 
   n5.output();
   cout << "\n\n";   

   n5 = n2.subtract( n4 );
   n2.output();
   cout<< " - ";
   n4.output();
   cout << " = ";
   n5.output();
   cout << "\n\n";
    
   if ( n2.isEqualTo( n2 ) == true )
   { 
      n2.output(); 
      cout << " is equal to ";
      n2.output(); 
      cout << "\n\n"; 
   }

   if ( n1.isNotEqualTo( n2 ) == true )
   {
      n1.output(); 
      cout << " is not equal to ";
      n2.output(); 
      cout << "\n\n";  
   }

   if ( n2.isGreaterThan( n1 ) == true )
   {
      n2.output(); 
      cout << " is greater than ";
      n1.output(); 
      cout << "\n\n";  
   }

   if ( n4.isLessThan( n2 ) == true )
   {
      n4.output(); 
      cout << " is less than ";
      n2.output(); 
      cout << "\n\n";  
   } // end if 
    
   if ( n4.isLessThanOrEqualTo( n4 ) == true )
   {
      n4.output(); 
      cout << " is less than or equal to ";
      n4.output(); 
      cout << "\n\n";  
   }

   if ( n4.isLessThanOrEqualTo( n2 ) == true )
   {
      n4.output(); 
      cout << " is less than or equal to ";
      n2.output(); 
      cout << "\n\n";  
   }

   if ( n3.isGreaterThanOrEqualTo( n3 ) == true )
   {
      n3.output(); 
      cout << " is greater than or equal to ";
      n3.output(); 
      cout << "\n\n";  
   }
    
   if ( n2.isGreaterThanOrEqualTo( n3 ) == true )
   {
      n2.output(); 
      cout << " is greater than or equal to ";
      n3.output(); 
      cout << "\n\n";  
   }
    
   if ( n3.isZero() == true )
   {
      cout << "n3 contains ";
      n3.output();
      cout << "\n\n";  
   }

   return 0;
}