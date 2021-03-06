// Copyright (c) 2011-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "transactiondescdialog.h"
#include "ui_transactiondescdialog.h"

#include "transactiontablemodel.h"
#include "styleSheet.h"

#include <QModelIndex>
#include <QPushButton>

TransactionDescDialog::TransactionDescDialog(const QModelIndex &idx, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDescDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Close)->setText(tr("Close"));
    ui->detailText->setStyleSheet("background-color: #FFFFFF; border: none;");
    ui->buttonsContainerWhite->setStyleSheet("background-color: #FFFFFF;");
    ui->buttonBox->button(QDialogButtonBox::Close)->setStyleSheet("background-color: #4752E8;");
    // Set stylesheet
    SetObjectStyleSheet(this, StyleSheetNames::ScrollBarDark);

    setWindowTitle(tr("Details for %1").arg(idx.data(TransactionTableModel::TxIDRole).toString()));
    QString desc = idx.data(TransactionTableModel::LongDescriptionRole).toString();
    ui->detailText->setHtml(desc);
}

TransactionDescDialog::~TransactionDescDialog()
{
    delete ui;
}
