/*Program to compile and run other programs*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[])
{
	if (argc == 1)
		return 0;
	string srcf = argv[1];	//source file
	string prog = srcf.substr( 0, srcf.length()-4 );	//program name
	string objf = prog + ".o";	//object file for compiled program
	string Mfile = "Makefile";	//Custom Makefile
	string Cmd;	//Custom System Command
	Cmd = "rm -f " + Mfile;
	system(Cmd.c_str());
	
	ofstream mfile;
	mfile.open(Mfile.c_str());
	mfile << "PROGRAM = " << prog << endl;
	mfile << "OBJECTS = " << objf << endl;
	mfile << "SOURCEF = " << srcf << endl;
	mfile << "MAKFILE = " << Mfile << endl << endl;
	mfile << "CPPOPTIONS = -IStanfordCPPLib -fvisibility-inlines-hidden" << endl;
	mfile << "LDOPTIONS = -L." << endl;
	mfile << "LIB = -lStanfordCPPLib" << endl << endl;
	mfile << prog << ":	$(OBJECTS)" << endl;
	mfile << "			g++ -o $(PROGRAM) $(LDOPTIONS) $(OBJECTS) $(LIB)" << endl << endl;
	mfile << objf << ":	$(SOURCEF) $(MAKFILE) libStanfordCPPLib.a" << endl;
	mfile << "				g++ -c $(CPPOPTIONS) $(SOURCEF)" << endl << endl;
	mfile << "libStanfordCPPLib.a:" <<endl;
	mfile << "	@rm -f libStanfordCPPLib.a" << endl;
	mfile << "	(cd StanfordCPPLib; make all)" << endl;
	mfile << "	ln -s StanfordCPPLib/libStanfordCPPLib.a ." << endl << endl;
	mfile << "clean:" << endl;
	mfile << "	rm -f $(OBJECTS) $(PROGRAM)" << endl << endl;
	mfile.close();
	
	Cmd = "make -f " + Mfile + " " + prog;
	system(Cmd.c_str());
	string CLA="";
	if (argc > 2){
		int count = 2;
		while ( count != argc )
		{
			CLA = CLA + " " + argv[count];
			count++;
		};
	}
	Cmd = "./"+prog+CLA;
	cout << Cmd<<endl;;
	system(Cmd.c_str());
	/* Uncomment to automatically delete Makefile
	Cmd = "rm -f " + Mfile;
	system(Cmd.c_str());*/
	return 0;
}
