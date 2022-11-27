#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH

#include <string>
#include <sstream>

#include "Vector3D.hh"


/*!
 * \file
 * \brief Zawiera definicj� klasy MobileObj
 *
 * Plik zawiera definicj� klasy MobileObj.
 * Definicja to mo�e by� rozszerzona i zmienione mog�
 * by� nazwy p�l. Obowi�zkowe s� jedynie nazwy metod.
 */

/*!
 * Nazwy p�l klasy s� jedynie propozycj� i mog� by� zmienione
 * Nazwy metod s� obowi�zuj�ce.
 */
class MobileObj {
  /*!
   * \brief K�t \e yaw reprezentuje rotacj� zgodnie z ruchem wskaz�wek zegara
   *        wok� osi \e OZ.
   *
   * K�t \e yaw reprezentuje rotacj� zgodnie z ruchem wskaz�wek zegara
   * wok� osi \e OZ. Warto�� k�ta wyra�ona jest w stopniach.
   */
  double _Ang_Yaw_deg = 0;

  /*!
   * \brief K�t \e pitch reprezentuje rotacj� zgodnie z ruchem wskaz�wek zegara
   *        wok� osi \e OY.
   *
   * K�t \e pitch reprezentuje rotacj� zgodnie z ruchem wskaz�wek zegara
   * wok� osi \e OY. Warto�� k�ta wyra�ona jest w stopniach.
   */
  double _Ang_Pitch_deg = 0;

  /*!
   * \brief K�t \e roll reprezentuje rotacj� zgodnie z ruchem wskaz�wek zegara
   *        wok� osi \e OX.
   *
   * K�t \e roll reprezentuje rotacj� zgodnie z ruchem wskaz�wek zegara
   * wok� osi \e OX. Warto�� k�ta wyra�ona jest w stopniach.
   */
  double _Ang_Roll_deg = 0;

  /*!
   * \brief Wsp�rz�dne aktualnej pozycji obiektu.
   *
   * Wsp�rz�dne aktualnej pozycji obiektu. Przyjmuje si�,
   * �e wsp�rz�dne wyra�one s� w metrach.
   */
  Vector3D _Position_m;

  /*!
   * \brief Nazwa obiektu, kt�ra go indentyfikuje.
   *
   * Nazwa obiektu, kt�ra go indentyfikuje. Z tego wzgl�du musi
   * musi to by� nazwa unikalna w�r�d wszystkich obiekt�w na scenie.
   */
  string _Name;

  Vector3D _Scale;

  Vector3D _Shift;

  int color[3];

  public:
    /*!
     * \brief Zwraca informacj� o stanie obiektu
     *
     * \return ciag znak�w zawieraj�cy informacje o obiekcie.
     */
    string ActualPosition() {
      char buffer[100];
      int len = sprintf(buffer, " Name=%s RotXYZ_deg=(%f,%f,%f)\n", this -> _Name.c_str(), this -> _Ang_Yaw_deg, this -> _Ang_Pitch_deg, this -> _Ang_Roll_deg);
      string result(buffer, len);

      return result;
    }

  /*!
   * \brief Zwraca informacj� o stanie obiektu
   *
   * \return ciag znak�w zawieraj�cy informacje o obiekcie.
   */
  string returnParameters() {
    char buffer[200];
    int length = sprintf(buffer, "Name=%s RGB=(%d,%d,%d) Scale=(%f,%f,%f) Shift=(%f,%f,%f) RotXYZ_deg=(%f,%f,%f) Trans_m=(%f,%f,%f)\n",
      this -> _Name.c_str(), this -> color[0], this -> color[1], this -> color[2], this -> _Scale[0], this -> _Scale[1], this -> _Scale[2],
      this -> _Shift[0], this -> _Shift[1], this -> _Shift[2], this -> _Ang_Roll_deg, this -> _Ang_Pitch_deg, this -> _Ang_Yaw_deg, this -> _Position_m[0], this -> _Position_m[1], this -> _Position_m[2]);
    string result(buffer, length);
    string message = result;
    // Ta instrukcja to tylko uproszczony przyk�ad
    // cout << objectPointer->movingState;
    return message; // Tu musi zosta� wywo�anie odpowiedniej                  // metody/funkcji geruj�cej polecenia dla serwera
  }
  /*!
   * \brief Udost�pia warto�� k�ta \e roll.
   *
   * Udost�pia warto�� k�ta \e roll. Jest ona wyra�ona w stopniach.
   */
  double GetAng_Roll_deg() const {
    return _Ang_Roll_deg;
  }
  /*!
   * \brief Udost�pia warto�� k�ta \e pitch.
   *
   * Udost�pia warto�� k�ta \e pitch. Jest ona wyra�ona w stopniach.
   */
  double GetAng_Pitch_deg() const {
    return _Ang_Pitch_deg;
  }
  /*!
   * \brief Udost�pia warto�� k�ta \e yaw.
   *
   * Udost�pia warto�� k�ta \e yaw. Jest ona wyra�ona w stopniach.
   */
  double GetAng_Yaw_deg() const {
    return _Ang_Yaw_deg;
  }

