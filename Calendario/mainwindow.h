#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <stdexcept> // libreria per la cattura di alcune eccezioni
#include <iostream> // libreria per visualizzare il messaggio di errore catturato dalle eccezioni


#include "timer.h" // classe per la gestione del tempo
#include "gregoriancalendar.h" // Classe per la gestione del calendario gregoriano
#include "calendarexception.h" // Classe per la cattura di alcuni tipi di eccezioni
#include "threadtime.h" // Classe thread per lo scorrere del tempo

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ViewDay(); //Metodo per la visualizzazione dei giorni nel tableWidget
    void ClearView(); //Metodo per la pulizia del tableWidget
    void ButtonEnable(); // Metodo per abilitare o disabilitare i bottoni dell'incremento dell'anno iniziale e
                         // decremento dell'anno finale

public slots:
    void IncreaseFirstYear(); // Metodo per incrementare l'anno iniziale
    void DecrementFirstYear(); //Metodo per decrementare l'anno iniziale
    void IncreaseLastYear(); // Metodo per incrementare l'anno finale
    void DecrementLastYear(); //Metodo per decrementare l'anno finale
    void ChangeYear(); //Metodo per la selezione dell'anno dalla lista nella comboBox
    void ChangeMonth(); //Metodo per la selezione del mese dalla lista nella comboBox
    void ViewMinute(int minute); // Metodo per la visualizzazione dei minuti
    void ViewHour(int hour); // Metodo per la visualizzazione dell'ora
    void CloseProgram(); // Metodo per la chiusura del programma

private:
    ThreadTime * time_thread; // puntatore alla classe ThreadTime per lo scorrere del tempo
    Ui::MainWindow *ui; // puntatore per l'invocazione dei QObject della GUI
    GregorianCalendar* gc; // puntatore per l'invocazione dei metodi della classe GregorianCalendar
    Timer * time; // puntatore per l'invocazione dei metodi della classe Timer
};

#endif // MAINWINDOW_H
