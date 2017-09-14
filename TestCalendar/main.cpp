#include <QtTest/QtTest> // libreria per la gestione dello unit testing
#include "calendarapplicationtest.h" // classe contenente i vari test del progetto

/* E' una MACRO per l'implementazione di una funzione main() che non istanzia gli oggetti di una QApplication
 * ma solo quelli della classe Test, quindi effettua il test solo della parte logica del progetto
 */
QTEST_APPLESS_MAIN ( CalendarApplicationTest )
