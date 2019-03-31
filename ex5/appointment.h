#ifndef _H_APPOINTMENT
#define _H_APPOINTMENT

#include <string>
#include <utility>

/* 
The class represents a specific instant in time.
*/
class DateTime
{
private:
   // int day, month, year;
	int second, minute, hour;
public:
	DateTime(int second = 0, int minute = 0, int hour = 0)
		: second(second), minute(minute), hour(hour)
	{
	}
    // TODO: getDay, getMonth, getYear

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void setHour(int hour) {
		this->hour = hour;
	}
	void setMinute(int minute) {
		this->minute = minute;
	}
	void setSecond(int second) {
		this->second = second;
	}

    std::string to_string() const {
        return std::to_string(this->hour) + ":" + std::to_string(this->minute) + ":" + std::to_string(this->second);
    }
};

class Person {
private:
	std::string name;
public:
	Person(std::string name="") : name(name) {}
   
    std::string getName() const {
        return this->name;
    }
    
    std::string to_string() const {
        return this->name;
    }
};

class Appointment {
private: 
	std::string description;
	DateTime start;
	DateTime end;
	Person *participants;
	int participants_length;

private:
	void copy(Person* destination, const Person* source, int length) {
		for (int i = 0; i < length; ++i) {
			destination[i] = source[i];
		}
	}

public: 
	Appointment()
	{
		this->participants_length = 0;
		this->participants = new Person[this->participants_length];
	}

	Appointment(const std::string& description,
		const DateTime& start, const DateTime& end)
		: description(description),
		  start(start),
		  end(end)
	{
		this->participants_length = 0;
		this->participants = new Person[this->participants_length];
	}

	Appointment(const Appointment& other)
		: description(other.description),
		  start(other.start),
		  end(other.end) {
		this->participants_length = other.participants_length;
		this->participants = new Person[this->participants_length];
		copy(this->participants, other.participants, other.participants_length);
	}

	~Appointment() {
		delete[] this->participants;
	}

	Appointment& operator=(const Appointment& other) {
		if (this != &other) { // self-assignment check expected
			this->description = other.description;
			this->start = other.start;
			this->end = other.end;
			this->participants_length = other.participants_length;
			delete[] this->participants;
			this->participants = new Person[other.participants_length];
			copy(this->participants, other.participants, other.participants_length);
		}
		return *this;
	}

	std::string getDescription() const;
	DateTime getStart() const;
	DateTime getEnd() const;
	std::string getPlace() const;

	const Person* getParticipants() const {
		return this->participants;
	}

	void eraseParticipant(Person p) {
	}

	void addParticipant(Person p) {
       	 	// create new array to help the new participant
        	int newParticipantsLength = this->participants_length + 1;
		Person *newParticipants = new Person[newParticipantsLength];
        	// copy the old participants
		copy(newParticipants, this->participants, this->participants_length);
        	// add the new participant
		newParticipants[newParticipantsLength - 1] = p;
		delete []this->participants;
		this->participants_length = newParticipantsLength;
		this->participants = newParticipants;
	}

    std::string to_string() const {
        std::string s;
        s.append("description = ").append(this->description).append("\n");
        s.append("start = ").append(this->start.to_string()).append("\n");
        s.append("end = ").append(this->end.to_string()).append("\n");
        s.append("[");
        for (int i = 0; i < this->participants_length; ++i) {
            s.append(this->participants[i].to_string()).append(", ");
		}
        s.append("]");

        return s;
    }
};



#endif
