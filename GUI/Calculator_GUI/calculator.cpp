#include "calculator.h"

#include "./ui_calculator.h"
#include "qcustomplot.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../../Backend/calculator.h"
#ifdef __cplusplus
}
#endif

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);
  setlocale(LC_NUMERIC, "C");
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(print()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_power, SIGNAL(clicked()), this, SLOT(print()));

  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_lbracket, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_rbracket, SIGNAL(clicked()), this, SLOT(print()));

  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(print()));

  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(print()));

  connect(ui->pushButton_undo, SIGNAL(clicked()), this, SLOT(clearWindow()));

  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(result()));
}

Calculator::~Calculator() { delete ui; }

void Calculator::keyPressEvent(QKeyEvent *calc_key) {
  if (calc_key->key() == Qt::Key_Enter) {
    result();
  }
}

void Calculator::result() {
  char string[1024] = {0};
  char output[1024] = {0};
  bool RESULT_CODE = 0;
  QByteArray input = ui->expressionWindow->text().toLocal8Bit();
  double x = ui->xValue->text().toDouble(&RESULT_CODE);

  if (RESULT_CODE) {
    memcpy(string, input, ui->expressionWindow->text().length() + 1);
    SmartCalculator(string, x, output);
    ui->expressionWindow->setText(QString::fromLocal8Bit(output));
  } else {
    ui->expressionWindow->setText("INVALID X VALUE");
  }
}

void Calculator::clearWindow() { ui->expressionWindow->setText("  0"); }

void Calculator::print() {
  if (ui->expressionWindow->text() == "  0") {
    ui->expressionWindow->setText("");
  }
  QPushButton *button = (QPushButton *)sender();
  QString symbol = button->text();
  ui->expressionWindow->setText(ui->expressionWindow->text() += symbol);
}

void Calculator::on_actionCreditCalculator_triggered() {
  creditWindow = new credit(this);
  creditWindow->show();
}

void Calculator::on_actionDepositCalculator_triggered() {
  depositWindow = new deposit(this);
  depositWindow->show();
}

void Calculator::on_pushButton_PLOT_clicked() {
  bool RESULT_CODE = 0;
  int maxX = 0;
  int minX = 0;
  int maxY = 0;
  int minY = 0;
  double xValue = ui->xValue->text().toDouble(&RESULT_CODE);

  if (RESULT_CODE) maxX = ui->maxX->text().toInt(&RESULT_CODE);
  if (RESULT_CODE) maxY = ui->maxY->text().toInt(&RESULT_CODE);
  if (RESULT_CODE) minX = ui->minX->text().toInt(&RESULT_CODE);
  if (RESULT_CODE) minY = ui->minY->text().toInt(&RESULT_CODE);
  if (RESULT_CODE) {
    int rangeX = maxX - minX;
    char string[1024] = {0};
    char *result = (char *)calloc(1024, sizeof(char));
    QByteArray input = ui->expressionWindow->text().toLocal8Bit();
    QVector<double> x(1024), y(1024);
    QPen bluePen;

    memcpy(string, input, ui->expressionWindow->text().length() + 1);
    for (int i = 0; i < 1024; ++i) {
      memset(result, '\0', 1024);
      x[i] = minX + rangeX * (i / 1024.0);
      SmartCalculator(string, x[i], result);

      if (!strcmp(result, "INF"))
        y[i] = INFINITY;
      else if (!strcmp(result, "NAN"))
        y[i] = NAN;
      else if (strcmp(result, "ERROR"))
        y[i] = strtod(result, NULL);
    }

    ui->customPlot->addGraph();
    bluePen.setColor(QColor(30, 40, 255, 150));
    bluePen.setStyle(Qt::SolidLine);
    bluePen.setWidthF(5);
    ui->customPlot->graph(0)->setPen(bluePen);
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(minX, maxX);
    ui->customPlot->yAxis->setRange(minY, maxY);
    ui->customPlot->replot();
    free(result);
  }
}
