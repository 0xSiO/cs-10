/*
 * Lucas Street, 10/3/16
 * CS 10, Dave Harden
 * Assignment 5.3 - a5_3.cpp
 *
 * Counts the words in a given file.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string file_name;
    ifstream in;

    cout << "Enter filename ('quit' to quit): ";
    cin >> file_name;

    while (file_name != "quit") {
        in.open(file_name);
        if (!in) {
            cout << "Error opening file." << endl;
        } else {
            string str;
            int count = 0;
            in >> str;
            while (in) {
                count++;
                in >> str;
            }
            in.close();

            cout << "There are " << count << " words in the file '" << file_name << "'." << endl;
        }

        cout << "Enter filename ('quit' to quit): ";
        cin >> file_name;
    }

    return 0;
}
// Output
/*
Enter filename ('quit' to quit): one
There are 7 words in the file 'one'.
Enter filename ('quit' to quit): two
There are 10 words in the file 'two'.
Enter filename ('quit' to quit): three
There are 21 words in the file 'three'.
Enter filename ('quit' to quit): four
There are 19 words in the file 'four'.
Enter filename ('quit' to quit): five
There are 22 words in the file 'five'.
Enter filename ('quit' to quit): quit
*/
