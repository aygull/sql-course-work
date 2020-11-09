/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTableWidget *tableWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *change_Button;
    QSpacerItem *horizontalSpacer;
    QPushButton *close_Button;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(480, 394);
        tableWidget = new QTableWidget(Dialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(20, 20, 441, 261));
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::CustomDashLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(7);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(219);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(37);
        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 300, 441, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        change_Button = new QPushButton(horizontalLayoutWidget);
        change_Button->setObjectName(QStringLiteral("change_Button"));

        horizontalLayout->addWidget(change_Button);

        horizontalSpacer = new QSpacerItem(78, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close_Button = new QPushButton(horizontalLayoutWidget);
        close_Button->setObjectName(QStringLiteral("close_Button"));

        horizontalLayout->addWidget(close_Button);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\265", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = tableWidget->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "\320\230\320\274\321\217:", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->item(1, 0);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202:", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(2, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("Dialog", "\320\236\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(3, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("Dialog", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214:", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(4, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("Dialog", "\320\236\321\206\320\265\320\275\320\272\320\260:", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(5, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("Dialog", "\320\244\321\203\320\275\320\272\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\271 \320\276\320\277\321\213\321\202:", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(6, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("Dialog", "\320\236\320\277\321\213\321\202 \321\200\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\260:", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

        change_Button->setText(QApplication::translate("Dialog", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        close_Button->setText(QApplication::translate("Dialog", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
