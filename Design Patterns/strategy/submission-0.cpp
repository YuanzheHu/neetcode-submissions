class Person {
private:
    string lastName;
    int age;
    bool married;

public:
    Person(string lastName, int age, bool married) 
        : lastName(lastName), age(age), married(married) {}

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    bool isMarried() {
        return married;
    }
};

class PersonFilter {
public:
    virtual ~PersonFilter() {}
    virtual bool apply(Person& person) = 0;
};

class AdultFilter : public PersonFilter {
    // Implement Adult filter
    bool apply(Person& person) override {
        return person.getAge() >= 18;
    }
};

class SeniorFilter : public PersonFilter {
    // Implement Senior filter
    bool apply(Person& person) override {
        return person.getAge() >= 65;
    }
};

class MarriedFilter : public PersonFilter {
    // Implement Married filter
    bool apply(Person& person) override {
        return person.isMarried();
    }
};

class PeopleCounter {
private:
    PersonFilter *filter;

public:
    void setFilter(PersonFilter &filter) {
        this->filter = &filter;
    }

    int count(vector<Person> &people) {
        // Implement method here
        int count = 0;
        for (auto &person : people){
            if (filter->apply(person)){
                count++;
            }
        }
        return count;
    }
};

// List<Person> people = Arrays.asList(
//   new Person("Doe", 20, false),
//   new Person("Smith", 30, true),
//   new Person("Old", 70, true)
// );

// PeopleCounter counter = new PeopleCounter();

// ;counter.setFilter(new AdultFilter())
// counter.count(people); // Adult count: 3

// counter.setFilter(new SeniorFilter());
// counter.count(people); // Senior count: 1

// counter.setFilter(new MarriedFilter());
// counter.count(people); // Married count: 2

