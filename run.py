import sys
from PyQt6 import QtWidgets
from ui.mainwindow import Ui_MainWindow
from ui.Fahrzeiten import Ui_FahrzeitenWindow
from ui.rechner import Ui_RechnerWindow
from datetime import datetime

workweekday = "Arbeitstag"

app = QtWidgets.QApplication(sys.argv)


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.setWindowTitle("Fahrtkostenrechner")

        # Working Time Selector
        self.ui.PushButtonZeiterfassen.clicked.connect(self.work_day_time_save)

        # Selected Row Deleter
        self.ui.PushButtonZeitLoeschen.clicked.connect(self.delete_selected_row)

        self.ui.WindowFahrzeiten.triggered.connect(self.fahrzeiten_show)
        self.ui.WindowRechner.triggered.connect(self.rechner_show)

    def fahrzeiten_show(self):
        self.hide()
        window_fahrzeiten.show()

    def rechner_show(self):
        self.hide()
        window_rechner.show()

    def work_day_time_save(self):
        global workweekday
        workweekday = self.ui.ComboBoxWochentage.currentText()
        worktimefrom = self.ui.TimeEditVon.time().toString()
        worktimeto = self.ui.TimeEditBis.time().toString()

        # Inserting Row with correct Rownumber on Click
        row = self.ui.TableArbeitszeit.rowCount()
        self.ui.TableArbeitszeit.insertRow(row)

        self.ui.TableArbeitszeit.setItem(row, 0, QtWidgets.QTableWidgetItem(workweekday))
        self.ui.TableArbeitszeit.setItem(row, 1, QtWidgets.QTableWidgetItem(worktimefrom))
        self.ui.TableArbeitszeit.setItem(row, 2, QtWidgets.QTableWidgetItem(worktimeto))

        # Function that checks if there is a time overlap in the working schedule and removes the potential entry!
        for i in range(0, row):
            workweekday_abgl = self.ui.TableArbeitszeit.item(row, 0).text()
            worktimefrom_abgl = datetime.strptime(self.ui.TableArbeitszeit.item(row, 1).text(), "%H:%M:%S")
            worktimeto_abgl = datetime.strptime(self.ui.TableArbeitszeit.item(row, 2).text(), "%H:%M:%S")

            workweekday_tbl = self.ui.TableArbeitszeit.item(i, 0).text()
            worktimefrom_tbl = datetime.strptime(self.ui.TableArbeitszeit.item(i, 1).text(), "%H:%M:%S")
            worktimeto_tbl = datetime.strptime(self.ui.TableArbeitszeit.item(i, 2).text(), "%H:%M:%S")

            if workweekday_abgl == workweekday_tbl:
                overlap = max(0, int((min(worktimeto_abgl, worktimeto_tbl) - max(worktimefrom_abgl, worktimefrom_tbl))
                                     .total_seconds() / 60))
                if overlap > 0:
                    self.ui.TableArbeitszeit.removeRow(row)
                    print("#Error: Loop Break, due to overlap in selected lesson times!")
                    break

    def delete_selected_row(self):
        selectedrow = self.ui.TableArbeitszeit.currentRow()
        self.ui.TableArbeitszeit.removeRow(selectedrow)


