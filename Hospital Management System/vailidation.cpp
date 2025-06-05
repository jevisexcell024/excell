#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int age;
    string phone;

    Patient(string name, int age, string phone)
        : name(name), age(age), phone(phone) {}
};

class Doctor {
public:
    int id;
    string name;
    string specialty;

    Doctor(int id, string name, string specialty)
        : id(id), name(name), specialty(specialty) {}
};

class Appointment {
public:
    Patient patient;
    Doctor doctor;
    string date;
    bool isPaid;

    Appointment(Patient patient, Doctor doctor, string date, bool isPaid)
        : patient(patient), doctor(doctor), date(date), isPaid(isPaid) {}
};

class HospitalSystem {
private:
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    HospitalSystem() {
        doctors.push_back(Doctor(1, "Dr. Smith", "Cardiologist"));
        doctors.push_back(Doctor(2, "Dr. Johnson", "Neurologist"));
        doctors.push_back(Doctor(3, "Dr. Patel", "Pediatrician"));
    }

    void showDoctors() {
        cout << "\nAvailable Doctors:\n";
        for (const auto& doc : doctors) {
            cout << doc.id << ". " << doc.name << " - " << doc.specialty << endl;
        }
    }

    Doctor* getDoctorById(int id) {
        for (auto& doc : doctors) {
            if (doc.id == id)
                return &doc;
        }
        return nullptr;
    }

    void bookAppointment() {
        string name, phone, date;
        int age, doctorId;
        char payNow;

        cout << "\n--- Book Appointment ---\n";
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter phone: ";
        cin >> phone;

        showDoctors();
        cout << "Enter doctor ID to book: ";
        cin >> doctorId;

        Doctor* selectedDoctor = getDoctorById(doctorId);
        if (!selectedDoctor) {
            cout << "Invalid doctor ID!\n";
            return;
        }

        cout << "Enter appointment date (e.g., 2025-06-05): ";
        cin >> date;

        cout << "Pay appointment fee of $50? (y/n): ";
        cin >> payNow;

        if (payNow == 'y' || payNow == 'Y') {
            cout << "Payment successful.\n";
            Patient p(name, age, phone);
            appointments.push_back(Appointment(p, *selectedDoctor, date, true));
            cout << "Appointment booked successfully!\n";
        } else {
            cout << "Payment required to confirm appointment.\n";
        }
    }

    void viewAppointments() {
        cout << "\n--- All Appointments ---\n";
        if (appointments.empty()) {
            cout << "No appointments booked yet.\n";
            return;
        }

        for (size_t i = 0; i < appointments.size(); ++i) {
            const auto& app = appointments[i];
            cout << i + 1 << ". " << app.patient.name << " | " << app.doctor.name
                 << " | " << app.date << " | Paid: " << (app.isPaid ? "Yes" : "No") << endl;
        }
    }
};


int main() {
    HospitalSystem hs;
    int choice;

    while (true) {
        // cout << "\n=== Hospital Management System ===\n";
        cout << "1. Book Appointment\n";
        cout << "2. View Appointments\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hs.bookAppointment();
            break;
        case 2:
            hs.viewAppointments();
            break;
        case 3:
            cout << "Do come again anytime\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
