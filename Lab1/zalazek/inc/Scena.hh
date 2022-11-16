#ifndef SCENA_HH
#define SCENA_HH


#include "MobileObj.hh"
#include <string>
#include <map>
#include <vector>

using namespace std;

class Scena{
  private:
    map < string,
  MobileObj * > _Object_List;
  public:

    Scena();

  Scena(map < string, MobileObj * > & List);

  ~Scena() {
    _Object_List.clear();
  };

  MobileObj * FindMobileObj(string sName);

  void AddMobileObj(string sName);

  map < string,
  MobileObj * > getObjList() {
    return this -> _Object_List;
  }
  vector < MobileObj * > getObjects();

};








































#endif
