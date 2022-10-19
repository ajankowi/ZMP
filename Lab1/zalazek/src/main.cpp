#include <iostream>
#include <cstdio>
#include <sstream>
#include <dlfcn.h>
#include <cassert>
#include "Interp4Command.hh"
#include "MobileObj.hh"

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

  istringstream iStrm;

  void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);

  void *pLibHnd_Rotate = dlopen("libInterp4Rotate.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Rotate)(void);




  void *pFun_move;

  void *pFun_rotate;

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }

  if (!pLibHnd_Rotate) {
    cerr << "!!! Brak biblioteki: Interp4Rotate.so" << endl;
    return 1;
  }





  pFun_move = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun_move) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }

  pFun_rotate = dlsym(pLibHnd_Rotate,"CreateCmd");
  if (!pFun_move) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }


  pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_move);

  pCreateCmd_Rotate = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_rotate);


  Interp4Command *pCmd = pCreateCmd_Move();

  Interp4Command *pCmd_rotate = pCreateCmd_Rotate();

  ExecPreprocessor("prog.njpr", iStrm);

  //cout << iStrm.str() << endl;

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


  delete pCmd;
  delete pCmd_rotate;

  dlclose(pLibHnd_Move);
}
