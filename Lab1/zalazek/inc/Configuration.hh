#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH
#include "MobileObj.hh"

#include <map>

#include <string>

#include <vector>

#include <memory>

/*!
 * \file
 * \brief Definicja klasy Configuration.
 *
 * Plik zawiera definicj� klasy Configuration,
 * kt�ra przechowuje konfiguracj� sceny i list� bibliotek,
 * odczytywana z pliku XML.
 */

class Configuration {

  /*!
   * \brief Lista obiekt�w mobilnych w postaci struktury mapy
   */
  std::map < std::string, MobileObj * > ObjectsList;
  /*!
   * \brief Lista nazw bibliotek
   */
  std::vector < std::string > LibraryList;

  public:
    ~Configuration() {
      ObjectsList.clear();
    }
  /*!
   * \brief Metoda dodaje obiekt mobilny odczytany z pliku konfiguracyjnego XML
   *\param[in] LibraryName - nazwa biblioteki, kt�ra zostaje dodana do listy
   */
  void AddLibraryName(const std::string & LibraryName);
  /*!
   * \brief Metoda dodaje nazw� biblioteki odczytan� z pliku konfiguracyjnego XML
   *\param[in] ObjectName - nazwa obiektu, kt�ry zastaje dodany do listy
   * \param[in] Scale - wektor z warto�ciami skali obiektu
   * \param[in] RGB - napis z warto�ciami Red Green Blue obiektu
   */

  //void AddMobileObj(const std::string &ObjectName,const Vector3D &Scale, const std::string &RGB);
  void AddMobileObj(const std::string & ObjectName,
    const Vector3D & Scale,
      const std::string & RGB,
        const Vector3D & Shift,
          const Vector3D & RotXYZ,
            const Vector3D & Trans);

  /*!
   * \brief Metoda zwraca list� nazw bibliotek
   */
  std::vector < std::string > & getLibraryList() {
    return this -> LibraryList;
  }
  /*!
   * \brief Metoda zwraca list� obiekt�w mobilnych
   */
  std::map < std::string, MobileObj * > & getObjectList() {
    return this -> ObjectsList;
  }

};

#endif
