/****************************************************************************
**
** Copyright (C) 2018 AWSoft.
** Contact: https://www.
**
** Это файл является частью программы RiskF - Программы по проведению
** расчетов величины индивидуального пожарного риска.
**
** Программа использует кроссплатформенный фреймворк для разработки ПО Qt
** под лицензией GNU LGPL v3.0 динамически подключая ее
** https://www.qt.io
**
** Лицензия на использовние исходных текстов и программы RiskF
** находится в файле licenses.txt
**
****************************************************************************/

#ifndef RU_MDIWINDOW_H
#define RU_MDIWINDOW_H

#include <QMdiSubWindow>

class RU_MDIWindow : public QMdiSubWindow
{
public:
    RU_MDIWindow(QWidget *parent);
};

#endif // RU_MDIWINDOW_H
