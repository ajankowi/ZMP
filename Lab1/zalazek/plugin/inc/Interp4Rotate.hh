#ifndef  COMMAND4ROTATE_HH
#define  COMMAND4ROTATE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"


/*!
 * \file
 * \brief Definicja klasy Interp4Rotate
 *
 * Plik zawiera definicj� klasy Interp4Rotate ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, kt�re wymusza jego ruch obrotowy
 *
 *  Klasa modeluje ...
 */
class Interp4Rotate: public Interp4Command {
  /*
   *  Tu nale�y zdefiniowa� pola, kt�re s� niezb�dne
   *  do przechowywania warto�ci parametr�w danego polecenia.
   *  Ponie�ej zdefiniowane jest tylko jedno pole jako przyk�ad.
   */
  double  _Angular_Velocity;//!< pole przechowuj�ce szybko�� k�tow� w deg/s
  //double  _Axis; //!<pole przechowuj�ce numer si obrotu
  double  _Angle; //!< pole przechowuj�ce k�t obrotu w deg
  std::string _Axis_Name;//!<pole przechowuj�ce nazw� osi obrotu
  std::string _Obj_Name;//!<pole przechowuj�ce nazw� obiektu

 public:
  /*!
   * \brief
   */
  Interp4Rotate();
  /*!
   * \brief Wy�wietla posta� bie��cego polecenia (nazw� oraz warto�ci parametr�w)
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wy�wietla sk�adni� polecenia
   */
  virtual void PrintSyntax() const;
  /*!
   * \brief Wy�wietla nazw� polecenia
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief Wykonuje polecenie oraz wizualizuje jego realizacj�
   */
  virtual bool ExecCmd( MobileObj  *pMobObj, GuardedSocket *pAccessCtrl) const;
  /*!
   * \brief Czyta warto�ci parametr�w danego polecenia
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Wy�wietla warto�ci wczytanych parametr�w
   */
  virtual void PrintParams() {}
  /*!
   * \brief
   *
   *  Ta metoda nie musi by� zdefiniowna w klasie bazowej.
   */
  static Interp4Command* CreateCmd();
 };

#endif
