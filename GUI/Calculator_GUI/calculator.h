#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QKeyEvent>
#include <QMainWindow>

#include "credit.h"
#include "deposit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
  Q_OBJECT

 public:
  Calculator(QWidget *parent = nullptr);
  ~Calculator();

 private:
  Ui::Calculator *ui;
  credit *creditWindow;
  deposit *depositWindow;

 protected:
  void keyPressEvent(QKeyEvent *calc_key) override;

 private slots:
  void print();
  void clearWindow();
  void result();
  void on_actionCreditCalculator_triggered();
  void on_pushButton_PLOT_clicked();
  void on_actionDepositCalculator_triggered();
};
#endif  // CALCULATOR_H
