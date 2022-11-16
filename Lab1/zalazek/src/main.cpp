#include <iostream>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <iterator>
#include <dlfcn.h>
#include <cassert>
#include <cstdio>


#include "LibInterface.hh"
#include "Set4LibInterfaces.hh"
#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "Configuration.hh"

using namespace std;

#define LINE_SIZE 500


bool ExecPreprocessor(const char *NazwaPliku, istringstream &IStrm4Cmds){

  string Cmd4Preproc = "cpp -P ";
  char Line[LINE_SIZE];
  ostringstream OTmpStrm;

  Cmd4Preproc += NazwaPliku;
  FILE * pProc = popen(Cmd4Preproc.c_str(), "r");

  if (!pProc)
    return false;

  while (fgets(Line, LINE_SIZE, pProc)) {
    OTmpStrm << Line;
  }

  IStrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}




int main()
{
	Configuration config;

	istringstream iStrm;

	map < string, MobileObj * > objectsList = config.getObjectList();
	Set4LibInterfaces * LibraryList = new Set4LibInterfaces(objectsList);


	cout << &LibraryList << endl;




	void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
	Interp4Command *(*pCreateCmd_Move)(void);

	void *pLibHnd_Rotate = dlopen("libInterp4Rotate.so",RTLD_LAZY);
	Interp4Command *(*pCreateCmd_Rotate)(void);

	void *pLibHnd_Pause = dlopen("libInterp4Pause.so",RTLD_LAZY);
	Interp4Command *(*pCreateCmd_Pause)(void);

	void *pLibHnd_Set = dlopen("libInterp4Set.so",RTLD_LAZY);
	Interp4Command *(*pCreateCmd_Set)(void);


	void *pFun_move;

	void *pFun_rotate;

	void *pFun_pause;

	void *pFun_set;

	if (!pLibHnd_Move) {
		cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
		return 1;
	}

	if (!pLibHnd_Rotate) {
		cerr << "!!! Brak biblioteki: Interp4Rotate.so" << endl;
		return 1;
	}

	if (!pLibHnd_Pause) {
		cerr << "!!! Brak biblioteki: Interp4Pause.so" << endl;
		return 1;
	}

	if (!pLibHnd_Set) {
		cerr << "!!! Brak biblioteki: Interp4Set.so" << endl;
		return 1;
	}





	pFun_move = dlsym(pLibHnd_Move,"CreateCmd");
	if (!pFun_move) {
		cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
		return 1;
	}

	pFun_rotate = dlsym(pLibHnd_Rotate,"CreateCmd");
	if (!pFun_rotate) {
		cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
		return 1;
	}

	pFun_pause = dlsym(pLibHnd_Pause,"CreateCmd");
	if (!pFun_pause) {
		cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
		return 1;
	}


	pFun_set = dlsym(pLibHnd_Set,"CreateCmd");
	if (!pFun_set) {
		cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
		return 1;
	}




	pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_move);

	pCreateCmd_Rotate = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_rotate);

	pCreateCmd_Pause = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_pause);

	pCreateCmd_Set = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_set);


	Interp4Command *pCmd = pCreateCmd_Move();

	Interp4Command *pCmd_rotate = pCreateCmd_Rotate();

	Interp4Command *pCmd_pause = pCreateCmd_Pause();

	Interp4Command *pCmd_set = pCreateCmd_Set();

	ExecPreprocessor("prog.njpr", iStrm);

	cout << iStrm.str() << endl;


	cout << endl;
	cout << pCmd_set->GetCmdName() << endl;
	cout << endl;
	pCmd_set->PrintSyntax();
	cout << endl;
	pCmd_set->PrintCmd();
	cout << endl;


	cout << endl;
	cout << pCmd->GetCmdName() << endl;
	cout << endl;
	pCmd->PrintSyntax();
	cout << endl;
	pCmd->PrintCmd();
	cout << endl;
  

	cout << endl << endl;
	cout << pCmd_rotate->GetCmdName() << endl;
  	cout << endl;
  	pCmd_rotate->PrintSyntax();
  	cout << endl;
  	pCmd_rotate->PrintCmd();
  	cout << endl;


  	cout << endl;
  	cout << pCmd_pause->GetCmdName() << endl;
  	cout << endl;
  	pCmd_pause->PrintSyntax();
  	cout << endl;
  	pCmd_pause->PrintCmd();
  	cout << endl;



  	  delete pCmd;
  	  delete pCmd_rotate;
  	  delete pCmd_pause;
  	  delete pCmd_set;

  	  dlclose(pLibHnd_Move);
  	  dlclose(pLibHnd_Rotate);
  	  dlclose(pLibHnd_Pause);
  	  dlclose(pLibHnd_Set);

}
