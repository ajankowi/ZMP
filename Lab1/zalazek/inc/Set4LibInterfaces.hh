#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <sstream>

#include "LibInterface.hh"

#include <memory>

#include "Scena.hh"

#include "klient.hh"

/*!
 * \file
 * \brief Definicja klasy Set4LibInterfaces.
 *
 * Klasa ma na celu wczytywanie i obs�ug� wtyczek kt�re s� u�ywane do poruszania danym obiektem
 */
class Set4LibInterfaces {
  private:

    std::map < std::string, LibInterface * > _Lib_List; //!< Lista komend przechowywane w strukturze map

  Scena * scena; //!< Wska�nik do obiektu klasy Scena przechowuj�cej wszystkie obiekty

  public:
    /*!
     * \brief Konstruktor.
     *
     * Konstruktor ma za zadanie za�adawanie wszystkich wtyczek do wybranej struktury
     */
    Set4LibInterfaces(std::map < std::string, MobileObj * > & _Object_List);

  /*!
   * \brief Destruktor
   */
  ~Set4LibInterfaces();

  /*!
   * \brief Metoda wczytuje podan� biblioteke dynamiczne do struktury
   *
   * \param[in] path - �cie�ka do biblioteki dynamicznej
   */
  void LoadLibrary(std::string path);

  /*!
   * \brief Metoda interpretuje ci�g znak�w, i przypisuje parametry z instrukcji dla odpowiedniej komendy
   *
   * \param[in] iStrm - Strumie� utworzony przez funkcj� ExecPreprocessor
   */
  bool ReadCommands(std::istringstream & iStrm, int socket);

  bool ExecPreprocessor(const char * NazwaPliku, std::istringstream & IStrm4Cmds);

  Scena * getScena() {
    return this -> scena;
  }
};

#endif
