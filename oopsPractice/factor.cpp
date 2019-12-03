class Factor
{
    private :
      int numerator;
      int denominator;
    public :
      Factor(int numerator, int denominator)
      {
          this -> numerator = numerator;
          this -> denominator = denominator;
      }
      void print()
      {
          cout << this -> numerator << " / " << this -> denominator << endl;
      }

      int getGcd()
      {
          int a = this -> numerator;
          int b = this -> denominator;
          while(b != 0)
          {
              int rem = a % b;
              a = b;
              b = rem;
          }
          return a;
      }

      /*
      ADD
          5      7      x * 5 + y * 7     x = denominator1 / 12 * 12(denominator of ans)
         ---  + ---  =  -------------     y = denominator2 / 12 * 12(denominator of ans)
          12     12       12 * 12
      */

      void add(const Factor &obj)
      {
          int mul = this -> denominator * obj.denominator;
          int x = mul / this -> denominator;
          int y = mul / obj.denominator;
          this -> numerator = (x * this -> numerator) + (y * obj.numerator);
          this -> denominator = mul;
          int gcd = getGcd();
          this -> numerator /= gcd;
          this -> denominator /= gcd;
      }
};
