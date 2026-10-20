
#include <bits/stdc++.h>
using namespace std;

class User
{
private:
    string username;
    string password;

    const string filename = "users.txt";

    // Simple educational hash, not suitable for production.
    string hashPassword(string pass)
    {
        hash<string> hasher;
        return to_string(hasher(pass));
    }

    bool usernameExists(string user)
    {
        ifstream file(filename);
        string savedUser, savedHash;

        while (file >> savedUser >> savedHash)
        {
            if (savedUser == user)
                return true;
        }

        return false;
    }

public:
    bool validUsername(string user)
    {
        if (user.length() < 4)
            return false;

        for (char c : user)
        {
            if (!isalnum((unsigned char)c) && c != '_')
                return false;
        }

        return true;
    }

    bool validPassword(string pass)
    {
        return pass.length() >= 6;
    }

    void registerUser()
    {
        cout << "\n===== REGISTRATION =====\n";

        cout << "Enter username: ";
        cin >> username;

        if (!validUsername(username))
        {
            cout << "Username must be at least 4 characters "
                 << "and contain only letters, numbers, or _.\n";
            return;
        }

        if (usernameExists(username))
        {
            cout << "Username already exists!\n";
            return;
        }

        cout << "Enter password (minimum 6 characters): ";
        cin >> password;

        if (!validPassword(password))
        {
            cout << "Password must contain at least 6 characters!\n";
            return;
        }

        ofstream file(filename, ios::app);

        if (!file)
        {
            cout << "Error opening user database!\n";
            return;
        }

        file << username << " "
             << hashPassword(password) << "\n";

        file.close();

        cout << "Registration successful!\n";
    }

    void loginUser()
    {
        cout << "\n===== LOGIN =====\n";

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        ifstream file(filename);

        if (!file)
        {
            cout << "No registered users found!\n";
            return;
        }

        string savedUser, savedHash;
        string enteredHash = hashPassword(password);

        while (file >> savedUser >> savedHash)
        {
            if (savedUser == username)
            {
                if (savedHash == enteredHash)
                {
                    cout << "Login successful! Welcome, "
                         << username << "!\n";
                }
                else
                {
                    cout << "Incorrect password!\n";
                }

                return;
            }
        }

        cout << "Username not found!\n";
    }
};

int main()
{
    User user;
    int choice;

    do
    {
        cout << "\n===== LOGIN AND REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice)
        {
        case 1:
            user.registerUser();
            break;

        case 2:
            user.loginUser();
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
