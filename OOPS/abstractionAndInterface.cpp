#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
// Abstraction Example: Database Interaction

class Database {
public:
    virtual void connect() = 0;
    virtual vector<string> query(const string& sql) = 0;
    virtual void close() = 0;
};

class MySQLDatabase : public Database {
public:
    void connect() override {
        cout << "Connecting to MySQL database..." << endl;
    }

    vector<string> query(const string& sql) override {
        cout << "Executing MySQL query: " << sql << endl;
        // Simulated query results for demonstration
        return {"Result 1", "Result 2"}; 
    }

    void close() override {
        cout << "Closing MySQL connection..." << endl;
    }
};

class PostgreSQLDatabase : public Database {
public:
    void connect() override {
        cout << "Connecting to PostgreSQL database..." << endl;
    }

    vector<string> query(const string& sql) override {
        cout << "Executing PostgreSQL query: " << sql << endl;
        // Simulated query results for demonstration
        return {"Result A", "Result B"}; 
    }

    void close() override {
        cout << "Closing PostgreSQL connection..." << endl;
    }
};

// Interface Example: GUI Components

class ActionListener {
public:
    virtual void actionPerformed(const string& action) = 0;
};

class Button : public ActionListener {
public:
    void actionPerformed(const string& action) override {
        cout << "Button clicked, action: " << action << endl;
    }
};

class Menu : public ActionListener {
public:
    void actionPerformed(const string& action) override {
        cout << "Menu item selected, action: " << action << endl;
    }
};

// Using Abstraction and Interface

int main() {
    // Database interaction
    cout << "Database Abstraction Example" << endl;
    unique_ptr<Database> db = make_unique<MySQLDatabase>(); 
    db->connect();
    vector<string> results = db->query("SELECT * FROM users");
    for (const auto& result : results) {
        cout << result << endl;
    }
    db->close();

    db = make_unique<PostgreSQLDatabase>();
    db->connect();
    vector<string> res = db->query("select * from users");
    for (const auto& result : results) {
        cout << result << endl;
    }
    db->close();

    

    // GUI component interaction
    cout << "\nGUI Interface Example" << endl;
    Button button;
    Menu menu;
    button.actionPerformed("Click");
    menu.actionPerformed("Select");

    return 0;
}