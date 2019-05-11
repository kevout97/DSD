#include <iostream>
#include <string>

using namespace std;

class FileClass { 
	public:
		FileClass(char * nombre, int size);
		FileClass();
		char * getName();
		int getSize();
		void setName(char* nombre);
		char* getData(char* nombre);
		void writeFile(char* nombre,char* contenido);
        void deleteFile(char* nombre);
		int getSizeFile(char* nombre);

	private:
		char name[255];
        int sizeFile;
};