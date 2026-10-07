#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  void initialState();
  void toggleOn();
  void toggleOff();
  void toggleRepeated();

};

void TestToggleWidget::initialState(){
  ToggleWidget w;
  QVERIFY(!w.isOn());
}

void TestToggleWidget::toggleOn(){
  ToggleWidget w;
  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);

  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(w.isOn());
}

void TestToggleWidget::toggleOff(){
  ToggleWidget w;
  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);

  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(w.isOn());
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(!w.isOn());
}

void TestToggleWidget::toggleRepeated(){
  ToggleWidget w;
  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);

  for(int i = 1; i <= 6; i++){
    QTest::mouseClick(pb, Qt::LeftButton);
    QCOMPARE(w.isOn(), i % 2 == 1);
  }
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
