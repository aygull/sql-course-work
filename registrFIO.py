# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'registrFIO.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets
from Database import Database


class Ui_registrFIO(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi()
        self.db = None
        self.id = None
        self.registr = None
        self.name=None
        self.enterButton.clicked.connect(self.check_name)

    def setupUi(self):
        # self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.setObjectName("registrFIO")
        self.verticalLayout = QtWidgets.QVBoxLayout(self)
        self.verticalLayout.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout.setSpacing(6)
        self.verticalLayout.setObjectName("verticalLayout")
        self.FIO = QtWidgets.QLabel(self)
        font = QtGui.QFont()
        font.setPointSize(10)
        self.FIO.setFont(font)
        self.FIO.setObjectName("FIO")
        self.verticalLayout.addWidget(self.FIO)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.FIOEdit = QtWidgets.QLineEdit(self)
        self.FIOEdit.setObjectName("FIOEdit")
        self.horizontalLayout.addWidget(self.FIOEdit)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setSpacing(6)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.enterButton = QtWidgets.QPushButton(self)
        self.enterButton.setObjectName("enterButton")
        self.horizontalLayout_2.addWidget(self.enterButton)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem1)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        # MainWindow.setCentralWidget(self)


        self.retranslateUi(self)
        QtCore.QMetaObject.connectSlotsByName(self)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Как вас зовут?"))
        self.FIO.setText(_translate("MainWindow", "Введите своё ФИО"))
        self.enterButton.setText(_translate("MainWindow", "Дальше"))

    def getId(self):
        print(self.id)
        return self.id

    def check_name(self):
       self.id = self.db.checkFIO(self.FIOEdit.text())
       self.registr = self.db.check_registr(self.FIOEdit.text())
       if self.id is not None:
           self.name = self.FIOEdit.text()
       self.accept()

    def getName(self):
        return self.name