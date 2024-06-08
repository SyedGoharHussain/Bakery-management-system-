#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// ANSI Escape Codes for colors and styles
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string ITALIC = "\033[3m";
const string UNDERLINE = "\033[4m";
const string REVERSED = "\033[7m";

// Colors
const string ORANGE = "\033[38;5;214m";
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

class Employee
{
protected:
    int idNo;
    string name;
    float salary;
    string shift;

public:
    Employee() : idNo(0), name(" "), salary(0), shift(" ") {}
    Employee(int id, string n, float s, string sh) : idNo(id), name(n), salary(s), shift(sh) {}
    virtual void display()
    {
        cout << BOLD << GREEN << "Employee ID : " << idNo << RESET << endl;
        cout << BOLD << GREEN << "Employee Name : " << name << RESET << endl;
        cout << BOLD << GREEN << "Employee Salary : " << salary << RESET << endl;
        cout << BOLD << GREEN << "Employee Shift : " << shift << RESET << endl;
    }
    // Getters
    int getIdNo() { return idNo; }
    string getName() { return name; }
    float getSalary() { return salary; }
    string getShift() { return shift; }
    string getType() { return "Employee"; }
};

class Manager : public Employee
{
protected:
    int teamSize;
    float performanceScore;

public:
    Manager() : teamSize(0), performanceScore(0) {}
    Manager(int id, string n, float s, string sh, int ts, float ps) : Employee(id, n, s, sh), teamSize(ts), performanceScore(ps) {}
    void display()
    {
        Employee::display();
        cout << BOLD << BLUE << "Manager Team Size : " << teamSize << RESET << endl;
        cout << BOLD << BLUE << "Manager Performance Score : " << performanceScore << RESET << endl;
    }
    // Getters
    string getType() { return "Manager"; }
    int getTeamSize() { return teamSize; }
    float getPerformanceScore() { return performanceScore; }
};

class Baker : public Employee
{
protected:
    string speciality;

public:
    Baker() : speciality(" ") {}
    Baker(int id, string n, float s, string sh, string sp) : Employee(id, n, s, sh), speciality(sp) {}
    void display()
    {
        Employee::display();
        cout << BOLD << YELLOW << "Baker Speciality : " << speciality << RESET << endl;
    }
    // Getters
    string getSpeciality() { return speciality; }
    string getType() { return "Baker"; }
};

class Worker : public Employee
{
protected:
    string department;

public:
    Worker() : department(" ") {}
    Worker(int id, string n, float s, string sh, string dep) : Employee(id, n, s, sh), department(dep) {}
    void display()
    {
        Employee::display();
        cout << BOLD << CYAN << "Worker Department : " << department << RESET << endl;
    }
    // Getters
    string getDepartment() { return department; }
    string getType() { return "Worker"; }
};

