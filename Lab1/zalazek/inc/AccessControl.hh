#ifndef ACCESSCONTROLL_HH
#define ACCESSCONTROLL_HH

#include <mutex>

/*!
 * \file
 * \brief Zawiera definicj� klasy AccessControl
 */

/*!
 * \brief Przechowuje informacje o zmianie
 *
 *  Przechowuje informacje o zmianie z zabezpieczeniem
 *  wielow�tkowej modyfikacji.
 */
class AccessControl {
  /*!
   * \brief Zapewnia wy��czny dost�p do obiektu w trakcie modyfikacji.
   */
  std::mutex _InternalGuard;
  /*!
   * \brief Przechowuje informacje o zmianie.
   *
   * Przechowuje informacje o tym czy zmiana nast�pi�a (\p true) czy te�
   * nie (\p false).
   */
  bool _Changed = false;
  /*!
   * \brief Wykorzystywany do blokowania ca�ej sceny.
   */
  std::mutex _ExternalGuard;
  public:
    /*!
     * \brief Dost�p do informacji o zmianie.
     *
     * Dost�p do informacji o zmianie.
     * \retval true - gdy zmiana nast�pi�a.
     * \retval false - w przypadku przeciwnym.
     */
    bool IsChanged() const {
      return _Changed;
    }
  /*!
   * \brief Zaznaczenie, �e zmiana nast�pi�a.
   */
  void MarkChange() {
    _InternalGuard.lock();
    _Changed = true;
    _InternalGuard.unlock();
  }
  /*!
   * \brief Skasowanie informacji, �e zmiana nast�pi�a.
   */
  void CancelChange() {
    _InternalGuard.lock();
    _Changed = false;
    _InternalGuard.unlock();
  }
  /*!
   * \brief Zamyka dost�p ca�ej sceny.
   */
  void LockAccess() {
    _ExternalGuard.lock();
  }
  /*!
   * \brief Otwiera dost�p do ca�ej sceny.
   */
  void UnlockAccess() {
    _ExternalGuard.unlock();
  }
};

#endif
