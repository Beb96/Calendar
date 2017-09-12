#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>
#include <thread> // libreria per l'esecuzione dei thread
#include <stdexcept> // libreria per la cattura di alcune eccezioni
#include <iostream> // libreria per stampare il messaggio di errore catturato dalle eccezioni

#include "ui_mainwindow.h"
#include "timer.h" // classe per la gestione del tempo
#include "gregoriancalendar.h" // Classe per la gestione del calendario gregoriano
#include "calendarexception.h" // Classe per la cattura di alcuni tipi di eccezioni



class MainWindow : public QMainWindow, private Ui::MainWindowDLG
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); //distruttore della classe MainWindow

    void ViewTime(); //Metodo per la visualizzazione del tempo
    void ViewDay(); //Metodo per la visualizzazione dei giorni nel tableWidget
    void ClearView(); //Metodo per la pulizia del tableWidget
    void ButtonEnable(); //Metodo per abilitare o disabilitare i bottoni dell'incremento dell'anno iniziale e
                        // decremento dell'anno finale

public slots:
    void IncreaseFirstYear(); // Metodo per incrementare l'anno iniziale
    void DecrementFirstYear(); //Metodo per decrementare l'anno iniziale
    void IncreaseLastYear(); // Metodo per incrementare l'anno finale
    void DecrementLastYear(); //Metodo per decrementare l'anno finale
    void ChangeYear(); //Metodo per la selezione dell'anno dalla lista nella comboBox
    void ChangeMonth(); //Metodo per la selezione del mese dalla lista nella comboBox

private:
    GregorianCalendar* gc;
    Timer * time;
    std::thread tempo; // variabile per il lancio del thread riguardante la visualizzazione dell'ora e dei minuti
};

#endif // MAINWINDOW_H
