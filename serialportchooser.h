// Copyright 2017 Eric Smith

#ifndef SERIALPORTCHOOSER_H
#define SERIALPORTCHOOSER_H

#include <QObject>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QDialogButtonBox>

class SerialPortChooser: public QDialog
{
  Q_OBJECT

public:
  SerialPortChooser(QWidget *parent = 0, Qt::WindowFlags f = 0);

  QString get_selection();

private:
  QVBoxLayout *layout;
  QLabel *label;
  QListWidget *list;
  QDialogButtonBox *buttonBox;
  QString selection;

private slots:
  void selectionChanged();
};

#endif // SERIALPORTCHOOSER_H
