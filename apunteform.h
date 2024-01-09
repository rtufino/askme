#ifndef APUNTEFORM_H
#define APUNTEFORM_H

#include <QWidget>
#include <QDebug>

#include "asignatura.h"

namespace Ui {
class ApunteForm;
}

class ApunteForm : public QWidget
{
    Q_OBJECT

public:
    explicit ApunteForm(QWidget *parent = nullptr);
    ~ApunteForm();

    const QList<Asignatura *> &asignaturas() const;
    void setAsignaturas(const QList<Asignatura *> &newAsignaturas);
    void cargarAsignaturas();
private:
    Ui::ApunteForm *ui;
    QList<Asignatura*> m_asignaturas;
};

#endif // APUNTEFORM_H
