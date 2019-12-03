class Polynomial {
  public:
  int *degCoeff;// Name of your array (Don't change this)
  int size;
  // Complete the class
  //default constructor
  Polynomial(){
    degCoeff=new int[10];
     size=10;
    for(int j=0;j<10;j++)
      degCoeff[j]=0;
  }


  //copy constructor
  Polynomial(Polynomial const & p2){
    this->degCoeff=new int[p2.size];
    for(int i=0;i<p2.size;i++)
      this->degCoeff[i]=p2.degCoeff[i];
    this->size=p2.size;
  }


  //copy assignment
  void operator=(Polynomial const & p2){
    delete []degCoeff;
    this->degCoeff=new int[p2.size];
    for(int i=0;i<p2.size;i++)
      this->degCoeff[i]=p2.degCoeff[i];
    this->size=p2.size;
  }


  //printf
  void print() const{
    for(int j=0;j<size;j++){
      if(degCoeff[j]!=0){
        cout<<degCoeff[j]<<"x"<<j<<" ";
      }
    }
    cout<<endl;
  }


  //set coefficient
  void setCoefficient(int deg,int coeff){
    if(deg>=size){
      int cap=2*size;
      while(cap<=deg){
        cap=cap*2;
      }
      int *newarr=new int[cap];
      for(int j=0;j<cap;j++)
        newarr[j]=0;
      for(int j=0;j<size;j++)
        newarr[j]=degCoeff[j];
      size=cap;
      delete []degCoeff;
      degCoeff=newarr;
    }
    degCoeff[deg]=coeff;
  }


  //+ operator
  Polynomial operator+(Polynomial const & p2){
    Polynomial result;
    int i=0,j=0;
    while(i<this->size && j<p2.size){
      int deg=i;
      int coeff=degCoeff[i]+p2.degCoeff[j];
      result.setCoefficient(deg,coeff);
      i++;
      j++;
    }
    while(i<size)
    {
      result.setCoefficient(i,degCoeff[i]);
      i++;
    }
    while(j<p2.size)
    {
      result.setCoefficient(j,p2.degCoeff[j]);
      j++;
    }
    return result;
  }


  //- operator
  Polynomial operator-(Polynomial const & p2){
    Polynomial result;
    int i=0,j=0;
    while(i<this->size && j<p2.size){
      int deg=i;
      int coeff=degCoeff[i]-p2.degCoeff[j];
      result.setCoefficient(deg,coeff);
      i++;
      j++;
    }
    while(i<size)
    {
      result.setCoefficient(i,degCoeff[i]);
      i++;
    }
    while(j<p2.size)
    {
      result.setCoefficient(j,(-1*p2.degCoeff[j]));
      j++;
    }
    return result;

  }

  
  int getcoeff(int degree)
  {
    if(degree>=size)
      return 0;
    return degCoeff[degree];
  }


  //* operator
  Polynomial operator*(Polynomial const & p2){
    Polynomial result;
    for(int j=0;j<p2.size;j++)
    {
      for(int i=0;i<size;i++)
      {
        int deg=i+j;
        int coeff=result.getcoeff(i+j) + (degCoeff[i]*p2.degCoeff[j]);
        result.setCoefficient(deg,coeff);

      }
    }
    return result;
  }
};
















class Polynomial {
    public :
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
        // default CONSTRUCTOR
        Polynomial()
        {
            this -> degCoeff = new int[5];
            this -> capacity = 5;
            for(int i = 0; i < capacity; i++)
            {
                this -> degCoeff[i] = 0;
            }
        }

        Polynomial(Polynomial const &obj)
        {
            this -> capacity = obj.capacity;
            this -> degCoeff = new int[this -> capacity];
            for(int i = 0; i < this -> capacity; i++)
            {
                this -> degCoeff[i] = obj.degCoeff[i];
            }
        }

        Polynomial (int newCapacity)
        {
            this -> capacity = newCapacity;
            this -> degCoeff = new int[this -> capacity];
            for(int i = 0; i < this -> capacity; i++)
            {
                this -> degCoeff[i] = 0;
            }
        }

