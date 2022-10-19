#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include "Interp4Command.hh"
#include <string>
#include <iostream>

using namespace std;

class LibInterface {
  private:
    void * handler;

  public:

  string _Lib_Name;
  LibInterface(string path);

  ~LibInterface();

  Interp4Command * ( * pCreateCmd)(void);
};
#endif