class EmployeeManagement
{
private:
    Employee *employees[100];
    int totalEmployees;

public:
    EmployeeManagement() : totalEmployees(0) {}
    void add_record()
    {
        int count;
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************ADDING EMP**************|\n"
             << RESET;
        cout << YELLOW << "How Many Employees do you want to Add: " << RESET;
        cin >> count;

        for (int i = 0; i < count; i++)
        {
            int choice;
            cout << CYAN << BOLD << ITALIC << "\n1. Employee" << RESET << RESET << endl;
            cout << CYAN << BOLD << ITALIC << "2. Manager" << RESET << endl;
            cout << CYAN << BOLD << ITALIC << "3. Baker" << RESET << endl;
            cout << CYAN << BOLD << ITALIC << "4. Worker" << RESET << endl;
            cout << YELLOW << BOLD << "Enter your choice: " << RESET;
            cin >> choice;
            if (choice == 1)
            {
                int id;
                string name;
                float salary;
                string shift;
                cout << GREEN << BOLD << ITALIC << "Enter the details of the Employee:" << endl;
                cout << MAGENTA << BOLD << "Id: " << RESET;
                cin >> id;
                cout << MAGENTA << BOLD << "Name: " << RESET;
                cin >> name;
                cout << MAGENTA << BOLD << "Salary: " << RESET;
                cin >> salary;
                cout << MAGENTA << BOLD << "Shift: " << RESET;
                cin >> shift;
                employees[totalEmployees] = new Employee(id, name, salary, shift);
                totalEmployees++;
                store_record();
            }
            else if (choice == 2)
            {
                int id;
                string name;
                float salary;
                string shift;
                int teamSize;
                float performanceScore;
                cout << GREEN << BOLD << ITALIC << "Enter the details of the Manager:" << endl
                     << RESET;
                cout << MAGENTA << BOLD << "Id: " << RESET;
                cin >> id;
                cout << MAGENTA << BOLD << "Name: " << RESET;
                cin >> name;
                cout << MAGENTA << BOLD << "Salary: " << RESET;
                cin >> salary;
                cout << MAGENTA << BOLD << "Shift: " << RESET;
                cin >> shift;
                cout << MAGENTA << BOLD << "Team Size: " << RESET;
                cin >> teamSize;
                cout << MAGENTA << BOLD << "Performance Score: " << RESET;
                cin >> performanceScore;
                employees[totalEmployees] = new Manager(id, name, salary, shift, teamSize, performanceScore);
                totalEmployees++;
                store_record();
            }
            else if (choice == 3)
            {
                int id;
                string name;
                float salary;
                string shift;
                string speciality;
                cout << BOLD << ITALIC << GREEN << "Enter the details of the Baker:" << endl;
                cout << BOLD << MAGENTA << "Id: ";
                cin >> id;
                cout << BOLD << MAGENTA << "Name: ";
                cin >> name;
                cout << BOLD << MAGENTA << "Salary: ";
                cin >> salary;
                cout << BOLD << MAGENTA << "Shift: ";
                cin >> shift;
                cout << BOLD << MAGENTA << "Speciality: ";
                cin >> speciality;
                employees[totalEmployees] = new Baker(id, name, salary, shift, speciality);
                totalEmployees++;
                store_record();
            }
            else if (choice == 4)
            {
                int id;
                string name;
                float salary;
                string shift;
                string department;
                cout << "Enter the details of the Worker:" << endl;
                cout << "Id: ";
                cin >> id;
                cout << "Name: ";
                cin >> name;
                cout << "Salary: ";
                cin >> salary;
                cout << "Shift: ";
                cin >> shift;
                cout << "Department: ";
                cin >> department;
                employees[totalEmployees] = new Worker(id, name, salary, shift, department);
                totalEmployees++;
                store_record();
            }
        }
    }

