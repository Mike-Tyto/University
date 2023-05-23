#pragma once

class Complex {
private:
    double real_part;
    double img_part;
public:
    Complex():
        real_part(0),
        img_part(0)
    {}

    Complex(double rp, double ip):
        real_part(rp),
        img_part(ip)
    {}

    Complex(double rp):
        real_part(rp)
    {}

    ~Complex()
    {}

    Complex& operator= (const Complex& other) {
        real_part = other.real_part;
        img_part = other.img_part;
        return *this;
    }

    bool operator== (const Complex& other) {
        return real_part == other.real_part && img_part = other.img_part;
    }

    double GetRealPart() const noexcept {
        return this->real_part;
    }

    double GetImgPart() const noexcept {
        return this->img_part;
    }

// Sum
    friend Complex operator+ (const Complex& left, const Complex& right) {
        Complex copy = left;
        copy.real_part = left.real_part + right.real_part;
        copy.img_part = left.img_part + right.img_part;
        return copy;
    }

    friend Complex operator+ (const double& left, const Complex& right) {
        Complex copy = right;
        copy.real_part = left + right.real_part;
        return copy;
    }

    friend Complex operator+ (const Complex& left, const double& right) {
        Complex copy = left;
        copy.real_part = left.real_part + right;
        return copy;
    }

// difference
    friend Complex operator- (const Complex& left, const Complex& right) {
        Complex copy = left;
        copy.real_part = left.real_part - right.real_part;
        copy.img_part = left.img_part - right.img_part;
        return copy;
    }

    friend Complex operator- (const double& left, const Complex& right) {
        Complex copy = right;
        copy.real_part = left - right.real_part;
        copy.img_part = -right.img_part;
        return copy;
    }

    friend Complex operator- (const Complex& left, const double& right) {
        Complex copy = left;
        copy.real_part = left.real_part - right;
        return copy;
    }

// product
    friend Complex operator* (const Complex& left, const Complex& right) {
        Complex copy = left;
        copy.real_part = left.real_part * right.real_part - left.img_part * right.img_part;
        copy.img_part = left.img_part * right.real_part + right.img_part * left.real_part;
        return copy;
    }

    friend Complex operator* (const double& left, const Complex& right) {
        Complex copy = right;
        copy.real_part = left * right.real_part;
        copy.img_part = left * right.img_part;
        return copy;
    }

    friend Complex operator* (const Complex& left, const double& right) {
        Complex copy = left;
        copy.real_part = left.real_part * right;
        copy.img_part = left.img_part * right;
        return copy;
    }

// // division
//     friend Complex operator/ (const Complex& left, const Complex& right) {
//         Complex copy = left;
//         double buf = right.real_part * right.real_part - right.img_part * right.img_part; 
//         copy.real_part = left.real_part * right.real_part - left.img_part * right.img_part;
//         copy.img_part = left.img_part * right.real_part + right.img_part * left.real_part;
//         return copy;
//     }

//     friend Complex operator/ (const double& left, const Complex& right) {
//         Complex copy = right;
//         copy.real_part = left * right.real_part;
//         copy.img_part = left * right.img_part;
//         return copy;
//     }

//     friend Complex operator/ (const Complex& left, const double& right) {
//         Complex copy = left;
//         copy.real_part = left.real_part * right;
//         copy.img_part = left.img_part * right;
//         return copy;
//     }

    friend std::ostream& operator<< (std::ostream& os, Complex* complex) {
        if (complex->img_part == 0 && complex->real_part == 0) {
            os << 0;
        }
        else if (complex->img_part == 0) {
            os << complex->real_part;
        }
        else if (complex->real_part == 0){
            os << complex->real_part;
        }
        else if (complex->img_part > 0){
            os << complex->real_part << "+" << complex->img_part << "i";
        }
        else {
            os << complex->real_part << complex->img_part << "i";
        }
        return os;
    }
};

class Person {
private:
    int person_id;
    char* first_name;
    char* middle_name;
    char* last_name;
    int age;
public:
    Person():
        person_id(-1),
        first_name("None"),
        middle_name("None"),
        last_name("None"),
        age(-1)
    {}
 
    Person(int person_id, char* first_name, char* middle_name, char* last_name, int age):
        person_id(person_id),
        first_name(first_name),
        middle_name(middle_name),
        last_name(last_name),
        age(age)
    {}

    Person(const Person& person):
        person_id(person.person_id),
        first_name(person.first_name),
        middle_name(person.middle_name),
        last_name(person.last_name),
        age(person.age)
    {}

    ~Person()
    {}

    int GetId() const noexcept{
        return person_id;
    }

    char* GetFirstName() const noexcept{
        return first_name;
    }

    char* GetMiddleName() const noexcept{
        return middle_name;
    }

    char* GetLastName() const noexcept{
        return last_name;
    }
    int GetAge() const noexcept{
        return age;
    }

    friend std::ostream& operator<< (std::ostream& os, Person* person) {
        os << person->person_id << " " << person->first_name << " " << person->middle_name << " " << person->last_name << " " << person->age;
        return os;
    }

    bool EqualId(const Person& other) {
        return person_id == other.person_id;
    }

    bool EqualFN(const Person& other) {
        return first_name == other.first_name;
    }

    bool EqualMN(const Person& other) {
        return middle_name == other.middle_name;
    }

    bool EqualLN(const Person& other) {
        return last_name == other.last_name;
    }

    bool EqualAge(const Person& other) {
        return age == other.age;
    }

    bool operator== (const Person& other) {
        return EqualId(other) && EqualFN(other) && EqualMN(other) 
        && EqualLN(other) && EqualAge(other);
    }
};