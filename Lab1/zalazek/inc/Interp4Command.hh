#ifndef INTERP4COMMAND_HH
#define INTERP4COMMAND_HH

#include <iostream>

#include "MobileObj.hh"
#include "GuardedSocket.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Command
 *
 * Plik zawiera definicj� klasy Interp4Command ...
 */

/*!
 * \brief Modeluje abstrakcyjne polecenie dla robota mobilnego
 *
 *  Klasa modeluje ...
 */
class Interp4Command {
  public:
    /*!bObj, int Socket ) const = 0;
     * \brief Destruktor wirtualny ze wzgledu na klasy pochodne
     *
     *
     */
    virtual~Interp4Command() {}
  /*!
   * \brief Wy�wietla posta� bie��cego polecenia (nazw� oraz warto�ci parametr�w).
   */
  virtual void PrintCmd() const = 0;
  /*!
   * \brief Wy�wietla sk�adni� polecenia.
   */
  virtual void PrintSyntax() const = 0;
  /*!
   * \brief Wy�wietla nazw� polecenia.
   */
  virtual
  const char * GetCmdName() const = 0;
  /*!
   * \brief Wykonuje polecenie oraz wizualizuje jego realizacj�.
   */
  virtual bool ExecCmd(MobileObj * pMobObj, GuardedSocket * pAccCtrl) const = 0;
  //virtual bool ExecCmd( MobileObj *pMobObj, int Socket ) const = 0;
  /*!
   * \brief Czyta warto�ci parametr�w danego polecenia.
   */
  virtual bool ReadParams(istream & Strm_CmdsList) = 0;
};

#endif
