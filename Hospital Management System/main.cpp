#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;



class Patient {
    public:
    string name;
    int age;
    string dob;
    string gender;
    string issue;

    Patient(string n,int a, string D, string g, string is) :name(n), age(a), dob(D), gender(g), issue(is) {}
};

class Doctor {
    public:
    string name;
    string Specialty;

    Doctor(string n,string s):name(n),Specialty(s){}
};

class Appointment {
    public:
    Patient patient;
    Doctor doctor;
    string date_time;

    Appointment(Patient p,Doctor d,string dt):patient(p),doctor(d),date_time(dt){}
};

class Billing {
    public:
    Patient patient;
    double amount;
    bool paid;

    Billing(Patient p,double amt):patient(p),amount(amt),paid(false){}
    void processBill() {paid=true;}
};

class Hospital {
    private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    vector<Billing> bills;

    public:
    void addPatient(const Patient& p) {patients.push_back(p);}

    void addDoctor(const Doctor& d) {
        doctors.push_back(d);
    }

    void scheduleAppointment(const Patient& p,const Doctor& d,const string& dt) {
        appointments.emplace_back(p,d,dt);
    }

    void processBill(const Patient& p,double amt) {
        bills.emplace_back(p,amt);
    }

    void viewPatients() {
        for(const auto& p:patients) {
            cout<<p.name<<"Age"<<p.age<<"DOB "<<p.dob<<"Gender"<<p.gender<<"Issue"<<p.issue<<endl;
        }
    }

};







int main() {
   Hospital hospital;

    string name,DOB,gender,issue;
    int age;

    cout<<"Enter your name:";
    cin>>name;

    cout<<"Enter your age:";
    cin>>age;

    cin.ignore();
    cout<<"Enter your DOB:";

    getline(cin,DOB);

    cout<<"Enter your Gender(male/female):";
    getline(cin,gender);

    cout<<"What is wrong with you";
    getline(cin,issue);

    Patient newPatient(name,age,DOB,gender,issue);
    hospital.addPatient(newPatient);

    hospital.viewPatients();
    return 0;
}
