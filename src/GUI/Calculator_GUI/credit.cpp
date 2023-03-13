#include "credit.h"

#include "ui_credit.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../../Backend/calculator.h"
#ifdef __cplusplus
}
#endif

credit::credit(QWidget *parent) : QMainWindow(parent), ui(new Ui::credit) {
  ui->setupUi(this);
}

credit::~credit() { delete ui; }

void credit::on_creditEqual_clicked() {
  bool RESULT_CODE = 0;
  long double creditAmount = ui->creditAmount->text().toDouble(&RESULT_CODE);
  int creditPeriod = 0;
  long double percentRate = 0;
  int type = 0;
  long double monthlyPayment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  long double min = 0;
  long double max = 0;

  if (RESULT_CODE) creditPeriod = ui->creditPeriod->text().toInt(&RESULT_CODE);
  if (RESULT_CODE) percentRate = ui->percentRate->text().toDouble(&RESULT_CODE);

  if (ui->type_annuity->isChecked()) {
    type = ANNUITY;
  } else if (ui->type_diff->isChecked()) {
    type = DIFFERENTIATED;
  } else {
    RESULT_CODE = false;
  }

  if (RESULT_CODE && percentRate >= 0.01 && percentRate <= 999) {
    CreditCalculator(creditAmount, creditPeriod, percentRate, type,
                     &monthlyPayment, &overpayment, &totalPayment, &max, &min);
    if (type == DIFFERENTIATED) {
      ui->monthlyPayment->setText(QString::number(min, 'g', 10));
      ui->monthlyPayment->setText(ui->monthlyPayment->text() += " - ");
      ui->monthlyPayment->setText(ui->monthlyPayment->text() +=
                                  QString::number(max, 'g', 10));
    } else {
      ui->monthlyPayment->setText(QString::number(monthlyPayment, 'g', 10));
    }
    ui->overpayment->setText(QString::number(overpayment, 'g', 10));
    ui->totalPayment->setText(QString::number(totalPayment, 'g', 10));
  }
}
