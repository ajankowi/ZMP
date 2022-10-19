#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include "Interp4Command.hh"
#include <string>
#include <map>
#include <dlfcn.h>
#include <iostream>

using namespace std;

class LibInterface {
  private:
    void * handler;

  public:

    string _Lib_Name;
  LibInterface(std::string path);

  ~LibInterface();

  Interp4Command * ( * pCreateCmd)(void);
};
#endif