    void store_record()
    {
        ofstream outfile("EmployeeInformation.txt", ios::app);
        if (!outfile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        for (int i = 0; i < totalEmployees; ++i)
        {
            outfile << employees[i]->getIdNo() << "\t " << employees[i]->getName() << "\t " << employees[i]->getSalary() << "\t " << employees[i]->getShift();
            if (dynamic_cast<Manager *>(employees[i]))
            {
                Manager *manager = dynamic_cast<Manager *>(employees[i]);
                outfile << "\t " << manager->getTeamSize();
            }
            else if (dynamic_cast<Baker *>(employees[i]))
            {
                Baker *baker = dynamic_cast<Baker *>(employees[i]);
                outfile << "\t " << baker->getSpeciality();
            }
            else if (dynamic_cast<Worker *>(employees[i]))
            {
                Worker *worker = dynamic_cast<Worker *>(employees[i]);
                outfile << "\t " << worker->getDepartment();
            }
            outfile << endl;
        }
        outfile.close();
    }

    void view_records()
    {
        ifstream infile("EmployeeInformation.txt");
        if (!infile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        string line;
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************VIEW EMP**************|\n"
             << RESET;
        cout << BOLD << "\nID\tNAME\tSALARY\tSHIFT\t\tADDINFO\n"
             << RESET;
        while (getline(infile, line))
        {
            cout << BOLD << CYAN << line << endl;
        }
        cout << BOLD << "\n----------------------------------------------\n"
             << RESET;
        infile.close();
    }

    void search_record(int id)
    {
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************SEARCH EMP**************|\n"
             << RESET;
        bool found = false;
        ifstream infile("EmployeeInformation.txt");
        if (!infile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        int empId;
        string name;
        float salary;
        string shift, additionalInfo;
        while (infile >> empId >> name >> salary >> shift >> additionalInfo)
        {
            if (empId == id)
            {
                cout << BOLD << YELLOW << "\n\n================================================\n\n"
                     << RESET;
                cout << BOLD << GREEN << "Employee ID : " << empId << RESET << endl;
                cout << BOLD << GREEN << "Employee Name : " << name << RESET << endl;
                cout << BOLD << GREEN << "Employee Salary : " << salary << RESET << endl;
                cout << BOLD << GREEN << "Employee Shift : " << shift << RESET << endl;
                cout << BOLD << GREEN << "Additional Info: " << additionalInfo << RESET << endl;
                found = true;
                break;
            }
        }
        infile.close();
        if (!found)
        {
            cout << RED << "Record not found!" << RESET << endl;
        }
    }

    void update_record(int id)
    {
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************UPDATE REC**************|\n"
             << RESET;
        ifstream file("EmployeeInformation.txt");
        ofstream temp("temp.txt");
        int empId;
        string name;
        float salary;
        string shift, additionalInfo;
        while (file >> empId >> name >> salary >> shift >> additionalInfo)
        {
            if (empId == id)
            {
                cout << BOLD << YELLOW << "Enter the new details of the employee:" << RESET << endl;
                cout << "Id: ";
                cin >> empId;
                cout << "Name: ";
                cin >> name;
                cout << "Salary: ";
                cin >> salary;
                cout << "Shift: ";
                cin >> shift;
                cout << "Additional Info: ";
                cin >> additionalInfo;
            }
            temp << empId << "\t" << name << "\t" << salary << "\t" << shift << "\t" << additionalInfo << endl;
        }
        temp.close();
        file.close();
        remove("EmployeeInformation.txt");
        rename("temp.txt", "EmployeeInformation.txt");
    }

    void delete_record(int id)
    {
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************DEL REC**************|\n"
             << RESET;
        ifstream file("EmployeeInformation.txt");
        ofstream temp("temp.txt");
        int empId;
        string name;
        float salary;
        string shift, additionalInfo;
        while (file >> empId >> name >> salary >> shift >> additionalInfo)
        {
            if (empId != id)
            {
                temp << empId << "\t" << name << "\t" << salary << "\t" << shift << "\t" << additionalInfo << endl;
            }
        }
        temp.close();
        file.close();
        remove("EmployeeInformation.txt");
        rename("temp.txt", "EmployeeInformation.txt");
    }
};

class Item
{
protected:
    int item_id;
    string item_name, item_type;
    double item_price;
    string mfg; // Manufacturing date
    string exp; // Expiration date

public:
    Item(int id, string name, string type, double price, string mfgDate)
        : item_id(id), item_name(name), item_type(type), item_price(price), mfg(mfgDate)
    {
        calculateExpDate();
    }

    int getItemID() const { return item_id; }
    string getItemName() const { return item_name; }
    string getItemType() const { return item_type; }
    double getItemPrice() const { return item_price; }
    string getMfg() const { return mfg; }

    void calculateExpDate()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        ltm->tm_mday += 3;
        mktime(ltm);

        // Formatting the expiration date
        char buffer[11]; // Format: YYYY-MM-DD
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
        exp = buffer;
    }

    string getExp() const { return exp; }

    virtual void display() const
    {
        cout << BOLD << CYAN << "\nItem ID: " << item_id << RESET << endl;
        cout << BOLD << CYAN << "Item Name: " << item_name << RESET << endl;
        cout << BOLD << CYAN << "Item Type: " << item_type << RESET << endl;
        cout << BOLD << CYAN << "Item Price: " << item_price << RESET << endl;
        cout << BOLD << CYAN << "Manufacturing Date: " << mfg << RESET << endl;
        cout << BOLD << CYAN << "Expiration Date: " << exp << RESET << endl;
    }
};

class Sweet : public Item
{
private:
    string flavor;

public:
    Sweet(int id, string name, string type, double price, string mfgDate, string f)
        : Item(id, name, type, price, mfgDate), flavor(f) {}

    string getFlavor() const { return flavor; }

    void display() const
    {
        Item::display();
        cout << BOLD << GREEN << "Flavor: " << flavor << RESET << endl;
    }
};

class Cake : public Item
{
private:
    string flavor;
    int weight;

public:
    Cake(int id, string name, string type, double price, string mfgDate, string f, int w)
        : Item(id, name, type, price, mfgDate), flavor(f), weight(w) {}

    string getFlavor() const { return flavor; }
    int getWeight() const { return weight; }

    void display() const
    {
        Item::display();
        cout << BOLD << MAGENTA << "Flavor: " << flavor << RESET << endl;
        cout << BOLD << MAGENTA << "Weight: " << weight << " kg" << RESET << endl;
    }
};

class Biscuits : public Item
{
private:
    string type;

public:
    Biscuits(int id, string name, string type, double price, string mfgDate, string biscuitsType)
        : Item(id, name, type, price, mfgDate), type(biscuitsType) {}

    string getType() const { return type; }

    void display() const
    {
        Item::display();
        cout << BOLD << YELLOW << "Type: " << type << RESET << endl;
    }
};

class Pizza : public Item
{
private:
    string toppings;

public:
    Pizza(int id, string name, string type, double price, string mfgDate, string t)
        : Item(id, name, type, price, mfgDate), toppings(t) {}

    string getToppings() const { return toppings; }

    void display() const
    {
        Item::display();
        cout << BOLD << RED << "Toppings: " << toppings << RESET << endl;
    }
};

class ItemManagement
{
private:
    Item *item[100];
    int itemCount;

public:
    ItemManagement() : itemCount(0) {}

    void addItemRecord()
    {
        int count;
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************ADDING ITEMS**************|\n"
             << RESET;
        cout << YELLOW << "\nHow many Items do you want to add: " << RESET;
        cin >> count;

        for (int i = 0; i < count; i++)
        {
            int choice;
            cout << BOLD << "\nWhat do you want to add\n"
                 << "1. Sweets" << endl
                 << "2. Cake" << endl
                 << "3. Biscuits" << endl
                 << "4. Pizza" << endl;
            cout << "Enter your choice: " << RESET;
            cin >> choice;

            cout << BOLD << "\n----------------------------------------------\n"
                 << RESET;

            if (choice == 1)
            {
                cout << "\nEnter the details of the Sweet item:" << endl;
                cout << "Id : ";
                int id;
                cin >> id;
                cout << "Name : ";
                string name;
                cin >> name;

                string type;
                type = "Sweet";
                cout << "Type : " << type;

                cout << "\nPrice : ";
                double price;
                cin >> price;
                cout << "Manufacturing Date (YYYY-MM-DD): ";
                string mfgDate;
                cin >> mfgDate;
                cout << "Flavor : ";
                string flavor;
                cin >> flavor;
                item[itemCount] = new Sweet(id, name, type, price, mfgDate, flavor);

                itemCount++;
                store_record();
                cout << BOLD << "\n----------------------------------------------\n"
                     << RESET;
            }
            else if (choice == 2)
            {
                cout << "\nEnter the details of the Cake item:" << endl;
                cout << "Id : ";
                int id;
                cin >> id;
                cout << "Name : ";
                string name;
                cin >> name;
                string type;
                type = "Cake";
                cout << "Type : " << type;
                cout << "\nPrice : ";
                double price;
                cin >> price;
                cout << "Manufacturing Date (YYYY-MM-DD): ";
                string mfgDate;
                cin >> mfgDate;
                cout << "Flavor : ";
                string flavor;
                cin >> flavor;
                cout << "Weight : ";
                int weight;
                cin >> weight;

                item[itemCount] = new Cake(id, name, type, price, mfgDate, flavor, weight);

                itemCount++;
                store_record();
                cout << BOLD << "\n----------------------------------------------\n"
                     << RESET;
            }
            else if (choice == 3)
            {
                cout << "\nEnter the details of the Biscuits item:" << endl;
                cout << "Id : ";
                int id;
                cin >> id;
                cout << "Name : ";
                string name;
                cin >> name;
                string type;
                type = "Biscuits";
                cout << "Type : " << type;
                cout << "\nPrice : ";
                double price;
                cin >> price;
                cout << "Manufacturing Date (YYYY-MM-DD): ";
                string mfgDate;
                cin >> mfgDate;
                cout << "Flavor : ";
                string biscuitsType;
                cin >> biscuitsType;

                item[itemCount] = new Biscuits(id, name, type, price, mfgDate, biscuitsType);

                itemCount++;
                store_record();
                cout << BOLD << "\n----------------------------------------------\n"
                     << RESET;
            }
            else if (choice == 4)
            {
                cout << "\nEnter the details of the Pizza item:" << endl;
                cout << "Id : ";
                int id;
                cin >> id;
                cout << "Name : ";
                string name;
                cin >> name;
                string type;
                type = "Pizza";
                cout << "Type : " << type;
                cout << "\nPrice : ";
                double price;
                cin >> price;
                cout << "Manufacturing Date (YYYY-MM-DD): ";
                string mfgDate;
                cin >> mfgDate;
                cout << "Toppings : ";
                string toppings;
                cin >> toppings;

                item[itemCount] = new Pizza(id, name, type, price, mfgDate, toppings);

                itemCount++;
                store_record();
                cout << BOLD << "\n----------------------------------------------\n"
                     << RESET;
            }
        }
    }

    void store_record()
    {
        ofstream outfile("ItemInformation.txt", ios::app);
        if (!outfile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        for (int i = 0; i < itemCount; ++i)
        {
            outfile << item[i]->getItemType() << "\t" << item[i]->getItemID() << "\t" << item[i]->getItemName() << "\t" << item[i]->getItemType() << "\t" << item[i]->getItemPrice() << "\t" << item[i]->getMfg() << "\t" << item[i]->getExp();
            if (item[i]->getItemType() == "Sweet")
            {
                Sweet *sweetItem = dynamic_cast<Sweet *>(item[i]);
                outfile << " " << sweetItem->getFlavor();
            }
            else if (item[i]->getItemType() == "Cake")
            {
                Cake *cakeItem = dynamic_cast<Cake *>(item[i]);
                outfile << " " << cakeItem->getFlavor() << " " << cakeItem->getWeight();
            }
            else if (item[i]->getItemType() == "Biscuits")
            {
                Biscuits *biscuitsItem = dynamic_cast<Biscuits *>(item[i]);
                outfile << " " << biscuitsItem->getType();
            }
            else if (item[i]->getItemType() == "Pizza")
            {
                Pizza *pizzaItem = dynamic_cast<Pizza *>(item[i]);
                outfile << " " << pizzaItem->getToppings();
            }
            outfile << endl;
        }
        outfile.close();
    }

    void view_record()
    {
        ifstream infile("ItemInformation.txt");
        if (!infile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        string line;
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************VIEWING ITEMS**************|\n"
             << RESET;
        cout << BOLD << "\nCAT\tID\tNAME\tTYPE\tPRICE\tMFG\tExpDATE\t\tADDINFO\n"
             << RESET;
        while (getline(infile, line))
        {
            cout << BOLD << CYAN << line << RESET << endl;
        }
        cout << BOLD << "\n----------------------------------------------\n"
             << RESET;
        infile.close();
    }

    void search_record(int temp_id)
    {
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************SEARCH ITEMS**************|\n"
             << RESET;
        bool found = false;
        ifstream infile("ItemInformation.txt");
        if (!infile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        string type;
        int id;
        string name, mfgDate, expDate, additionalInfo;
        double price;
        while (infile >> type >> id >> name >> type >> price >> mfgDate >> expDate >> additionalInfo)
        {
            if (id == temp_id)
            {
                cout << BOLD << "\nItem ID: " << id << RESET << endl;
                cout << BOLD << "Item Name: " << name << RESET << endl;
                cout << BOLD << "Item Type: " << type << RESET << endl;
                cout << BOLD << "Item Price: " << price << RESET << endl;
                cout << BOLD << "Manufacturing Date: " << mfgDate << RESET << endl;
                cout << BOLD << "Expiration Date: " << expDate << RESET << endl;
                cout << BOLD << "Additional Info: " << additionalInfo << RESET << endl;
                found = true;
                break;
            }
        }
        infile.close();
        if (!found)
        {
            cout << RED << "Record not found!" << RESET << endl;
        }
    }

    void update_record(int temp_id)
    {
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************EDITING ITEMS**************|\n"
             << RESET;
        bool found = false;
        ifstream infile("ItemInformation.txt");
        ofstream outfile("temp.txt");
        if (!infile || !outfile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        string type;
        int id;
        string name, mfgDate, expDate, additionalInfo;
        double price;
        while (infile >> type >> id >> name >> type >> price >> mfgDate >> expDate >> additionalInfo)
        {
            if (id == temp_id)
            {
                cout << BOLD << YELLOW << "Enter the new details of the item:" << RESET << endl;
                cout << "Name : ";
                cin >> name;
                cout << "Type : ";
                cin >> type;
                cout << "Price : ";
                cin >> price;
                cout << "Manufacturing Date (YYYY-MM-DD): ";
                cin >> mfgDate;
                cout << "Additional Info : ";
                cin >> additionalInfo;
                cout << BOLD << "\n----------------------------------------------\n"
                     << RESET;
                outfile << type << "\t" << id << "\t" << name << "\t" << type << "\t" << price << "\t" << mfgDate << "\t" << expDate << "\t" << additionalInfo << endl;
                found = true;
            }
            else
            {
                outfile << BOLD << CYAN << type << "\t" << id << "\t" << name << "\t" << type << "\t" << price << "\t" << mfgDate << "\t" << expDate << "\t" << additionalInfo << endl;
            }
        }
        infile.close();
        outfile.close();
        remove("ItemInformation.txt");
        rename("temp.txt", "ItemInformation.txt");
        if (!found)
        {
            cout << RED << "\nRecord not found!" << RESET << endl;
        }
    }

    void delete_rec(int temp_id)
    {
        cout << BOLD << GREEN << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << GREEN << "|************DEL ITEMS**************|\n"
             << RESET;
        bool found = false;
        ifstream infile("ItemInformation.txt");
        ofstream outfile("temp.txt");
        if (!infile || !outfile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        string type;
        int id;
        string name, mfgDate, expDate, additionalInfo;
        double price;
        while (infile >> type >> id >> name >> type >> price >> mfgDate >> expDate >> additionalInfo)
        {
            if (id != temp_id)
            {
                outfile << BOLD << CYAN << type << " " << id << " " << name << " " << type << " " << price << " " << mfgDate << " " << expDate << " " << additionalInfo << endl;
            }
            else
            {
                found = true;
            }
        }
        infile.close();
        outfile.close();
        remove("ItemInformation.txt");
        rename("temp.txt", "ItemInformation.txt");
        if (!found)
        {
            cout << RED << "Record not found!" << RESET << endl;
        }
    }
};

class costumer
{
public:
    void view_items()
    {
        ItemManagement temp;
        temp.view_record();
    }

    void search_items(string temp_name)
    {
        bool found = false;
        ifstream infile("ItemInformation.txt");
        if (!infile)
        {
            cerr << RED << "Error opening file." << RESET << endl;
            return;
        }
        string type;
        int id;
        string name, mfgDate, expDate, additionalInfo;
        double price;
        while (infile >> type >> id >> name >> type >> price >> mfgDate >> expDate >> additionalInfo)
        {
            if (name == temp_name)
            {
                cout << BOLD << GREEN << "\n--------------------------------------------------------\n"
                     << RESET;
                cout << BOLD << GREEN << "Item ID: " << id << RESET << endl;
                cout << BOLD << GREEN << "Item Name: " << name << RESET << endl;
                cout << BOLD << GREEN << "Item Type: " << type << RESET << endl;
                cout << BOLD << GREEN << "Item Price: " << price << RESET << endl;
                cout << BOLD << GREEN << "Manufacturing Date: " << mfgDate << RESET << endl;
                cout << BOLD << GREEN << "Expiration Date: " << expDate << RESET << endl;
                cout << BOLD << GREEN << "Additional Info: " << additionalInfo << RESET << endl;
                found = true;
                break;
            }
        }
        infile.close();
        if (!found)
        {
            cout << RED << "\nRecord not found!" << RESET << endl;
        }
    }

    void buy()
    {
        cout << BOLD << YELLOW << "\n______________________________________\n"
             << RESET;
        cout << ITALIC << UNDERLINE << YELLOW << "|************BUYING ITEMS**************|\n"
             << RESET;
        ItemManagement temp;
        temp.view_record();
        cout << BOLD << "\n---------------------------------------------\n"
             << RESET;

        char buy_more;
        double total_cost = 0;
        do
        {
            int id, quantity;
            bool found = false;
            string name, type, mfgDate, expDate, additionalInfo;
            double price;

            int tempid;
            cout << BOLD << "Enter the ID of the item you want to buy: " << RESET;
            cin >> tempid;

            ifstream infile("ItemInformation.txt");
            if (!infile.is_open())
            {
                cout << RED << "Unable to open file!" << RESET << endl;
                return;
            }
            while (infile >> type >> id >> name >> type >> price >> mfgDate >> expDate >> additionalInfo)
            {
                if (tempid == id)
                {
                    found = true;
                    break;
                }
            }
            infile.close();

            if (!found)
            {
                cout << RED << "\nItem with ID " << tempid << " not found!" << RESET << endl;
                continue;
            }
            cout << BOLD << "\n--------------------------------------------------------\n"
                 << RESET;
            cout << BOLD << "Enter the quantity of " << name << " you want to buy: " << RESET;
            cin >> quantity;
            double item_total_price = price * quantity;
            cout << BOLD << "\n--------------------------------------------------------\n"
                 << RESET;
            cout << BOLD << "Total price for " << quantity << " " << name << "(s): $" << item_total_price << RESET << endl;

            total_cost = total_cost + item_total_price;
            cout << BOLD << "\n--------------------------------------------------------\n"
                 << RESET;
            cout << BOLD << "Do you want to buy more items? (y/n): " << RESET;
            cin >> buy_more;
        } while (buy_more == 'y' || buy_more == 'Y');
        cout << BOLD << "\n--------------------------------------------------------\n"
             << RESET;
        cout << BOLD << "Total cost for all items: $" << total_cost << RESET << endl;
        cout << BOLD << "\n\n"
             << RESET;
    }
};

void item()
{
    ItemManagement itemManagement;
    int choice;
    while (choice != 6)
    {
        cout << BOLD << YELLOW << "\n\n================================================\n\n"
             << RESET;
        cout << BOLD << CYAN << "\n1. Add Record" << RESET << endl;
        cout << BOLD << CYAN << "2. View Records" << RESET << endl;
        cout << BOLD << CYAN << "3. Search Record" << RESET << endl;
        cout << BOLD << CYAN << "4. Update Record" << RESET << endl;
        cout << BOLD << CYAN << "5. Delete Record" << RESET << endl;
        cout << BOLD << CYAN << "6. Exit" << RESET << endl;
        cout << BOLD << GREEN << "Enter your choice: " << RESET;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            itemManagement.addItemRecord();
            break;
        case 2:
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            itemManagement.view_record();
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;

            break;
        case 3:
        {
            int id;
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            cout << BOLD << CYAN << "\nEnter the ID to search: " << RESET;
            cin >> id;
            itemManagement.search_record(id);
            break;
        }
        case 4:
        {
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            int id;
            cout << BOLD << CYAN << "\nEnter the ID to update: " << RESET;
            cin >> id;
            itemManagement.update_record(id);
            break;
        }
        case 5:
        {
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            int id;
            cout << BOLD << CYAN << "\nEnter the ID to delete: " << RESET;
            cin >> id;
            itemManagement.delete_rec(id);
            break;
        }
        case 6:
        {
            system("cls");
            break;
        }
        default:
            cout << RED << "\nInvalid choice!" << RESET << endl;
        }
    }
}

void employee()
{
    EmployeeManagement em;
    int choice;
    int id;
    while (choice != 6)
    {
        cout << BOLD << YELLOW << "\n\n================================================\n\n"
             << RESET;
        cout << BOLD << CYAN << "\n1. Add Record" << RESET << endl;
        cout << BOLD << CYAN << "2. View Records" << RESET << endl;
        cout << BOLD << CYAN << "3. Search Record" << RESET << endl;
        cout << BOLD << CYAN << "4. Update Record" << RESET << endl;
        cout << BOLD << CYAN << "5. Delete Record" << RESET << endl;
        cout << BOLD << CYAN << "6. Exit" << endl;
        cout << BOLD << GREEN << "Enter your choice: " << RESET;
        cin >> choice;
        if (choice == 1)
        {
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            em.add_record();
        }
        else if (choice == 2)
        {
            em.view_records();
        }
        else if (choice == 3)
        {
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            cout << BOLD << "Enter the id of the employee to search: " << RESET;
            cin >> id;
            em.search_record(id);
        }
        else if (choice == 4)
        {
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            cout << BOLD << "Enter the id of the employee to update: " << RESET;
            cin >> id;
            em.update_record(id);
        }
        else if (choice == 5)
        {
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            cout << BOLD << "Enter the id of the employee to delete: " << RESET;
            cin >> id;
            em.delete_record(id);
        }
        else if (choice == 6)
        {
            system("cls");
            break;
        }
    }
}

class BakeryManagemet
{
public:
    void costumers()
    {
        int choice;
        while (choice != 4)
        {
            cout << MAGENTA << BOLD << "______________________________________________"
                 << "\n||*************WELCOME TO OUR SHOP************||\n"
                 << "______________________________________________" << RESET;
            cout << BOLD << "\nSelect Management System:" << RESET << endl;
            cout << BOLD << YELLOW << "1. View Items" << endl;
            cout << BOLD << YELLOW << "2. Search Items" << RESET << endl;
            cout << BOLD << YELLOW << "3. Buy Items" << RESET << endl;
            cout << BOLD << YELLOW << "4. Exit" << RESET << endl;
            cout << BOLD << ORANGE << "Enter your choice: " << RESET;
            cin >> choice;
            costumer c;
            if (choice == 1)
            {
                cout << BOLD << YELLOW << "\n\n================================================\n\n"
                     << RESET;
                c.view_items();
            }
            else if (choice == 2)
            {
                string tempname;
                cout << BOLD << YELLOW << "\n\n================================================\n\n"
                     << RESET;
                cout << BOLD << CYAN << "\nEnter Name of item you want to search: " << RESET;
                cin >> tempname;
                c.search_items(tempname);
            }
            else if (choice == 3)
            {
                c.buy();
            }
            else if (choice == 4)
            {
                cout << BOLD << YELLOW << "\n\n================================================\n\n"
                     << RESET;
                cout << BOLD << "\nExiting....." << RESET << endl;
                system("cls");
            }
            else
            {
                cout << RED << "\nINVALID OPTION" << RESET << endl;
            }
        }
    }

    void Admin_portal()
    {
        int choice;
        while (choice != 3)
        {
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            cout << BOLD << ORANGE << "\nSelect Management System:" << RESET << endl;
            cout << BOLD << GREEN << "1. Employee Management" << RESET << endl;
            cout << BOLD << GREEN << "2. Item Management" << RESET << endl;
            cout << BOLD << GREEN << "3. Exit" << RESET << endl;
            cout << BOLD << GREEN << "Enter your choice: " << RESET;
            cin >> choice;
            cout << BOLD << YELLOW << "\n\n================================================\n\n"
                 << RESET;
            switch (choice)
            {
            case 1:
                employee();
                break;
            case 2:
                item();
                break;
            case 3:
                cout << BOLD << "\nExiting..." << RESET << endl;
                system("cls");
                break;
            default:
                cout << RED << "\nInvalid choice. Please try again." << RESET << endl;
            }
        }
    }
};

int main()
{
    BakeryManagemet Bkr;
    int choice;
    while (choice != 3)
    {
        cout << endl;
        cout << BOLD << YELLOW
             << "        __        __  _____   _        ____    ___    __  __   _____ \n"
                "        \\ \\      / / | ____| | |      / ___|  / _ \\  |  \\/  | | ____|\n"
                "         \\ \\ /\\ / /  |  _|   | |     | |     | | | | | |\\/| | |  _|  \n"
                "          \\ V  V /   | |___  | |___  | |___  | |_| | | |  | | | |___ \n"
                "           \\_/\\_/    |_____| |_____|  \\____|  \\___/  |_|  |_| |_____|\n"
             << RESET;
        cout << BOLD << YELLOW << "\n\n=================================================================\n\n"
             << RESET;
        cout << BOLD << CYAN << "\n*************BAKERY MANAGEMENT SYSTEM*************\n"
             << RESET;
        cout << BOLD << ITALIC << MAGENTA << "\nSelect Your Category:" << endl;
        cout << BOLD << YELLOW << "1. Admin" << endl;
        cout << BOLD << YELLOW << "2. Customer" << endl;
        cout << BOLD << YELLOW << "3. Exit" << RESET << endl;
        cout << BOLD << YELLOW << "Enter your choice: " << RESET;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int pass;
            cout << BOLD << ORANGE << "Enter your password: " << RESET;
            cin >> pass;
            if (pass == 230930)
            {
                Bkr.Admin_portal();
            }
            else
            {
                cout << RED << "\nInvalid password\n"
                     << RESET;
            }
            break;
        }
        case 2:
            Bkr.costumers();
            break;
        case 3:
            cout << BOLD << "Exiting..." << RESET << endl;
            break;
            system("cls");
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }
    }
    return 0;
}
