#include <iostream>
#include <map>
#include <string>
#include <random>
#include <memory>
#include <windows.h>

using namespace std;

string get_rand_name() { // Просто випадкові імена
    vector<string> names = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Henry", "Ivy", "Jack"};

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, names.size() - 1);

    return names[distribution(generator)];
}

class Diseases {
private:
    map<string, int> prices{
            {"Filling",                      560},
            {"Root canal treatment",         340},
            {"Enamel whitening",             670},
            {"Tooth extraction",             890},
            {"Prosthetics and implantation", 540},
            {"Orthodontics",                 760},
            {"Cancer treatment",             980},
    }; //Ціни на процедури

    vector<string> Complaints{"Soreness", "Swelling", "Saliary glands", "Dry", "Dry mouth", "Salty taste",
                              "Unknown taste"}; //Випадкові жалоби

public:
    int calculate_prcie(string ill) {
        return prices[ill];//Ціна в халежності від процедури
    }

    string get_Complaint(int id) {//Отримати жалобу від ІН(Буде генеруватися випадково)
        if (id <= Complaints.size())
            return Complaints[id];
        cerr << "Wrong ID!";
        return Complaints[0];
    }

    int n_complaints() {//К-сть жалоб
        return Complaints.size() - 1;
    }
};

class Patient {
private:
    vector<string> complaints;//Жалоби
    vector<string> ilness;//Захворювання
    vector<string> procedures;//Процедури

    string doctor;
    string Name;

    int price;//К-сть витрачених грошей у поліклініці

    void set_complaints(vector<string> complaints) {//Додати жалоби
        for (string complaint: complaints) {
            this->complaints.push_back(complaint);
        }
    }

public:
    Patient() {//Випадкова генерація жалоб
        Diseases dis;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution numOf(1, 5);//Дистанція від 1 до 5 жалоб на пацієента
        uniform_int_distribution MaxCompl(0, dis.n_complaints());//Різні захворювання - дистанція
        int n = numOf(gen);
        for (int i = 0; i < n; i++) {
            int ID_Complaint = MaxCompl(gen);//Генеруємо жалобу
            complaints.push_back(dis.get_Complaint(ID_Complaint));//Додаємо жалобу
        }
        Name = get_rand_name();//Випадкове ім'я пацієнта
        price = 0;
    }

    Patient(vector<string> complaints, string Name) {
        set_complaints(complaints);
        this->Name = Name;
        price = 0;
    }

    Patient(string complaint, string Name) {
        this->complaints.push_back(complaint);
        this->Name = Name;
        price = 0;
    }

    vector<string> get_complaints() {
        return complaints;//Отримати всі жалоби
    }

    vector<string> get_illnesses() {
        return ilness;//Отримати заховрювання
    }

    vector<string> get_pocedures() {
        return procedures;//Отримати процедури
    }

    string get_name() {
        return Name;
    }

    int get_price() {
        return this->price;
    }

    void set_illneses(vector<string> illnesses) {//Задати захворювання(Це робить лікар)
        for (string ill: illnesses)
            this->ilness.push_back(ill);
    }

    void set_procedures(vector<string> procedures) {//Задати процедури(Це робить лікар)
        for (string procedure: procedures)
            this->procedures.push_back(procedure);
    }

    void set_price(int price) {//Задати к-ість грошей, що було витрачено(Це робить клініка)
        this->price = price;
    }

    void set_doctor(string doc) {//Задати ім'я лікаря
        this->doctor = doc;
    }
};

class Consultant {
private:
    map<string, string> Complaints{//Мапа жалоб та захворювань
            {"Soreness",       "Tooth decay"},
            {"Swelling",       "Gum disease"},
            {"Saliary glands", "Periodontitis"},
            {"Dry",            "Gingivitis"},
            {"Dry mouth",      "Oral thrush"},
            {"Salty taste",    "Tooth abscess"},
            {"Unknown taste",  "Tooth erosion"},
    };

    map<string, pair<string, string>> Treatment{//Мапа Захворювань та процедур для лікування
            {"Tooth decay",   {"Filling",              "Root canal treatment"}},
            {"Gum disease",   {"Root canal treatment", "Enamel whitening"}},
            {"Periodontitis", {"Cancer treatment",     "Enamel whitening"}},
            {"Gingivitis",    {"Cancer treatment",     "Prosthetics and implantation"}},
            {"Oral thrush",   {"Tooth extraction",     "Root canal treatment"}},
            {"Tooth abscess", {"Tooth extraction",     "Cancer treatment"}},
            {"Tooth erosion", {"Cancer treatment",     "Filling"}}
    };

    string Name;
    double margin;//Націнка лікаря

