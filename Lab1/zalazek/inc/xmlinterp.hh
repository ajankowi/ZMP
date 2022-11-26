#ifndef XMLINTERP4ACTIONS_HH
#define XMLINTERP4ACTIONS_HH

#include <string>

#include <xercesc/util/XMLString.hpp>

#include <xercesc/sax2/XMLReaderFactory.hpp>

#include <xercesc/util/PlatformUtils.hpp>

#include <xercesc/sax/Locator.hpp>

#include <xercesc/sax2/Attributes.hpp>

#include <xercesc/sax2/DefaultHandler.hpp>

//XERCES_CPP_NAMESPACE_USE

#include "Configuration.hh"


/*!
 * \brief Implementuje reakcje na napotkane elementu opisu akcji
 *
 * Klasa zawiera zestaw metod, kt�re wywo�ywane s� w trakcie czytania i analizy
 * pliku XML.
 */
class XMLInterp4Config: public xercesc::DefaultHandler {
  public: Configuration & config;
  /*!
   * \brief Inicjalizuje obiekt i kojarzy go z list� polece� robota
   */
  XMLInterp4Config(Configuration & rConfig);

  /*!
   * \brief Wywo�ywana jest na pocz�tku dokumentu
   */
  virtual void startDocument() override;
  /*!
   * \brief Wywo�ywana jest na ko�cu dokumentu
   */
  virtual void endDocument() override;

  /*!
   * \brief Wywo�ywana jest po napotkaniu nowego elementu XML
   */
  virtual void startElement(
    const XMLCh *
      const pURI,
        const XMLCh *
          const pLocalName,
            const XMLCh *
              const pQNname,
                const xercesc::Attributes & rAttrs
  ) override;

  /*!
   * \brief Wywo�ywana jest po doj�ciu do ko�ca elementu XML
   */
  virtual void endElement(
    const XMLCh *
      const pURI,
        const XMLCh *
          const pLocalName,
            const XMLCh *
              const pQNname
  ) override;
  /*!
   * \brief Wywo�ywana jest gdy napotkany zostanie b��d fatalny
   */
  void fatalError(const xercesc::SAXParseException & );
  /*!
   * \brief Wywo�ywana jest gdy napotkany zostanie b��d
   */
  void error(const xercesc::SAXParseException & );
  /*!
   * \brief Wywo�ywana jest gdy parser sygnalizuje ostrze�enie
   */
  void warning(const xercesc::SAXParseException & );

  /*!
   * \brief Wykonuje operacje zwi�zane z danym elementem XML
   */
  void WhenStartElement(const std::string & rElemName,
    const xercesc::Attributes & rAttrs);
  /*!
   * \brief Analizuje atrybuty i  odpwiednio je interpretuje
   */
  void ProcessLibAttrs(const xercesc::Attributes & rAttrs);
  /*!
   * \brief Analizuje atrybuty i odpwiednio je interpretuje
   */
  void ProcessCubeAttrs(const xercesc::Attributes & rAttrs);
  private:

};

bool ReadFile(const char * filename, Configuration & config);
#endif
