#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicj� klasy Interp4Move kt�ra odpowiada za poruszanie obiektem z na dan� odleg�o�� z zadan� pr�dko�ci�.
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, kt�re wymusza jego ruch do przodu
 *
 *  Klasa modeluje polecenie umozliwiaj�ce ruch do przodu z zadan� pr�dko�ci�.
 * Dodatkowo definiujemy odleg�o�� do przejechania oraz nazw�.
 */
class Interp4Move: public Interp4Command {
  /*
   *  Tu nale�y zdefiniowa� pola, kt�re s� niezb�dne
   *  do przechowywania warto�ci parametr�w danego polecenia.
   *  Ponie�ej zdefiniowane jest tylko jedno pole jako przyk�ad.
   */
  double _Speed_mmS;//!< pole przechowuj�ce pr�dko��
  double _Lenght;//!< pole przechowuj�ce d�ugo�� drogi
  std::string _Obj_Name;//!< pole przechowuj�ce nazw�
 public:
  /*!
   * \brief Konstruktor klasy
   */
  Interp4Move();  
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
