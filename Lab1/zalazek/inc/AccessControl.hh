#ifndef ACCESSCONTROLL_HH
#define ACCESSCONTROLL_HH

#include <mutex>

/*!
 * \file
 * \brief Zawiera definicjê klasy AccessControl
 */

/*!
 * \brief Przechowuje informacje o zmianie
 *
 *  Przechowuje informacje o zmianie z zabezpieczeniem
 *  wielow¹tkowej modyfikacji.
 */
class AccessControl {
  /*!
   * \brief Zapewnia wy³¹czny dostêp do obiektu w trakcie modyfikacji.
   */
  std::mutex _InternalGuard;
  /*!
   * \brief Przechowuje informacje o zmianie.
   *
   * Przechowuje informacje o tym czy zmiana nast¹pi³a (\p true) czy te¿
   * nie (\p false).
   */
  bool _Changed = false;
  /*!
   * \brief Wykorzystywany do blokowania ca³ej sceny.
   */
  std::mutex _ExternalGuard;
  public:
    /*!
     * \brief Dostêp do informacji o zmianie.
     *
     * Dostêp do informacji o zmianie.
     * \retval true - gdy zmiana nast¹pi³a.
     * \retval false - w przypadku przeciwnym.
     */
    bool IsChanged() const {
      return _Changed;
    }
  /*!
   * \brief Zaznaczenie, ¿e zmiana nast¹pi³a.
   */
  void MarkChange() {
    _InternalGuard.lock();
    _Changed = true;
    _InternalGuard.unlock();
  }
  /*!
   * \brief Skasowanie informacji, ¿e zmiana nast¹pi³a.
   */
  void CancelChange() {
    _InternalGuard.lock();
    _Changed = false;
    _InternalGuard.unlock();
  }
  /*!
   * \brief Zamyka dostêp ca³ej sceny.
   */
  void LockAccess() {
    _ExternalGuard.lock();
  }
  /*!
   * \brief Otwiera dostêp do ca³ej sceny.
   */
  void UnlockAccess() {
    _ExternalGuard.unlock();
  }
};

#endif
