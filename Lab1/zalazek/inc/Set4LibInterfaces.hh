#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <sstream>
#include "LibInterface.hh"
#include <memory>

#include "Scena.hh"
//#include "klient.hh"


class Set4LibInterfaces {
  private:

    std::map < std::string, LibInterface * > _Lib_List;

  //Scena * scena;

  public:

    Set4LibInterfaces(std::map < std::string, MobileObj * > & _Object_List);


  ~Set4LibInterfaces();

  void LoadLibrary(std::string path);

  bool ReadCommands(std::istringstream & iStrm, int socket);

  bool ExecPreprocessor(const char * NazwaPliku, std::istringstream & IStrm4Cmds);

  //Scena * getScena() {
  //  return this -> scena;
  //}
};

#endif
