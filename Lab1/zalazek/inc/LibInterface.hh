#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <string>
#include <map>
#include <dlfcn.h>
#include <iostream>

#include "Interp4Command.hh"


using namespace std;
/*!
 * \file
 * \brief Definicja klasy LibInterface
 *
 * Klasa ma na celu obs�ug� interfejsu bibliotek
 */
class LibInterface {
  private:
    void * handler; //!<uchwyt do biblioteki

  public:

    string _Lib_Name; //!<pole przechowuje nazw� polecenia
  /*!
   * \brief Kontruktor
   *
   * param[in] path - �cie�ka do pliku biblioteki dynamicznej
   */
  LibInterface(string path);
  /*!
   * \brief Destruktor
   *
   * Zamyka biblioteke przed usuni�ci�m obiektu
   */
  ~LibInterface();
  /*!
   * \brief Metoda tworzy obiekt klasy Interp4Command, kt�ry s�u�y do modelowanai polecenia
   */
  Interp4Command * ( * pCreateCmd)(void);
};
#endif
