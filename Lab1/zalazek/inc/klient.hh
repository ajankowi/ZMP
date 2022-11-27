#ifndef KLIENT_HH
#define KLIENT_HH

#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>

#include "GuardedSocket.hh"
#include "Port.hh"
#include "Scena.hh"


using namespace std;



/*!
 * \brief Wysy�a napis do poprzez gniazdo sieciowe.
 *
 * Wysy�a napis do poprzez gniazdo sieciowe.
 * \param[in] Sk2Server - deskryptor gniazda sieciowego, poprzez kt�re
 *                        ma zosta� wys�any napis w sensie j�zyka C.
 * \param[in] sMesg - zawiera napis, kt�ry ma zosta� wys�any poprzez
 *                    gniazdo sieciowe.
 */
int Send(int Sk2Server,
  const char * sMesg);

/*!
 * \brief Modeluje nadajnik polece� odzwierciedlaj�cych aktualny stan sceny.
 *
 * Modeluje nadajnik polece� odzwierciedlaj�cych aktualny stan sceny.
 * W tym celu monitoruje zmiany na scenie, a gdy je wykryje przesy�a
 * informacje o aktualnej pozycji wszystkich obiekt�w.
 */
class Sender {
  /*!
   * \brief Warto�� tego pola decyduje o kontynuacji wykonywania w�tku.
   *
   * Warto�� tego pola decyduje o kontynuacji wykonywania w�tku.
   * W przypadku warto�ci \p true, p�tla w�tku b�dzie wykonywana.
   * Natomiast warto�� \p false powoduje przerwanie p�tli.
   */
  volatile bool _ContinueLooping = true;
  /*!
   * \brief Deskryptor gniazda sieciowego, poprzez kt�re wysy�ane s� polecenia.
   */
  int _Socket = 0;
  /*!
   * \brief Wska�nik na scen�, kt�re stan jest przesy�any w postaci
   *        polece� do serwera graficzneg.
   */
  Scena * _pScn = nullptr;

  std::thread klient_thread;

  public:
    /*!
     * \brief Inicjalizuje obiekt deskryptorem gniazda i wska�nikiem
     *        na scen�, na zmian� stanu kt�re b�dzie ten obiekt reagowa�.
     */
    Sender(int Socket, Scena * pScn);

  ~Sender() {
    this -> CancelCountinueLooping();
    this -> klient_thread.join();
    close(_Socket);
  }

  /*!
   * \brief Sprawdza, czy p�tla w�tku mo�e by� wykonywana.
   *
   * Sprawdza, czy p�tla w�tku mo�e by� wykonywana.
   * \retval true - p�tla w�tku mo�e by� nadal wykonywana.
   * \retval false - w przypadku przeciwnym.
   */
  bool ShouldCountinueLooping() const {
    return _ContinueLooping;
  }
  /*!
   * \brief Powoduje przerwanie dzia�ania p�tli w�tku.
   *
   * Powoduje przerwanie dzia�ania p�tli w�tku.
   * \warning Reakcja na t� operacj� nie b�dize natychmiastowa.
   */
  void CancelCountinueLooping() {
    _ContinueLooping = false;
  }

  /*!
   * \brief Ta metoda jest de facto tre�ci� w�tku komunikacyjnego
   *
   * Przegl�da scen� i tworzy odpowiednie polecenia, a nast�pnie
   * wysy�a je do serwera.
   * \param[in] Socket - deskryptor gniazda sieciowego, poprzez kt�re
   *                     wysy�ane s� polecenia.
   */
  void Watching_and_Sending() {
    while (ShouldCountinueLooping()) {
      if (!_pScn -> IsChanged()) {
        usleep(10000);
        continue;
      }
      _pScn -> LockAccess();

      //------- Przegl�danie tej kolekcji to uproszczony przyk�ad

      //Send(_Socket,"Clear\n"); // To jest konieczne, aby usun�� wcze�niejsze obiekty.
      //cout << "Clear\n";
      std::map < std::string, MobileObj * > MobileObjects = _pScn -> getObjList();
      std::vector < MobileObj * > objects_list;
      std::map < std::string, MobileObj * > ::iterator Iter;

      for (Iter = MobileObjects.begin(); Iter != MobileObjects.end(); Iter++) {
        objects_list.push_back(Iter -> second);
      }

      for (MobileObj * object_ptr: objects_list) {
        //MobileObj* object = object_ptr;

        std::string message = "UpdateObj ";
        message += object_ptr -> returnParameters();
        //std::cout<<"lul"<<message<<"XDDDD"<<std::endl;
        // Ta instrukcja to tylko uproszczony przyk�ad
        // cout << objectPointer->movingState;
        Send(_Socket, message.c_str()); // Tu musi zosta� wywo�anie odpowiedniej
        // metody/funkcji geruj�cej polecenia dla serwera.
      }
      //Send(_Socket,"Display\n"); // To jest konieczne, aby zobaczy� zmiany
      //cout << "Display\n";

      _pScn -> CancelChange();
      _pScn -> UnlockAccess();
    }
  }
};

/*!
 * \brief Funkcja jest tre�ci� w�tku komunikacyjnego
 *
 * Funkcja jest tre�ci� w�tku komunikacyjnego.
 * \param[in] rSender - odpowiada za �ledenie zmian na scenie
 *                      i przesy�anie do serwera graficznego
 *                      aktualnego stanu sceny, gdy uleg� on zmianie.
 */
void Fun_CommunicationThread(Sender * pSender);

/*!
 * Otwiera po��czenie sieciowe
 * \param[out]  rSocket - deskryptor gniazda, poprzez kt�re mo�e by�
 *                        realizowana komunikacja sieciowa.
 */
bool OpenConnection(int & rSocket);

void close(int socket, Sender & clientSender, thread t);


#endif
