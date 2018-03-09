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

#ifndef FL_SETTINGS_H
#define FL_SETTINGS_H

#include <QSettings>
#include <QString>

/*******************************
 * FL_Settings - класс поддержки сохранения настроек приложения
 *
 *******************************/
class FL_Settings : public QSettings
{
public:
    FL_Settings();

    /**
     * @brief instance
     * @return - возвращает единственный экземпляр объекта
     */
    static FL_Settings* instance();

private:
    static FL_Settings uniqInstance;


};

#endif // FL_SETTINGS_H
