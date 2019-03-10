#include<windows.h>
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int main(){
	cout<<"Clear your blog. Are you sure? (y/n) ";
	char c;
	cin>>c;
	if(c!='Y'&&c!='y') return 0;
	 
	string command = "del /Q ";
	string path = "html\\*.html";
	system(command.append(path).c_str());
	
	ifstream copy("html/temp_index_SPARE.txt");
	ofstream index("index.html");
	ofstream help("html/temp_index.txt");
	
	string line;
	while(getline(copy,line)){
		index<<line<<endl;
		help<<line<<endl;
	}
	cout<<"index.html has been reset."<<endl;
	
	cin.ignore();
	cin.get();
}
