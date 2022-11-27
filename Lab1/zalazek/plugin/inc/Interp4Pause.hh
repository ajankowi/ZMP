#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Pause
 *
 * Plik zawiera definicj� klasy Interp4Pause ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, kt�re wymusza jego ruch do przodu
 *
 *  Klasa modeluje zatrzymanie w pozycji.
 */
class Interp4Pause: public Interp4Command {

private:
   int _Pause_time;


 public:
  /*!
   * \brief
   */
  Interp4Pause();
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
