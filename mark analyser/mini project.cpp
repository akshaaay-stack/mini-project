
#include <iostream>
using namespace std;

void readMarks(int marks[], int n);
int findTotal(int marks[], int n);
double findAverage(int marks[], int n);
int findHighest(int marks[], int n);
int findLowest(int marks[], int n);
int countPassed(int marks[], int n);
void printReport(int marks[], int n);

int main()
{
    int marks[100];
    int n;
    char choice;

    do
    {
        cout << "\n===== STUDENT MARKS ANALYZER =====\n";

     
        do
        {
            cout << "Enter number of students (1-100): ";
            cin >> n;

            if (n < 1 || n > 100)
            {
                cout << "Invalid count! Please try again.\n";
            }

        } while (n < 1 || n > 100);

        
        readMarks(marks, n);
        printReport(marks, n);

        cout << "\nDo you want to analyse again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using Student Marks Analyzer!\n";

    return 0;
}


void readMarks(int marks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];

        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks! Enter marks between 0 and 100: ";
            cin >> marks[i];
        }
    }
}

int findTotal(int marks[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + marks[i];
    }

    return total;
}


double findAverage(int marks[], int n)
{
    int total = findTotal(marks, n);

    double average = (double) total / n;

    return average;
}


int findHighest(int marks[], int n)
{
    int highest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}


int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}


int countPassed(int marks[], int n)
{
    int passed = 0;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= 40)
        {
            passed++;
        }
    }

    return passed;
}


void printReport(int marks[], int n)
{
    int passed = countPassed(marks, n);
    int failed = n - passed;

    cout << "\n========== STUDENT REPORT ==========\n";

  
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": "
             << marks[i] << " - ";

        if (marks[i] >= 40)
        {
            cout << "Pass\n";
        }
        else
        {
            cout << "Fail\n";
        }
    }

    cout << "\nTotal Students : " << n;
    cout << "\nTotal Marks    : " << findTotal(marks, n);
    cout << "\nAverage Marks  : " << findAverage(marks, n);
    cout << "\nHighest Mark   : " << findHighest(marks, n);
    cout << "\nLowest Mark    : " << findLowest(marks, n);
    cout << "\nPassed         : " << passed;
    cout << "\nFailed         : " << failed;

    cout << "\n====================================\n";
}
