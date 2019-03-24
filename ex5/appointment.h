#ifndef _H_APPOINTMENT
#define _H_APPOINTMENT

#include <string>
#include <utility>

class DateTime {
   private:
    int hour, minute, second;

   public:
    DateTime(int hour = 0, int minute = 0, int second = 0);

    // TODO: getDay, getMonth, getYear

    int GetHour() const;

    int GetMinute() const;

    int GetSecond() const;

    bool operator==(const DateTime& other) const;

    bool operator!=(const DateTime& other) const;

    bool operator<(const DateTime& other) const;
    bool operator>(const DateTime& other) const;

    bool operator<=(const DateTime& other) const;
    bool operator>=(const DateTime& other) const;
};

class Person {
   private:
    std::string name;

   public:
    Person(const std::string& name);
   
    std::string getName() const;
};

class Appointment {
   private:
    std::string description;
    Person* participants;
    DateTime start;
    DateTime end;

   public:
    // constructors:
    // default constructor
    Appointment();

    Appointment(const std::string& description, const DateTime& start, const DateTime& end);

    Appointment(const Appointment& other);

    ~Appointment();

    Appointment& operator=(const Appointment& other);

    void SetDescription(const char* pDescription);

    char const* GetDescription() const;

    DateTime GetStart() const;
    DateTime GetEnd() const;
    DateTime GetLength() const;

    Person* getParticipants() const;
    void addParticipant(const Person& participant);
};

#endif
