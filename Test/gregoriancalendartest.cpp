#include <QtWidgets>
#include <QtTest/QtTest>


class GregorianCalendarTest : public QObject
{
    Q_OBJECT

private slots:
    void testGUI();
};

void GregorianCalendarTest::testGUI() {
    QComboBox year;

    QTest::mouseClick(&year, Qt::LeftButton, Qt::NoModifier, QPoint(10, 80), 1000);

    QCOMPARE(year.currentText(), QString("2017"));
}

QTEST_MAIN(GregorianCalendarTest)
#include "gregoriancalendartest.moc"
