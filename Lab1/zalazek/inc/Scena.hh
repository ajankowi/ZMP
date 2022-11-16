#ifndef SCENA_HH
#define SCENA_HH


#include "MobileObj.hh"
#include <string>
#include <map>
#include <vector>

using namespace std;

class Scena{
  private:
    std::map < std::string,
  MobileObj * > _Object_List;
  public:

    Scena();

  Scena(std::map < std::string, MobileObj * > & List);

  ~Scena() {
    _Object_List.clear();
  };

  MobileObj * FindMobileObj(std::string sName);

  void AddMobileObj(std::string sName);

  std::map < std::string,
  MobileObj * > getObjList() {
    return this -> _Object_List;
  }
  std::vector < MobileObj * > getObjects();

};








































#endif
