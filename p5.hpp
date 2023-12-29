//File name : A3_Sheet2b5_20220835
//Purpose :Taske Manger
//Author : Safa Tawfik Al-sharabi
//ID : 20220835
//Section : S1
//Date :8/12/2023


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include<iomanip>

using namespace std;

class Process
{
public:
    string imageName;
    int pid;
    int memoryUsage;
    string sessionName;
    int sessionNumber;

    Process(string n, int p, int m, string sn, int snu) : imageName(n), pid(p), memoryUsage(m), sessionName(sn), sessionNumber(snu) {}
};

class TaskManager
{
private:
    vector<Process> processes;

public:
    void loadProcessesFromOS()
    {
        processes.clear();


        /*
        using the _popen function to execute the tasklist /FO CSV command and
        create a pipe to capture its output.
        Let's break down the components of this line:
        1- _popen function : This is a platform-specific function
        used in C and C++ on Windows systems to open
        a process and create a pipe for communication with that process.

        2- "tasklist /FO CSV" :hich specifies that the output should be in
         Comma-Separated Values (CSV) format. The
         tasklist command on Windows provides information about running processes.
        3- "r": This specifies that the pipe is opened for
        reading (input). The "r" mode indicates
        that the program intends to read from the pipe.
        */
        FILE* pipe = _popen("tasklist /FO CSV", "r");
        if (!pipe)
        {
            cout << "Can't run tasklist command" << endl;
            return;
        }

        char buffer[256];
        /*
        fgets(buffer, sizeof(buffer), pipe);
         fgets function to read a line of text from the pipe
         (which is connected to the output of the tasklist command) and stores it in the buffer array.
          The sizeof(buffer) specifies the maximum number of characters to read.
        buffer: The destination buffer where the line of text will be stored.
        sizeof(buffer): The maximum number of characters to read into the buffer.
        pipe: The file stream from which to read the line, which is the output of the tasklist command.
        */
        fgets(buffer, sizeof(buffer), pipe);
        //"ProcessName1",123,"SessionName1",456,789  this is the example of the token that we get from Task manager
        // we parsing it
        /*
        After the first call: "ProcessName1" // stored in name
        After the second call: 123 // stored in pid
        After the third call: "SessionName1" // stored in session name
        After the fourth call: 456 // stored in session number
        After the fifth call: 789 // stored in memory usage

        Look at the code down , we iterate over the long token (String) that we get from the operating system (OS)
        when we use this line         FILE* pipe = _popen("tasklist /FO CSV", "r");

        */
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) // we iterate of the the buffer that contain the token ( this token is string )
        {

            /*
              strtok -> used for tokenizing (breaking into parts) a string based on a delimiter.
              atoi  ->converts a string of characters representing an integer into an actual integer.


              like if if have "123" the result will be 123 not string
            */



            /*

            if you cout << fgets(buffer, sizeof(buffer))
              for example you will get
            "services.exe","792","Services","0","9,468 K"
            "svchost.exe","944","Services","0","31,732 K"
            "winlogon.exe","384","Console","1","11,280 K"
            "fontdrvhost.exe","532","Console","1","6,964 K"

            */
            char* token = strtok(buffer, "\","); // from start to the end of the name
            string imageName = token;
            token = strtok(NULL, "\","); // from end of the name to end of th pid
            int pid = atoi(token);
            token = strtok(NULL, "\","); //form pid to the end of the session name
            string sessionName = token;
            token = strtok(NULL, "\","); // from session name to the end of session number
            int sessionNumber = atoi(token);
            token = strtok(NULL, "\","); // from session number to the end of memory usage
            int memoryUsage = atoi(token);

            /*
            example :
            the token like this --->char input[] = "John,123,Console,1,512";

            char* token = strtok(input, ",");
            string name = token;

            if i make this the variable name will be contain John


            */

            processes.push_back(Process(imageName, pid, memoryUsage, sessionName, sessionNumber));
        }

        _pclose(pipe);
    }

    void sortedByName()
    {
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b)
        {
            return a.imageName < b.imageName;
        });

        displayProcesses("By Sorted by Name");
    }

    void sortedByPID()
    {
        sort(processes.begin(), processes.end(), []( Process a,  Process b)
        {
            return a.pid < b.pid;
        });

        displayProcesses("By sorted by PID");
    }

    void sortedByMemoryUsage()
    {
        sort(processes.begin(), processes.end(), [](Process a,Process b)
        {
            return a.memoryUsage < b.memoryUsage;
        });

        displayProcesses("By Memory Usage");
    }

    void Spaces(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            cout << " ";
        }
    }



void displayProcesses(string title)
{
    cout << title << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << setw(30) << left << "Image Name" << setw(14) << "    PID" << setw(14) << "Session Name" << setw(6) << "Session#  " << "Mem Usage" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    for (const auto& process : processes)
    {
        cout << setw(33) << left << process.imageName.substr(0, 30);
        cout << setw(10) << process.pid;
        cout << setw(16) << left << process.sessionName.substr(0, 16);
        cout << setw(9) << process.sessionNumber;
        cout << process.memoryUsage << " KB" << endl;
    }

    cout << "---------------------------------------------------------------------------" << endl << endl;
}





};