  /*!
   * \brief Zmienia warto�� k�ta \e roll.
   *
   * Zmienia warto�� k�ta \e roll.
   * \param[in] Ang_Roll_deg - nowa warto�� k�ta \e roll wyra�ona w stopniach.
   */
  void SetAng_Roll_deg(double Ang_Roll_deg) {
    _Ang_Roll_deg = Ang_Roll_deg;
  }
  /*!
   * \brief Zmienia warto�� k�ta \e pitch.
   *
   * Zmienia warto�� k�ta \e pitch.
   * \param[in] Ang_Pitch_deg - nowa warto�� k�ta \e pitch wyra�ona w stopniach.
   */
  void SetAng_Pitch_deg(double Ang_Pitch_deg) {
    _Ang_Pitch_deg = Ang_Pitch_deg;
  }
  /*!
   * \brief Zmienia warto�� k�ta \e yaw.
   *
   * Zmienia warto�� k�ta \e yaw.
   * \param[in] Ang_Yaw_deg - nowa warto�� k�ta \e yaw wyra�ona w stopniach.
   */
  void SetAng_Yaw_deg(double Ang_Yaw_deg) {
    _Ang_Yaw_deg = Ang_Yaw_deg;
  }

  /*!
   * \brief Udost�pnia wsp�rz�dne po�o�enia obiektu w trybie tylko do odczytu.
   *
   * Udost�pnia wsp�rz�dne punktu, kt�ry definiuje po�o�enia obiektu
   * w trybie tylko do odczytu.
   * Domy�lnie przyjmuje si�, �e jest to geometryczny �rodek bry�y.
   */
  const Vector3D & GetPositoin_m() const {
    return _Position_m;
  }
  /*!
   * \brief Udost�pnia wsp�rz�dne po�o�enia obiektu w trybie modyfikacji.
   *
   * Udost�pnia wsp�rz�dne punktu, kt�ry definiuje po�o�enia obiektu
   * w trybie modyfikacji.
   * Domy�lnie przyjmuje si�, �e jest to geometryczny �rodek bry�y.
   */
  Vector3D & UsePosition_m() {
    return _Position_m;
  }
  /*!
   * \brief Zmienia wsp�rz�dne po�o�enia obiektu.
   *
   * Zmienia wsp�rz�dne punktu, kt�ry definiuje po�o�enia obiektu.
   * Domy�lnie przyjmuje si�, �e jest to geometryczny �rodek bry�y.
   * \param[in] rPos_m - wsp�rz�dne nowgo po�o�enia. Przyjmuje si�,
   *                     �e s� one wyra�one w metrach.
   */
  void SetPosition_m(const Vector3D & rPos_m) {
    _Position_m = rPos_m;
  }

  /*!
   * \brief Zmienia nazw� obiektu.
   *
   *  Zmienia nazw� obiektu.
   *  \param[in] sName - nowa nazwa obiektu.
   */
  void SetName(const char * sName) {
    _Name = sName;
  }
  /*!
   * \brief Udost�pnia nazw� obiektu.
   *
   * Udost�pnia nazw� obiektu w trybie tylko do odczytu.
   */
  const string & GetName() const {
    return _Name;
  }

  /*!
   * \brief Zmienia wielko�� obiektu
   *
   * \param[in] Scale - wektor3D z warto�ciami skali XYZ
   */
  void SetScale(const Vector3D & Scale) {
    _Scale = Scale;
  }

  /*!
   * \brief Zmienia kolor obiektu.
   *
   * \param[in] RGB - kolor w postaci RGB
   */
  void setColor(const string RGB) {
    istringstream IStrm;
    IStrm.str(RGB);
    IStrm >> this -> color[0] >> this -> color[1] >> this -> color[2];
  }

  void setShift(const Vector3D & Shift) {
    _Shift = Shift;
  }
};

#endif
