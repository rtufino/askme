#include "apunteform.h"
#include "ui_apunteform.h"

ApunteForm::ApunteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApunteForm)
{
    ui->setupUi(this);
}

ApunteForm::~ApunteForm()
{
    delete ui;
}

const QList<Asignatura *> &ApunteForm::asignaturas() const
{
    return m_asignaturas;
}

void ApunteForm::setAsignaturas(const QList<Asignatura *> &newAsignaturas)
{
    m_asignaturas = newAsignaturas;
}

void ApunteForm::cargarAsignaturas()
{
    foreach(Asignatura *a, m_asignaturas){
        qDebug() << a->nombre();
        ui->cmbAsignaturas->addItem(a->nombre());
    }
}