    vector<Patient> patients;

public:
    Consultant(string Name, double margin) {
        this->Name = Name;
        this->margin = margin;
    }

    void consult(Patient &patient) {
        vector<string> current_compl = patient.get_complaints();//Поточні жалоби
        vector<string> illnesses;
        for (string complaint: current_compl) {
            string ill = Complaints[complaint];//Відповідно до жалоб сказати пацієнту діагнози
            illnesses.push_back(ill);
        }
        patient.set_illneses(illnesses);//Передати пацієнту дігнози(Захворювання)
    }

    void create_treatment(Patient &patient) {
        vector<string> current_ill = patient.get_illnesses();
        vector<string> treatmnet;
        for (string ill: current_ill) {//Відповідно до захворюваннь створити курс ліквання(процедури)
            pair<string, string> treat = Treatment[ill];
            treatmnet.push_back(treat.first);
            treatmnet.push_back(treat.second);
        }

        patient.set_procedures(treatmnet);
        patient.set_doctor(this->Name);//Задати ім'я лікаря
    }

    double get_margin() {
        return margin;
    }

    vector<Patient> get_patients() {
        return patients;
    }

    string get_name() {
        return Name;
    }

    void add_patient(Patient &patient){//Список пацієнтів, що лікував цей лікар
        patients.push_back(patient);
    }
};

class Klinica : public Diseases {
private:
    void create_check(Patient &patient, Consultant &consul) {//СПідрахунок ціни відповідно до процедур
        vector<string> treatments = patient.get_pocedures();
        int price = 0;
        for (string treat: treatments) {
            price += calculate_prcie(treat) *
                     consul.get_margin(); // Підрахунок ціни за процедури відповідно до націнки лікаря.
        }
        if (price >= 2500) {
            price -= price * 0.05; //5% Знижка при ціні більше за 2500 грн
        }
        price += patient.get_price();//Те, що витратив пацієнт раніше
        patient.set_price(price);
        consul.add_patient(patient);
    }

public:
    void make_consultation(Patient &patient, Consultant &consul) {
        consul.consult(patient);//Консультація від лікаря
        consul.create_treatment(patient);//Створення курсу ліквання
        patient.set_price(500);//Ціна за консультацію

        create_check(patient, consul);//Створюємо ціни за процедури
    }

    void create_report(Consultant &consul) {//Красивий вивід звіту для кожно консультанта
        cout << "\n\n\tІм'я лікаря: " << consul.get_name();
        int prices = 0;
        vector<Patient> patients = consul.get_patients();

        sort(patients.begin(), patients.end(),[](Patient a, Patient b) { //Сортування пацієентів по їх витраченним грошам у клініці.
            return a.get_price() > b.get_price();
        });
        if(patients.empty()){
            cout << "\nНе має пацієентіів.";
            return;
        }
        cout << "\n\nСписок його пацієнтів: \n";
        for (int i = 0; i < patients.size(); i++) {
            cout << i + 1 << ") " << "\t" << patients[i].get_name();
            cout << "\nЗахворювання: ";
            vector<string> ilnesses = patients[i].get_illnesses();
            for (string ill: ilnesses) {
                cout << ill << "; ";
            }
            cout << "\nЦіна цого лікування: " << patients[i].get_price() << "$.";
            prices += patients[i].get_price();
            cout << "\n\n";
        }
        cout << "\nПрибуток клініки від цього лікаря: " << prices << "$.";
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    random_device rd;
    mt19937 gen(rd());

    const int N_consul = 3;
    shared_ptr<Consultant> consultants[N_consul]; //Массив лікарів

    consultants[0] = make_shared<Consultant>("Bob", 1.1);
    consultants[1] = make_shared<Consultant>("Roman", 1.5);
    consultants[2] = make_shared<Consultant>("Ivan", 0.9); //Заповнили масив лікарів

    uniform_int_distribution<int> consul_dis(0, N_consul - 1); //Діст лікарів
    uniform_int_distribution<int> patient_dis(25, 75);  //Діст пацієнтів

    int N_patients = patient_dis(gen);
    shared_ptr<Patient> Patients[N_patients];
    for (int i = 0; i < N_patients; i++) {
        Patients[i] = make_shared<Patient>(); //Згенеруванли пацієнтів
    }

    Klinica klinica;
    for (int i = 0; i < N_patients; i++) {
        int ranDoctor = consul_dis(gen);
        klinica.make_consultation(*Patients[i], *consultants[ranDoctor]);//Консультуємо кожного пацієнта
    }

    klinica.create_report(*consultants[0]);//Звіти до всіх лікарів
    klinica.create_report(*consultants[1]);
    klinica.create_report(*consultants[2]);

    return 0;
}