class FahrzeitenWindow(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.ui = Ui_FahrzeitenWindow()
        self.ui.setupUi(self)
        self.setWindowTitle("Fahrtkostenrechner")

        self.ui.WindowKundenInformationen.triggered.connect(self.kundeninformationen_show)
        self.ui.WindowRechner.triggered.connect(self.rechner_show)

        # Driving time adder
        self.ui.PushButtonZeiterfassen.clicked.connect(self.driving_lesson_save)

        # Selected Row Deleter
        self.ui.PushButtonZeitLoeschen.clicked.connect(self.delete_selected_row)

    def kundeninformationen_show(self):
        self.hide()
        window_kundeninfo.show()

    def rechner_show(self):
        self.hide()
        window_rechner.show()

    def driving_lesson_save(self):
        weekday_dict = {0: "Montag", 1: "Dienstag", 2: "Mittwoch", 3: "Donnerstag", 4: "Freitag", 5: "Samstag",
                        6: "Sonntag"}

        lessondate = self.ui.KalenderFahrzeit.selectedDate().toString("dd.MM.yyyy")
        lessonweekday = weekday_dict[(datetime.strptime(lessondate, "%d.%m.%Y")).weekday()]

        lessontimefrom = self.ui.TimeEditVon.time().toString()
        lessontimeto = self.ui.TimeEditBis.time().toString()
        lessontimedelta = str(int((datetime.strptime(lessontimeto, "%H:%M:%S")
                                   - datetime.strptime(lessontimefrom, "%H:%M:%S")).total_seconds()/60))

        # Inserting Row with correct Rownumber on Click
        row = self.ui.TableFahrzeit.rowCount()

        self.ui.TableFahrzeit.insertRow(row)
        self.ui.TableFahrzeit.setItem(row, 0, QtWidgets.QTableWidgetItem(lessondate))
        self.ui.TableFahrzeit.setItem(row, 1, QtWidgets.QTableWidgetItem(lessonweekday))
        self.ui.TableFahrzeit.setItem(row, 2, QtWidgets.QTableWidgetItem(lessontimefrom))
        self.ui.TableFahrzeit.setItem(row, 3, QtWidgets.QTableWidgetItem(lessontimeto))
        self.ui.TableFahrzeit.setItem(row, 4, QtWidgets.QTableWidgetItem(lessontimedelta))

        # Function that checks if there is a time overlap between driving lessons and removes the potential entry!
        for i in range(0, row):
            lessondate_abgl = self.ui.TableFahrzeit.item(row, 0).text()
            lessontimefrom_abgl = datetime.strptime(self.ui.TableFahrzeit.item(row, 2).text(), "%H:%M:%S")
            lessontimeto_abgl = datetime.strptime(self.ui.TableFahrzeit.item(row, 3).text(), "%H:%M:%S")

            lessondate_tbl = self.ui.TableFahrzeit.item(i, 0).text()
            lessontimefrom_tbl = datetime.strptime(self.ui.TableFahrzeit.item(i, 2).text(), "%H:%M:%S")
            lessontimeto_tbl = datetime.strptime(self.ui.TableFahrzeit.item(i, 3).text(), "%H:%M:%S")

            if lessondate_tbl == lessondate_abgl:
                overlap = max(0, int((min(lessontimeto_tbl, lessontimeto_abgl)
                                      - max(lessontimefrom_tbl, lessontimefrom_abgl)).total_seconds() / 60))
                if overlap > 0:
                    self.ui.TableFahrzeit.removeRow(row)
                    print("#Error: Loop Break, due to overlap in selected lesson times!")
                    break

    def delete_selected_row(self):
        selectedrow = self.ui.TableFahrzeit.currentRow()
        self.ui.TableFahrzeit.removeRow(selectedrow)


class RechnerWindow(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.ui = Ui_RechnerWindow()
        self.ui.setupUi(self)
        self.setWindowTitle("Fahrtkostenrechner")

        self.ui.WindowKundenInformationen.triggered.connect(self.kundeninformationen_show)
        self.ui.WindowFahrzeiten.triggered.connect(self.fahrzeiten_show)

        self.ui.PushButtonBerechnen.clicked.connect(self.anteil_fahrzeiten_berechnen)

    def kundeninformationen_show(self):
        self.hide()
        window_kundeninfo.show()

    def fahrzeiten_show(self):
        self.hide()
        window_fahrzeiten.show()

    def anteil_fahrzeiten_berechnen(self):
        global workweekday
        totaltimequalification = int(window_kundeninfo.ui.GesDauerQuali.value()*60)
        rowsfahrzeit = window_fahrzeiten.ui.TableFahrzeit.rowCount()
        rowsarbeitszeit = window_kundeninfo.ui.TableArbeitszeit.rowCount()

        lesson_outside_worktime = 0
        list_workweekdays = []

        for i in range(0, rowsarbeitszeit):
            list_workweekdays.append(window_kundeninfo.ui.TableArbeitszeit.item(i, 0).text())

        for i in range(0, rowsfahrzeit):

            lessonweekday = window_fahrzeiten.ui.TableFahrzeit.item(i, 1).text()
            lessontimefrom = datetime.strptime(window_fahrzeiten.ui.TableFahrzeit.item(i, 2).text(), "%H:%M:%S")
            lessontimeto = datetime.strptime(window_fahrzeiten.ui.TableFahrzeit.item(i, 3).text(), "%H:%M:%S")
            lessontimedelta = int(window_fahrzeiten.ui.TableFahrzeit.item(i, 4).text())

            # Dict needed to calculate overlap if there are multiple work shifts on the same day!
            dict_overlapweekday = {}
            for j in range(0, rowsarbeitszeit):
                workweekday = window_kundeninfo.ui.TableArbeitszeit.item(j, 0).text()
                worktimefrom = datetime.strptime(window_kundeninfo.ui.TableArbeitszeit.item(j, 1).text(), "%H:%M:%S")
                worktimeto = datetime.strptime(window_kundeninfo.ui.TableArbeitszeit.item(j, 2).text(), "%H:%M:%S")
                if lessonweekday == workweekday:
                    if workweekday not in dict_overlapweekday.keys():
                        dict_overlapweekday[workweekday] = max(0, int((min(lessontimeto, worktimeto)
                                                                       - max(lessontimefrom, worktimefrom))
                                                                      .total_seconds() / 60))
                    else:
                        dict_overlapweekday[workweekday] = dict_overlapweekday[workweekday] \
                                                           + max(0, int((min(lessontimeto, worktimeto)
                                                                         - max(lessontimefrom, worktimefrom))
                                                                        .total_seconds() / 60))
            if lessonweekday in dict_overlapweekday.keys():
                if dict_overlapweekday[lessonweekday] > 0:
                    lessontimedelta -= dict_overlapweekday[lessonweekday]
                    lesson_outside_worktime += lessontimedelta
            else:
                lesson_outside_worktime += lessontimedelta

        if totaltimequalification > 0 and window_fahrzeiten.ui.TableFahrzeit.rowCount() > 0 and \
                window_kundeninfo.ui.TableArbeitszeit.rowCount() > 0:

            sharelessonoverlap = lesson_outside_worktime/totaltimequalification*100
            self.ui.EndergebnisProzent.setText(str(round(sharelessonoverlap, 2)) + "%")
            self.ui.GesDauerQualStunden.setText(str(totaltimequalification/60) + " Stunden")
            self.ui.FahrzeitStunden.setText(str(round(lesson_outside_worktime/60, 2)) + " Stunden")
        else:
            self.ui.EndergebnisProzent.setText(str("Parameter Eintragen!"))
            self.ui.GesDauerQualStunden.setText(str("Parameter Eintragen!"))
            self.ui.FahrzeitStunden.setText(str("Parameter Eintragen!"))


window_kundeninfo = MainWindow()
window_fahrzeiten = FahrzeitenWindow()
window_rechner = RechnerWindow()


window_kundeninfo.show()
sys.exit(app.exec())
