#ifndef CREDIT_H
#define CREDIT_H

#include <QMainWindow>

namespace Ui {
class credit;
}

class credit : public QMainWindow {
  Q_OBJECT

 public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

 private slots:
  void on_creditEqual_clicked();

 private:
  Ui::credit *ui;
};

#endif  // CREDIT_H
