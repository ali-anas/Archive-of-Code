class Polynomial
{
    private :
        int *degCoeff;
        int capacity;

    public :
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

        Polynomial(int newCapacity)
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
            //cout << "newCapacity : " << newCapacity <<endl;
            //cout << "minCapacity : " << minCapacity << endl;
            Polynomial newPoly(newCapacity);
            int i = 0;
            for( ; i < minCapacity; i++)
            {
                newPoly.degCoeff[i] = this -> degCoeff[i] + obj.degCoeff[i];
            }
            if(newCapacity == this -> capacity)
            {
                for( ; i < newCapacity; i++)
                {
                    newPoly.degCoeff[i] = this -> degCoeff[i];
                }
            }
            else if(newCapacity == obj.capacity)
            {
                for( ; i < newCapacity; i++)
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
                    newPoly.print();
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
            cout << "  capacity : " << this -> capacity;
            cout << "\n";
        }
};
