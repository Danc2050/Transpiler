// basic file operations
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
using std::cout;
using std::endl;
using namespace std;

int main (int argc, char *argv[]) {
	ofstream f;
	int i = 0; int j = -1;
	vector<string> functions;
	string str1, str2, file, className, tmp; bool stay = true; 
	while(stay){
		// File creation (.h)
		cout <<"Name your .h file"<<endl;
		cin >> file;
		f.open (file);
		for (int a = 0; a < file.length(); ++a){
			if(file[a] == '.') break;
			tmp += file.at(a);
		}
		cout <<"TMP"<<tmp<<"And?"<<endl;
		file = tmp;	
		// Class creation
		cout <<"Enter your class"<<endl;
		cin >> className;
		str1 = str2 = className; // "shallow copy", but its okay with strings
		f << "class " <<str1<< "{\npublic:\n";
		cout <<"str1"<<str1<<endl;
		cout <<"str2"<<str2<<endl;
		f << "int " <<str1<<"();\n";// Constructor
		f << "int ~"<<str2<<"();\n";// Destructor
		
		//.cpp implementation file creation
		str1.append("::"); str1.append(str2); str1.append("()\n{\n}\n\n");
		functions.push_back(str1);
		cout <<"\nstring1:"<<str1;
		str1 = "~"; str1.append(className);
		str2.append("::"); str2.append(str1); str2.append("()\n{\n}\n\n");
		cout <<"\nstring2:"<<str2;
		// vector to add to our .h file
		functions.push_back(str2);
		// Method creation	
		while(stay){
			str1 = className;
			cout <<"Enter your methods"<<endl;
			cin >> tmp;
			f << tmp<< "();\n";
			cin.clear();
			str1.append("::"); str1.append(tmp); str1.append("()\n{\n}\n\n"); // constructor for .h
			functions.push_back(str1); 
			cout <<"More Methods? (1 for yes, 0 for no)?"<<endl;
			cin >> stay;
		}
		stay = true;
		while(stay){
			// Data member creation	
			cout <<"Enter your data members -- {[Return type] [Field]} "<<endl;
			f << "private:"<<endl;
			cin >> tmp;
			f <<tmp <<"\n";
			cout <<"More data members? (1 for yes, 0 for no)?"<<endl;
			cin >> stay;
		}

		cout <<"Would you like to exit (1 for yes, 0 for no)?"<<endl;

	}
	f.close(); // close .h file

	// create .cpp file
	file.append(".cpp");
	f.open(tmp);
	cout <<"\nFile"<<tmp;
	tmp = "#include \"" + tmp + "\"\n\n";
	f <<tmp;
	for (auto it = functions.begin(); it != functions.end(); ++it) {
		f << *it;
		cout <<' ' <<*it;
	}
	f.close(); // close .cpp file
	return 0;
}
