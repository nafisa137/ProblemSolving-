#include <iostream>
#include "p1.hpp"
#include "p2.hpp"
#include "p3.hpp"
#include "p4.hpp"
#include "p5.hpp"
#include "p6.hpp"
using namespace std;

int main() {
    int x;
    cout << "First Problem\n"
            "Second Problem\n"
            "Third Problem\n"
            "Fourth Problem\n"
            "Fifth Problem\n"
            "Sixth Problem\n";
    cout << "Your choice: ";

    cin >> x;

    switch (x) {
        case 1: {
            LabelGenerator FigureNumbers("figure", 1);
            LabelGenerator pointNumbers("p", 0);

            cout << "Figure numbers: ";
            for (int i = 0; i < 3; i++) {
                FigureNumbers.nextlabel();
                if (i < 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Point numbers: ";
            for (int i = 0; i < 5; i++) {
                pointNumbers.nextlabel();
                if (i < 4) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "More figures: ";
            for (int i = 0; i < 3; i++) {
                FigureNumbers.nextlabel();
                if (i < 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            FileLableGenerator figtable("figure", 1, "ttt.txt");
            cout << "Figure labels: " << endl;
            figtable.nextlabel();
            cout << endl;

            break;
        }
        case 2: {
            StringSet file("file.txt", false);
            StringSet query("Chocolate ice cream, chocolate milk, and chocolate bars.", true);

            cout << "Document set from file: ";
            file.outputStrings();

            cout << "Query set: ";
            query.outputStrings();

            double similarity = file.computeSimilarity(query);
            cout << "Similarity between document and query: " << similarity << endl;
            break;
        }

        case 3: {
            string filename;

            // Get the input file name from the user
            cout << "Enter the name of the text file: ";
            getline(cin, filename);

            // Open the file
            ifstream inputFile(filename);

            // Check if the file is opened successfully
            if (!inputFile.is_open()) {
                cout << "Error opening file: " << filename << endl;
                return 1;
            }

            // Map to store word frequencies
            map<string, int> frequencyTable;

            // Read the file line by line using a while loop
            string line;
            while (getline(inputFile, line)) {
                // Process each word in the line using a stringstream and while loop
                istringstream iss(line);
                string word;
                while (iss >> word) {
                    // Clean the word and update the frequency table
                    string cleanedWord = cleanWord(word);
                    if (!cleanedWord.empty()) {
                        frequencyTable[cleanedWord]++;
                    }
                }
            }

            // Close the file
            inputFile.close();

            // Display the formatted frequency table
            cout << "\nWord Frequency Table:\n";
            for (const auto &pair : frequencyTable) {
                cout << setw(15) << left << pair.first << ": " << pair.second << endl;
            }
            break;
        }

        case 4: {
            new_set<int> integer;
            new_set<string> strr;
            integer.add(5);
            integer.add(5);
            integer.add(33);
            strr.add("hello");
            strr.add("hello");
            strr.add("world");
            integer.display();
            strr.display();

            new_set<int> neww;
            neww.add(5);
            neww.add(33);
            cout << (neww == integer);  // will print 1 referring to true
            break;
        }

        case 5: {
            TaskManager T;
            T.loadProcessesFromOS();
            cout << " 1-Display the process sorted by memory usage \n 2-Display the process sorted by name\n 3-Display the process sorted by ID\n 4-Exit" << endl;
            int choice = 0;

            while (choice != 4) {
                cin >> choice;
                switch (choice) {
                    case 1:
                        T.sortedByMemoryUsage();
                        break;

                    case 2:
                        T.sortedByName();
                        break;

                    case 3:
                        T.sortedByPID();
                        break;
                }
            }
            break;
        }

        case 6: {
            Universe u;
            u.run(50);
            break;
        }
    }

    return 0;
}
