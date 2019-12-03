class Student
{
        const int rollNumber;
    public :
        int age;
        char *name;
          // for practicing initialization list

        // default constructor at least needed age name and rollnumber to create new object.
        Student(int r, int age, char *name):rollNumber(r)  // initialization at time of creation is needed for constant members and for refrences.
        {
            this -> age = age;
            //this -> name = name;
            /* shallow copy- stores pointer to actual array
               which can be changed by the time
               from anywhere else in program*/
            this -> name = new char[strlen(name) + 1];
            strcpy(this -> name, name);
        }

        int getAge(void) const
        {
            return this -> age;
        }

        int getRoll(void) const
        {
            return this -> rollNumber;
        }

        // DISPLAY function to display properties of class.
        void display() const
        {
            cout << name << " " << age << " " << rollNumber << endl;
        }

        // Student s = s1; COPY CONSTRUCTOR.

        Student(const Student &obj):rollNumber(obj.rollNumber)
        {
            //this -> rollNumber = obj.rollNumber;
            this -> age = obj.age;
            this -> name = new char[strlen(obj.name) + 1];
            strcpy(this -> name, obj.name);
        }
};
