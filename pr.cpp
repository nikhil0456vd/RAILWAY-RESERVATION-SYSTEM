#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    // Default Constructor
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int num, const char name[], const char src[],
          const char dest[], const char time[])
    {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int num)
    {
        trainNumber = num;
    }

    void setTrainName(const char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(const char src[])
    {
        strcpy(source, src);
    }

    void setDestination(const char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(const char time[])
    {
        strcpy(trainTime, time);
    }

    // Getters
    int getTrainNumber()
    {
        return trainNumber;
    }

    char* getTrainName()
    {
        return trainName;
    }

    char* getSource()
    {
        return source;
    }

    char* getDestination()
    {
        return destination;
    }

    char* getTrainTime()
    {
        return trainTime;
    }

    // Input Train Details
    void inputTrainDetails()
    {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Train Details
    void displayTrainDetails()
    {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime << endl;
    }

    // Static Function
    static int getTrainCount()
    {
        return trainCount;
    }
};

// Initialize Static Member
int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    // Add Train
    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "\nTrain Added Successfully!\n";
        }
        else
        {
            cout << "\nTrain Storage Full!\n";
        }
    }

    // Display All Trains
    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo Train Records Found!\n";
            return;
        }

        cout << "\n===== Train Records =====\n";
        for (int i = 0; i < totalTrains; i++)
        {
            trains[i].displayTrainDetails();
            cout << "----------------------\n";
        }
    }

    // Search Train by Number
    void searchTrainByNumber(int number)
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nTrain Not Found!\n";
        }
    }
};

int main()
{
    RailwaySystem rs;
    int choice, number;

    do
    {
        cout << "\n===== Railway Management System =====";
        cout << "\n1. Add Train";
        cout << "\n2. Display All Trains";
        cout << "\n3. Search Train By Number";
        cout << "\n4. Display Train Count";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            rs.addTrain();
            break;

        case 2:
            rs.displayAllTrains();
            break;

        case 3:
            cout << "\nEnter Train Number to Search: ";
            cin >> number;
            rs.searchTrainByNumber(number);
            break;

        case 4:
            cout << "\nTotal Train Objects: "
                 << Train::getTrainCount() << endl;
            break;

        case 5:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}