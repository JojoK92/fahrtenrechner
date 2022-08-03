/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *WindowKundenInformationen;
    QAction *WindowFahrzeiten;
    QAction *WindowRechner;
    QWidget *CW_1;
    QGridLayout *gridLayout_2;
    QGroupBox *GB_1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *HL_1;
    QLabel *LabelGesDauerQuali;
    QLineEdit *GesDauerQuali;
    QLabel *LabelWochentag;
    QComboBox *ComboBoxWochentage;
    QLabel *LabelArbeitsZeitVon;
    QTimeEdit *TimeEditVon;
    QLabel *LabelArbeitsZeitBis;
    QTimeEdit *TimeEditBis;
    QTableWidget *TableArbeitszeit;
    QPushButton *PushButtonZeiterfassen;
    QPushButton *PushButtonZeitLoeschen;
    QMenuBar *menubar;
    QMenu *Menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(348, 723);
        WindowKundenInformationen = new QAction(MainWindow);
        WindowKundenInformationen->setObjectName(QString::fromUtf8("WindowKundenInformationen"));
        WindowFahrzeiten = new QAction(MainWindow);
        WindowFahrzeiten->setObjectName(QString::fromUtf8("WindowFahrzeiten"));
        WindowRechner = new QAction(MainWindow);
        WindowRechner->setObjectName(QString::fromUtf8("WindowRechner"));
        CW_1 = new QWidget(MainWindow);
        CW_1->setObjectName(QString::fromUtf8("CW_1"));
        gridLayout_2 = new QGridLayout(CW_1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        GB_1 = new QGroupBox(CW_1);
        GB_1->setObjectName(QString::fromUtf8("GB_1"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(10);
        GB_1->setFont(font);
        verticalLayout = new QVBoxLayout(GB_1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        HL_1 = new QHBoxLayout();
        HL_1->setObjectName(QString::fromUtf8("HL_1"));
        LabelGesDauerQuali = new QLabel(GB_1);
        LabelGesDauerQuali->setObjectName(QString::fromUtf8("LabelGesDauerQuali"));
        LabelGesDauerQuali->setFont(font);

        HL_1->addWidget(LabelGesDauerQuali);

        GesDauerQuali = new QLineEdit(GB_1);
        GesDauerQuali->setObjectName(QString::fromUtf8("GesDauerQuali"));
        GesDauerQuali->setFont(font);

        HL_1->addWidget(GesDauerQuali);


        verticalLayout->addLayout(HL_1);

        LabelWochentag = new QLabel(GB_1);
        LabelWochentag->setObjectName(QString::fromUtf8("LabelWochentag"));
        LabelWochentag->setFont(font);

        verticalLayout->addWidget(LabelWochentag);

        ComboBoxWochentage = new QComboBox(GB_1);
        ComboBoxWochentage->addItem(QString());
        ComboBoxWochentage->addItem(QString());
        ComboBoxWochentage->addItem(QString());
        ComboBoxWochentage->addItem(QString());
        ComboBoxWochentage->addItem(QString());
        ComboBoxWochentage->addItem(QString());
        ComboBoxWochentage->addItem(QString());
        ComboBoxWochentage->setObjectName(QString::fromUtf8("ComboBoxWochentage"));
        ComboBoxWochentage->setFont(font);

        verticalLayout->addWidget(ComboBoxWochentage);

        LabelArbeitsZeitVon = new QLabel(GB_1);
        LabelArbeitsZeitVon->setObjectName(QString::fromUtf8("LabelArbeitsZeitVon"));
        LabelArbeitsZeitVon->setFont(font);

        verticalLayout->addWidget(LabelArbeitsZeitVon);

        TimeEditVon = new QTimeEdit(GB_1);
        TimeEditVon->setObjectName(QString::fromUtf8("TimeEditVon"));
        TimeEditVon->setFont(font);
        TimeEditVon->setTime(QTime(8, 0, 0));

        verticalLayout->addWidget(TimeEditVon);

        LabelArbeitsZeitBis = new QLabel(GB_1);
        LabelArbeitsZeitBis->setObjectName(QString::fromUtf8("LabelArbeitsZeitBis"));
        LabelArbeitsZeitBis->setFont(font);

        verticalLayout->addWidget(LabelArbeitsZeitBis);

        TimeEditBis = new QTimeEdit(GB_1);
        TimeEditBis->setObjectName(QString::fromUtf8("TimeEditBis"));
        TimeEditBis->setFont(font);
        TimeEditBis->setTime(QTime(16, 0, 0));

        verticalLayout->addWidget(TimeEditBis);

        TableArbeitszeit = new QTableWidget(GB_1);
        if (TableArbeitszeit->columnCount() < 3)
            TableArbeitszeit->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableArbeitszeit->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableArbeitszeit->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableArbeitszeit->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        TableArbeitszeit->setObjectName(QString::fromUtf8("TableArbeitszeit"));
        TableArbeitszeit->setFont(font);
        TableArbeitszeit->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(TableArbeitszeit);

        PushButtonZeiterfassen = new QPushButton(GB_1);
        PushButtonZeiterfassen->setObjectName(QString::fromUtf8("PushButtonZeiterfassen"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PushButtonZeiterfassen->sizePolicy().hasHeightForWidth());
        PushButtonZeiterfassen->setSizePolicy(sizePolicy);
        PushButtonZeiterfassen->setFont(font);

        verticalLayout->addWidget(PushButtonZeiterfassen);

        PushButtonZeitLoeschen = new QPushButton(GB_1);
        PushButtonZeitLoeschen->setObjectName(QString::fromUtf8("PushButtonZeitLoeschen"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PushButtonZeitLoeschen->sizePolicy().hasHeightForWidth());
        PushButtonZeitLoeschen->setSizePolicy(sizePolicy1);
        PushButtonZeitLoeschen->setFont(font);

        verticalLayout->addWidget(PushButtonZeitLoeschen);


        gridLayout_2->addWidget(GB_1, 0, 0, 1, 1);

        MainWindow->setCentralWidget(CW_1);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 348, 21));
        Menu = new QMenu(menubar);
        Menu->setObjectName(QString::fromUtf8("Menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(Menu->menuAction());
        Menu->addAction(WindowKundenInformationen);
        Menu->addAction(WindowFahrzeiten);
        Menu->addAction(WindowRechner);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        WindowKundenInformationen->setText(QCoreApplication::translate("MainWindow", "Kundeninformationen", nullptr));
        WindowFahrzeiten->setText(QCoreApplication::translate("MainWindow", "Fahrzeiten", nullptr));
        WindowRechner->setText(QCoreApplication::translate("MainWindow", "Rechner", nullptr));
        GB_1->setTitle(QCoreApplication::translate("MainWindow", "Kundeninformationen", nullptr));
        LabelGesDauerQuali->setText(QCoreApplication::translate("MainWindow", "Gesamtdauer Qualifizierung (Stunden):", nullptr));
        GesDauerQuali->setText(QCoreApplication::translate("MainWindow", "420", nullptr));
        LabelWochentag->setText(QCoreApplication::translate("MainWindow", "Wochentag:", nullptr));
        ComboBoxWochentage->setItemText(0, QCoreApplication::translate("MainWindow", "Montag", nullptr));
        ComboBoxWochentage->setItemText(1, QCoreApplication::translate("MainWindow", "Dienstag", nullptr));
        ComboBoxWochentage->setItemText(2, QCoreApplication::translate("MainWindow", "Mittwoch", nullptr));
        ComboBoxWochentage->setItemText(3, QCoreApplication::translate("MainWindow", "Donnerstag", nullptr));
        ComboBoxWochentage->setItemText(4, QCoreApplication::translate("MainWindow", "Freitag", nullptr));
        ComboBoxWochentage->setItemText(5, QCoreApplication::translate("MainWindow", "Samstag", nullptr));
        ComboBoxWochentage->setItemText(6, QCoreApplication::translate("MainWindow", "Sonntag", nullptr));

        LabelArbeitsZeitVon->setText(QCoreApplication::translate("MainWindow", "Arbeitszeit von:", nullptr));
        LabelArbeitsZeitBis->setText(QCoreApplication::translate("MainWindow", "Arbeitszeit bis:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableArbeitszeit->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Tag", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableArbeitszeit->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Arbeitszeit von", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableArbeitszeit->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Arbeitszeit bis", nullptr));
        PushButtonZeiterfassen->setText(QCoreApplication::translate("MainWindow", "Arbeitszeit erfassen", nullptr));
        PushButtonZeitLoeschen->setText(QCoreApplication::translate("MainWindow", "Arbeitszeit l\303\266schen", nullptr));
        Menu->setTitle(QCoreApplication::translate("MainWindow", "Men\303\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
