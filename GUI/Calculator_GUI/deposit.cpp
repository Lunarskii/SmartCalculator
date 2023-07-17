#include "deposit.h"

#include "ui_deposit.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../../Backend/calculator.h"
#ifdef __cplusplus
}
#endif

deposit::deposit(QWidget *parent) : QMainWindow(parent), ui(new Ui::deposit) {
  ui->setupUi(this);
}

deposit::~deposit() { delete ui; }

void deposit::on_depositEqual_clicked() {
  bool RESULT_CODE = 0;
  long double depositAmount = 0;
  int period = 0;
  long double percent = 0;
  long double tax = 0;
  int frequency = 0;
  int capitalization = 0;
  long double payment = 0;
  long double invoiceSum = 0;
  long double taxSum = 0;

  depositAmount = ui->depositAmount->text().toDouble(&RESULT_CODE);
  if (RESULT_CODE) period = ui->period->text().toInt(&RESULT_CODE);
  if (RESULT_CODE) percent = ui->percent->text().toDouble(&RESULT_CODE);
  if (RESULT_CODE) tax = ui->taxPercent->text().toDouble(&RESULT_CODE);
  if (RESULT_CODE) frequency = ui->frequency->text().toInt(&RESULT_CODE);
  if (RESULT_CODE) {
    if (ui->capitalization->isChecked()) {
      capitalization = 1;
    }
    DepositCalculator(depositAmount, period, percent, tax, frequency,
                      capitalization, &payment, &invoiceSum, &taxSum);
    ui->payment->setText(QString::number(payment, 'g', 10));
    ui->invoiceSum->setText(QString::number(invoiceSum, 'g', 10));
    ui->tax->setText(QString::number(taxSum, 'g', 10));
  }
}
