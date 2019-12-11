// basic file operations
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
using std::cout;
using std::endl;
using namespace std;

int keywordSearch(int argc, char * argv[]){
	/*
	   {{{Minimal idea}}}- This will search through our tokenized input (from cmdline) and do actions based on the keywords sensed.
	*/
	ofstream f;
	int i = 0; int j = -1;
	vector<string> functions;
	//char str1[100]; char str2[100]; char file[100];char tmp[100];
	string str1, str2, file, tmp;
	char * className;
	while(i < argc){
		cout << "arg[" << i << "]: " << argv[i] << endl;
		// File creation (.h)
		if(strcmp(argv[i], "IN") == 0) {
			file = argv[i+1];
			f.open (file);
			cout <<"FILE LENGTH: "<<file.length();
			for (int a = 0; a < file.length(); ++a){
				if(file[a] == '.') break;
				tmp += file.at(a);
			}
			cout <<"TMP"<<tmp<<"And?"<<endl;
		}
		// Class creation
		if(strcmp(argv[i], "CREATE") == 0){ 
			className = argv[i+1];
			f << "class " <<*className<< "{\npublic:\n";
			str1 = &*className; str2 = &*className;
			f << "int " <<str1<<"();\n";// Constructor
			f << "int ~"<<str1<<"();\n";// Destructor
			//.cpp implementation file creation
			str1.append("::"); str1.append(argv[i+1]);str1.append("()\n{\n}\n\n");
			str2.append("::"); str2.append(argv[i+1]);str2.append("()\n{\n}\n\n");
			functions.push_back(str1); functions.push_back(str2);
		}
		if(strcmp(argv[i], "SHOULD") == 0){ // Method creation
			while(strcmp(argv[i+1], ".") != 0){ // "." delimiter to stop
				f <<"int " << argv[i+1]<< "();\n";
				str1 = &*className; // previous class member scope copied...
				str1.append("::"); str1.append(argv[i+1]); str1.append("()\n{\n}\n\n"); // constructor for .h
				functions.push_back(str1); 
				++i;
			}
		}
		if(strcmp(argv[i], "WITH") == 0){ // Data creation
			f << "private:"<<endl;
			while(strcmp(argv[i+1], ".") != 0){ // "." delimiter to stop
				f <<"int " << argv[i+1]<< "();\n";
				++i;
			}
		}
		++i;
	}
	f.close(); // close .h file
	tmp.append(".cpp");
	f.open(tmp);
	cout <<"\nFIle"<<tmp;
	tmp = "#include \"" + tmp + "\"\n\n";
	f <<tmp;
	for (auto it = functions.begin(); it != functions.end(); ++it) {
		f << *it;
		cout <<' ' <<*it;
	}
	f.close(); // close .cpp file
}


int main (int argc, char *argv[]) {
	keywordSearch(argc, argv);
	return 0;
}
