#include <array>
#include <string>

class HugeInteger 
{
public:
   HugeInteger( long = 0 );
   HugeInteger( const std::string & );

   HugeInteger add( const HugeInteger & ) const;
   HugeInteger add( int ) const;            
   HugeInteger add( const std::string & ) const;    

   HugeInteger subtract( const HugeInteger &  ) const; 

   HugeInteger subtract( int ) const; 

   HugeInteger subtract( const std::string & ) const; 

   bool isEqualTo( const HugeInteger &  ) const;
   bool isNotEqualTo( const HugeInteger &  ) const;
   bool isGreaterThan( const HugeInteger &  ) const;
   bool isLessThan( const HugeInteger &  ) const;
   bool isGreaterThanOrEqualTo( const HugeInteger &  ) const;
   bool isLessThanOrEqualTo( const HugeInteger &  ) const;
   bool isZero() const;
   void input( const std::string & );
   void output() const;
private:
   std::array< short, 40 > integer;
};