// Angel Rodriguez, 12/17/2017 on the train ride back home
// This program reads a text file and removes certain special characters and quotation marks
// from a file inputted and outputs the edited text into a new file

// Later expansion, in main, have the user type characters they don't want in the text file
// possibly? 
// Add the ability to keep inputing files, not just one at a time. Do it as a while loop or maybe in it's own function
// Fix the problem with sapces in the name of the files so I don't have to change that

#include <iostream>
#include <fstream>  // Open file stream
#include <string>  // For entering filename, not neccesary if I want a specific char size
#include <ctype.h> // To check for special characters
using namespace std;

int main(int argc, char** argv) {
	// Get file information
	string filename;
	cout << "Angel Rodriguez, 12/15/2017 \n";
	cout << "Enter the filename.\n"; 
	cout << "A txt file will be created with the same name as the original file, but with AR in the front.\n";
	cout << "The program removes \" " ", #, ^, |, ~, *, _ , <, and >.\n";
	cout << "{ and [ both get replaced by ( brackets.\n";
	cout << endl; 
	cout << "Enter the filename: ";
	
	//cin >> filename;  // User enters filename
    getline(cin,filename);
    filename=filename + ".txt";
	ifstream ifs; // Open filestream, open file 
	ifs.open (filename.c_str(), ifstream::in);
	
	// Check to see if it's a legit file
	while (!ifs) {
	    system("CLS"); // don't want them seeing the same stuff over and over again. 
		cout << "Gimme a good file, or press (CTRL and C) at the same time to quit.\n";
		cout << "Enter the filename: ";
		// cin >> filename; 
		getline(cin,filename);
		filename=filename + ".txt";
		ifs.open(filename.c_str(), ifstream::in);
		}

	// Set up the new file
	string editfile = "AR " + filename; // Just says edited in the front  
	ofstream ofs; // Set up output stream
	ofs.open (editfile.c_str(), ofstream::out);
	
	// Go through file
	while (!ifs.eof()) {
	
    	char c = ifs.get();
        if ( c == '\n') ofs << endl; 
        if ( c == '	') c = ' '; // The tab key replaces with a space key
		if ( c == ' ' || isprint(c) && c != '"' && c != '#' && c != '^' && c != '|' && c != '~' && c != '*' && c != '<' && c != '>' && c != '_'){
			if ( c == '{' || c == '[') c = '(';
			if ( c == '}' || c == ']') c = ')'; // We don't like square or curly brackets.
			
	 	ofs << c; 	// If it is a number or letter or accepted character keep it
   		}
   		
	}
	// TODO, Add it so I can have multiple files going in at the same time and files with spaces in the name. 
	cout << "Done, " << editfile << " was created.\n";
	system("PAUSE"); // Give them time to see what the name of the file is. 

	return 0;
}
