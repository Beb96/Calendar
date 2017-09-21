#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Inizializzazione del puntatore alla classe GregorianCalendar
    try {
        gc = new GregorianCalendar();
        if (gc == nullptr) {
            throw CalendarException("Errore! Il puntatore non è stato inizializato ");
        }
    }
    catch (CalendarException& err) {
        err.print_error();
    }

    //Inizializzazione del puntatore alla classe Timer
    try {
        time = new Timer();
        if (time == nullptr) {
            throw CalendarException("Errore! Il puntatore non è stato inizializzato ");
        }
    }
    catch (CalendarException& err) {
        err.print_error();
    }

    //Mostra a display l'ora
    ViewMinute(time->getMinute());
    // Mostra a display i minuti
    ViewHour(time->getHour());

    //Inizializzazione del thread
    time_thread = new ThreadTime(this);

    // Connesione per l'invocazione dei metodi quando viene emesso il segnale dal thread
    connect(time_thread, SIGNAL(MinuteChanged(int)), this, SLOT(ViewMinute(int)));
    connect(time_thread, SIGNAL(HourChanged(int)), this, SLOT(ViewHour(int)));

    // Inizio esecuzione del thread
    time_thread->start();

    // Crea la lista dei mesi sulla comboBox
    ui->comboBox_Month->addItems(gc->getListMonth());

    //Imposta come mese iniziale all'apertura del programma il mese attuale
    ui->comboBox_Month->setCurrentText(gc->getCurrentMonth());

    // Crea la lista degli anni sulla comboBox
    ui->comboBox_Year->addItems(gc->getListYear());

    //Imposta come anno iniziale all'apertura del programma l'anno attuale
    ui->comboBox_Year->setCurrentText(QString::number(gc->getCurrentYear()));

    //Mostra a display l'anno più piccola della lista
    ui->lcdNumber_firstYear->display(gc->getFirstYear());
    //Mostra a display l'anno più grande della lista
    ui->lcdNumber_LastYear->display(gc->getLastYear());

    // Costruzione della tabella per la visualizzazione dei giorni
    ui->tableWidget_Day->setRowCount(6);
    ui->tableWidget_Day->verticalHeader()->setVisible(false);
    ui->tableWidget_Day->setColumnCount(7);
    ui->tableWidget_Day->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList days_week;
    days_week << "Lunedì" << "Martedì" << "Mercoledì" << "Giovedì" << "Venerdì" << "Sabato" << "Domenica";
    ui->tableWidget_Day->setHorizontalHeaderLabels(days_week);

    // Visualizzazione dei giorni del mese e anno attuale
    ViewDay();

    //Connessione dei vari QObject ai relativi metodi
    connect(ui->comboBox_Month, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeMonth()));
    connect(ui->comboBox_Year, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeYear()));
    connect(ui->pushButton_IncreaseFirstYear, SIGNAL(clicked()), this, SLOT(IncreaseFirstYear()));
    connect(ui->pushButton_DecrementFirstYear, SIGNAL(clicked()), this, SLOT(DecrementFirstYear()));
    connect(ui->pushButton_IncreaseLastYear, SIGNAL(clicked()), this, SLOT(IncreaseLastYear()));
    connect(ui->pushButton_DecrementLastYear, SIGNAL(clicked()), this, SLOT(DecrementLastYear()));
    connect(ui->pushButton_Close, SIGNAL(clicked()), this, SLOT(CloseProgram()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gc;
    delete time;
    delete time_thread;
}

// Metodo per la visualizzazione dei giorni sul tableWidget
void MainWindow::ViewDay() {

    ClearView();

    int nday = gc->getDay();

    int day_week = gc->getDayWeek(ui->comboBox_Month->currentIndex(), gc->getCurrentYear(), ui->comboBox_Year->currentIndex());
    int day = 1;
    int maxday_week = 7;
    for (int i = 0; i < ui->tableWidget_Day->rowCount(); i++) {
        for (int j = day_week; j < maxday_week; j++) {
            if (day <= nday) {
                ui->tableWidget_Day->setItem(i, j, new QTableWidgetItem(QString::number(day)));
                day ++;
            }
            else {
                break;
            }
        }
        if (day_week != 0)
            day_week = 0;
    }
}

// Metodo per cancellare gli elementi dalla TableWidget
void MainWindow::ClearView() {
    ui->tableWidget_Day->clearContents();
}

/* Metodo che permette di abilitare o disabilitare i bottoni per l'incremento dell'anno iniziale e per il
decremento dell'anno finale. Funziona che:
   - I bottoni vengono disbilitati quando l'anno iniziale coincide con l'anno finale
   - I bottoni vengono abilitati quando l'anno iniziale non coincide con l'anno finale
*/
void MainWindow::ButtonEnable() {
    if (gc->getFirstYear() == gc->getLastYear()) {
       ui->pushButton_IncreaseFirstYear->setEnabled(false);
       ui->pushButton_DecrementLastYear->setEnabled(false);
    }
    else {
        ui->pushButton_IncreaseFirstYear->setEnabled(true);
        ui->pushButton_DecrementLastYear->setEnabled(true);
    }
    if (gc->getFirstYear() == gc->getLastYear()) {
       ui->pushButton_IncreaseFirstYear->setEnabled(false);
       ui->pushButton_DecrementLastYear->setEnabled(false);
    }
    else {
        ui->pushButton_IncreaseFirstYear->setEnabled(true);
        ui->pushButton_DecrementLastYear->setEnabled(true);
    }
}

/* Metodo per incrementare l'anno di partenza della lista degli anni, si effettua la rimozione del
 * primo elemento della lista della comboBox e il primo elemento della lista degli anni presente nella classe
 * GregorianCalendar.
 * Si effettua la chiamata della visualizzazione dei giorni a causa della variazione degli indici
*/
void MainWindow::IncreaseFirstYear() {
    ui->comboBox_Year->removeItem(0);
    gc->setFirstYear(1);
    ui->lcdNumber_firstYear->display(gc->getFirstYear());
    ViewDay();
    ButtonEnable();
}

/* Metodo per decrementare l'anno di partenza della lista, dunque si effettua un' aggiunta dell'elemento in testa
 * alla lista sia della comboBox che a quella della classe GregorianCalendar.
 * Si effettua di nuovo la chiamata della visualizzazione dei giorni a causa della variazione degli indici
 */
void MainWindow::DecrementFirstYear() {
    gc->setFirstYear(-1);
    gc->AddElementHeadListYear();
    ui->comboBox_Year->insertItem(0,QString::number(gc->getFirstYear()));
    ui->lcdNumber_firstYear->display(gc->getFirstYear());
    ViewDay();
    ButtonEnable();
}
/* Metodo per l'incremento dell'anno finale della lista, dunque si effettua un' aggiunta dell'elemento in coda
 * alla lista sia della comboBox che a quella della classe GregorianCalendar.
 * Si effettua di nuovo la chiamata della visualizzazione dei giorni a causa della variazione degli indici
 */
void MainWindow::IncreaseLastYear() {
    gc->setLastYear(1);
    gc->AddElementTailListYear();
    ui->comboBox_Year->addItem(QString::number(gc->getYear(gc->getSizeListYear() - 1)));
    ui->lcdNumber_LastYear->display(gc->getLastYear());
    ui->comboBox_Year->setCurrentText(QString::number(gc->getCurrentYear()));
    ViewDay();
    ButtonEnable();
}

/* Metodo per il decremento dell'anno finale della lista, dunque si effettua la rimozione dell'elemento dalla
 * coda della lista sia della comboBox che dalla lista della classe GregorianCalendar.
 * Si effettua di nuovo la chiamata della visualizzazione dei giorni a causa della variazione degli indici
 */
void MainWindow::DecrementLastYear() {
    int index = ui->comboBox_Year->count() - 1;
    ui->comboBox_Year->removeItem(index);
    gc->setLastYear(-1);
    ui->lcdNumber_LastYear->display(gc->getLastYear());
    ViewDay();
    ButtonEnable();
}

/* Metodo che permette di selezionare l'anno dalla lista della comboBox e visualizzare la lista dei giorni
 * dell'anno e del mese selzionato.
 */
void MainWindow::ChangeYear() {
    try {
        gc->setCurrentYear(ui->comboBox_Year->currentText().split(" ")[0].toInt());
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Errore, selezionato anno fuori dalla lista " << std::endl;
    }

    ViewDay();
}

/* Metodo che permette di selezionare il mese dalla lista della comboBox e visualizzare la lista dei giorni
 * dell'anno e del mese selzionato.
 */
void MainWindow::ChangeMonth() {
    try {
        gc->setCurrentMonth(ui->comboBox_Month->currentText());
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Errore, selezionato mese fuori dalla lista " << std::endl;
    }

    ViewDay();
}

// Metodo per la visualizzazione su display dei minuti
void MainWindow::ViewMinute(int minute) {
    ui->lcdNumber_Minutes->display(minute);
}

// Metodo per la visualizzazione su display dell'ora
void MainWindow::ViewHour(int hour) {
    ui->lcdNumber_Hour->display(hour);
}

/* Metodo per la chiusura del programma
 * Imposto il valore booleano a true in modo che il metodo per lo scorrere del tempo venga bloccato
 * Aspetto 3 secondi per la chiusura del programma siccome occorre 1 secondo affinchè il thread si blocchi
 */
void MainWindow::CloseProgram() {
    time_thread->stop = true;
    time->Wait(3);
    close();
}
