#include "Set4LibInterfaces.hh"
#include <iostream>
#include <vector>



using namespace std;


Set4LibInterfaces::Set4LibInterfaces(map < string, MobileObj * > & _Object_List) {


	//this -> scena = new Scena(_Object_List);
	LoadLibrary("libs/libInterp4Move.so");
	LoadLibrary("libs/libInterp4Set.so");
	LoadLibrary("libs/libInterp4Rotate.so");
	LoadLibrary("libs/libInterp4Pause.so");
	//this->scena->AddMobileObj("Alpha");
}

Set4LibInterfaces::~Set4LibInterfaces(){

	_Lib_List.clear();

	//if (nullptr != scena)
    //delete scena;
}

void Set4LibInterfaces::LoadLibrary(string path){

	LibInterface * pLibrary = new LibInterface(path);

	_Lib_List.insert({
    pLibrary -> _Lib_Name,
    pLibrary
	});

}

bool Set4LibInterfaces::ExecPreprocessor(const char * NazwaPliku, istringstream & IStrm4Cmds)
{
	string Cmd4Preproc = "cpp -P ";
	char Line[500];
	ostringstream OTmpStrm;

	Cmd4Preproc += NazwaPliku;
	FILE * pProc = popen(Cmd4Preproc.c_str(), "r");

	if (!pProc)
		return false;

	while (fgets(Line, 500, pProc)) {
		OTmpStrm << Line;
	}

	IStrm4Cmds.str(OTmpStrm.str());
	return pclose(pProc) == 0;
}

bool Set4LibInterfaces::ReadCommands(istringstream & iStrm, int socket){


  return true;
}