        void setCoefficient(int deg, int coeff)
        {

            if(deg > this -> capacity-1)
            {
                int prevCapacity = this -> capacity;
                while(deg > (this -> capacity-1))
                {
                    this -> capacity += 5;
                }
                int *newDegCoeff = new int[this -> capacity];
                for(int i = 0; i < prevCapacity; i++)
                {
                    newDegCoeff[i] = this -> degCoeff[i];
                }
                for(int i = prevCapacity; i < this -> capacity; i++)
                {
                    newDegCoeff[i] = 0;
                }
                delete []degCoeff;
                degCoeff = newDegCoeff;
            }
            this -> degCoeff[deg] = coeff;
        }

        void setCoefficient1(int deg, int coeff)
        {

            if(deg > this -> capacity-1)
            {
                int prevCapacity = this -> capacity;
                while(deg > (this -> capacity-1))
                {
                    this -> capacity += 5;
                }
                int *newDegCoeff = new int[this -> capacity];
                for(int i = 0; i < prevCapacity; i++)
                {
                    newDegCoeff[i] = this -> degCoeff[i];
                }
                for(int i = prevCapacity; i < this -> capacity; i++)
                {
                    newDegCoeff[i] = 0;
                }
                delete []degCoeff;
                degCoeff = newDegCoeff;
            }
            this -> degCoeff[deg] += coeff;
        }

        // overloading '-' operator
        Polynomial operator-(Polynomial const &obj)
        {
            int newCapacity = this -> capacity > obj.capacity ? this -> capacity : obj.capacity;
            int minCapacity = (newCapacity == this -> capacity) ? obj.capacity : this -> capacity;
            Polynomial newPoly(newCapacity);
            if(newCapacity == this -> capacity)
            {
                int i = 0;
                for( ; i < minCapacity; i++)
                {
                    newPoly.degCoeff[i] = this -> degCoeff[i] - obj.degCoeff[i];
                }
                for( ; i < newCapacity; i++)
                {
                    newPoly.degCoeff[i] = this -> degCoeff[i];
                }
            }
            else if(newCapacity == obj.capacity)
            {
                int i = 0;
                for(; i < minCapacity; i++)
                {
                    newPoly.degCoeff[i] = obj.degCoeff[i] - this -> degCoeff[i];
                }
                for(; i < newCapacity; i++)
                {
                    newPoly.degCoeff[i] = obj.degCoeff[i];
                }
            }
            return newPoly;
        }

        // overloading '+' operator
        Polynomial operator+(Polynomial const &obj)
        {
            int newCapacity = this -> capacity > obj.capacity ? this -> capacity : obj.capacity;
            int minCapacity = (newCapacity == this -> capacity) ? obj.capacity : this -> capacity;
            Polynomial newPoly(newCapacity);
            for(int i = 0; i < minCapacity; i++)
            {
                newPoly.degCoeff[i] = this -> degCoeff[i] + obj.degCoeff[i];
            }
            if(newCapacity == this -> capacity)
            {
                for(int i = minCapacity; i < newCapacity; i++)
                {
                    newPoly.degCoeff[i] = this -> degCoeff[i];
                }
            }
            else if(newCapacity == obj.capacity)
            {
                for(int i = minCapacity; i < newCapacity; i++)
                {
                    newPoly.degCoeff[i] = obj.degCoeff[i];
                }
            }
            return newPoly;
        }

        // overloading '*' operator.
        Polynomial operator*(Polynomial const &obj)
        {
            Polynomial newPoly;
            for(int i = 0; i < this -> capacity; i++)
            {
                for(int j = 0; j < obj.capacity; j++)
                {
                    int deg = i + j;
                    int coeff = this -> degCoeff[i] * obj.degCoeff[j];
                    newPoly.setCoefficient1(deg,coeff);
                }
            }
            return newPoly;
        }

        // overloading '=' operator.
        Polynomial operator=(Polynomial const &obj)
        {
            this -> capacity = obj.capacity;
            this -> degCoeff = new int[this -> capacity];
            for(int i = 0; i < this -> capacity; i++)
            {
                this -> degCoeff[i] = obj.degCoeff[i];
            }
        }

        void print() const
        {
            for(int i = 0; i < this -> capacity; i++)
            {
                if(this -> degCoeff[i] != 0)
                {
                    cout << this -> degCoeff[i] << 'x' << i << " ";
                }
            }
            // cout << "  capacity : " << this -> capacity;
            cout << "\n";
        }
    
};