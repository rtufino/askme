#ifndef LISTAFORM_H
#define LISTAFORM_H

#include <QWidget>

#include "asignatura.h"

namespace Ui {
class ListaForm;
}

class ListaForm : public QWidget
{
    Q_OBJECT

public:
    explicit ListaForm(QWidget *parent = nullptr);
    ~ListaForm();

    void setAsignaturas(QList<Asignatura *> &newAsignaturas);
    void cargarAsignaturas();

private slots:
    void on_cmbAsignaturas_currentIndexChanged(int index);

private:
    Ui::ListaForm *ui;
    QList<Asignatura*> *m_asignaturas;
    enum Columna
    {
        TEMA, TERMINO, CONCEPTO
    };
};

#endif // LISTAFORM_H
