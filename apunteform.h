#ifndef APUNTEFORM_H
#define APUNTEFORM_H

#include <QWidget>
#include <QDebug>
#include <QInputDialog>

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

    void setAsignaturas(QList<Asignatura *> &newAsignaturas);
    void cargarAsignaturas();
private slots:
    void on_btnAgregarAsignatura_released();

    void on_btnRefAsig_clicked();

private:
    Ui::ApunteForm *ui;
    QList<Asignatura*> *m_asignaturas;
};

#endif // APUNTEFORM_H
