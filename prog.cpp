#include<iostream>
#include<iomanip>
#include<cstdio>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
string month(int a){
	if(a==1) return "JAN";
	if(a==2) return "FEB";
	if(a==3) return "MAR";
	if(a==4) return "APR";
	if(a==5) return "MAY";
	if(a==6) return "JUN";
	if(a==7) return "JUL";
	if(a==8) return "AUG";
	if(a==9) return "SEP";
	if(a==10) return "OCT";
	if(a==11) return "NOV";
	else return "DEC";
}
int main(int argc,char *argv[]){
	if(argc<2) cout<<"Drag your TXT into this EXE."<<endl;
	else{
		char dubq='"';
		
		string center;
		center+="style=";
		center+=dubq;
		center+="text-align:center";
		center+=dubq;
		
		bool skipl=0;
		
		time_t t=time(0);
		tm* now=localtime(&t);
		string line,timen,title;
		ifstream fi(argv[1]);
		
		timen+="html/";
		if(now->tm_mday<10) timen+="0";
		timen+=to_string(now->tm_mday);
		if(now->tm_mon+1<10) timen+="0";
		timen+=to_string(now->tm_mon+1);
		timen+=to_string(now->tm_year+1900);
		timen+=".html";
		
		ifstream exists(timen);
		if(exists) skipl=1;
		exists.close();
		
		cout<<timen<<endl;
		
		freopen(timen.c_str(),"w",stdout); 
		cout<<"<!DOCTYPE html>\n<html>\n<head>\n<link rel="<<dubq<<"stylesheet"<<dubq<<"type="<<dubq<<"text/css"<<dubq<<" href="<<dubq<<"../css/main.css"<<dubq<<">\n<title>";
		
		if(now->tm_mday<10) cout<<"0";
		cout<<now->tm_mday;
		cout<<month(now->tm_mon+1);
		if((now->tm_year)%100==0) cout<<"0";
		if((now->tm_year)%100<10) cout<<"0";
		cout<<(now->tm_year)%100;
		
		cout<<"</title>\n</head>\n<body>"<<endl;
		
		cout<<"<p style="<<dubq<<"text-align:right"<<dubq<<"><a href="<<dubq<<"../index.html"<<dubq<<">Index</a>"<<endl;
		
		getline(fi,title); cout<<"<h1>"<<title<<"</h1>"<<endl<<"<h4>";
		
		cout<<"DATE: ";
		if(now->tm_mday<10) cout<<"0";
		cout<<now->tm_mday<<" ";
		cout<<month(now->tm_mon+1)<<" ";
		cout<<now->tm_year+1900;
		
		cout<<"</h4>"<<endl<<"<p>"<<endl;
		while(getline(fi,line)) cout<<line<<"<br>"<<endl;
		cout<<"</p>\n</body>\n</html>"<<endl;
		
		freopen("CON","w",stdout);
		cout<<"HTML file saved in html/"<<endl;
		
		fi.close();
		
		if(skipl==1){
			ifstream copy("html/temp_index.txt");
			ofstream nhtml("index.html");
			
			timen.clear();
			
			if(now->tm_mday<10) timen+="0";
			timen+=to_string(now->tm_mday);
			timen+=" ";
			timen+=month(now->tm_mon+1);
			timen+=" ";
			if((now->tm_year)%100==0) timen+="0";
			if((now->tm_year)%100<10) timen+="0";
			timen+=to_string((now->tm_year)%100);
			
			bool nextup=0;
			while(getline(copy,line)){
				if(nextup){
					nhtml<<"<td>"<<title<<"</td>"<<endl;
					nextup=0;
					continue;
				}
				if(line=="<td "+center+">"+timen+"</td>") nextup=1;
				nhtml<<line<<endl;
			}
			copy.close();
			nhtml.close();
			
			ifstream opy("index.html");
			ofstream html("html/temp_index.txt");
			while(getline(opy,line)) html<<line<<endl;
			opy.close();
			html.close();
			
			cout<<"Post edited."<<endl;
			goto fast;
		}
		
		ifstream rds("html/temp_index.txt");
		freopen("index.html","w",stdout);
		
		bool lupdat=0;
		while(getline(rds,line)){	
			if(lupdat==1){
				if(now->tm_mday<10) cout<<"0";
				cout<<now->tm_mday<<" ";
				cout<<month(now->tm_mon+1)<<" ";
				if((now->tm_year)%100==0) cout<<"0";
				if((now->tm_year)%100<10) cout<<"0";
				cout<<(now->tm_year)%100;
				lupdat=0;
				cout<<"</h4>"<<endl;
			}
			
			else if(line=="</table>"){		
				cout<<"<tr>\n<td "<<center<<">";
				if(now->tm_mday<10) cout<<"0";
				cout<<now->tm_mday<<" ";
				cout<<month(now->tm_mon+1)<<" ";
				if((now->tm_year)%100==0) cout<<"0";
				if((now->tm_year)%100<10) cout<<"0";
				cout<<(now->tm_year)%100;
				
				cout<<"</td>\n<td>"<<title<<"</td>\n<td "<<center<<">";
				cout<<"<a href="<<dubq<<timen<<dubq<<">Click Here</a>"<<"</td> </tr>"<<endl;
				
				cout<<endl<<"</table>"<<endl;
			}
			
			else cout<<line<<endl;
			if(line=="<h4>Last Updated:") lupdat=1; 
		}
		
		freopen("CON","w",stdout);
		
		ifstream copy("index.html");
		ofstream dest("html/temp_index.txt");
		while(getline(copy,line)) dest<<line<<endl;
		
		cout<<"index.html updated."<<endl;
	}
	
	fast:
		
	cin.get();
	return 0;
}

