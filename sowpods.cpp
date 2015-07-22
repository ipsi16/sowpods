#include<iostream>
#include<fstream>
#include<cstring>
#include<map>
using namespace std;
int main(){
	char primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
	unsigned long p=1;
	int index;
	string line;
	map<unsigned long int, string> m;
    ifstream myfile ("sowpods_data.txt");
    
    if (myfile.is_open()){
    	while ( getline (myfile,line) ){
    		p = 1, index = 0;
    		int size = line.size();
	    	while(index < size){
				p *= primes[line[index++] - 97];
			}
			if(m.find(p) == m.end()){
				m[p]=line;
			}
			else {
			m[p]= m[p] + " " + line;
		    } 
    	}
    	ofstream myfile ("sowpods_output.txt");
    	for(map<unsigned long int, string>::iterator it = m.begin(); it != m.end() ; it++){
    		if(it->second.find(" ",0) != -1){
    		myfile<<it->second<<endl;
			}
		}
    myfile.close();
    }

    else {
	 cout << "Unable to open file";
    }
    getchar();
    return 0;
	
	
}
