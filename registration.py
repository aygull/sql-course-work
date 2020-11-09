# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'registration.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtWidgets


class Ui_registration(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi()
        self.db = None
        self.name = None
        self.OK_butt.clicked.connect(self.addLog)

    def setupUi(self):
        self.setObjectName("registration")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self)
        self.verticalLayout_2.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout_2.setSpacing(6)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setSpacing(6)
        self.verticalLayout.setObjectName("verticalLayout")
        self.login_label = QtWidgets.QLabel(self)
        self.login_label.setObjectName("login_label")
        self.verticalLayout.addWidget(self.login_label)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.login_lineEdit = QtWidgets.QLineEdit(self)
        self.login_lineEdit.setObjectName("login_lineEdit")
        self.horizontalLayout.addWidget(self.login_lineEdit)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.passw_label = QtWidgets.QLabel(self)
        self.passw_label.setObjectName("passw_label")
        self.verticalLayout.addWidget(self.passw_label)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setSpacing(6)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.passw_lineEdit = QtWidgets.QLineEdit(self)
        self.passw_lineEdit.setObjectName("passw_lineEdit")
        self.passw_lineEdit.setEchoMode(QtWidgets.QLineEdit.Password)
        self.horizontalLayout_2.addWidget(self.passw_lineEdit)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem1)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setSpacing(6)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.OK_butt = QtWidgets.QPushButton(self)
        self.OK_butt.setObjectName("OK_butt")
        self.horizontalLayout_3.addWidget(self.OK_butt)
        spacerItem2 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem2)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.verticalLayout_2.addLayout(self.verticalLayout)

        self.retranslateUi(self)
        QtCore.QMetaObject.connectSlotsByName(self)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Регистрация"))
        self.login_label.setText(_translate("MainWindow", "Введите логин"))
        self.passw_label.setText(_translate("MainWindow", "Введите пароль"))
        self.OK_butt.setText(_translate("MainWindow", "Зарегистрироваться в системе"))

    def addLog(self):
        self.db.add_log(self.name, self.login_lineEdit.text(), self.passw_lineEdit.text())
        self.close()
