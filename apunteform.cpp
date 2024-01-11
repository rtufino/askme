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

void ApunteForm::setAsignaturas(QList<Asignatura *> &asignaturas)
{
    m_asignaturas = &asignaturas;
}

void ApunteForm::cargarAsignaturas()
{
    ui->cmbAsignaturas->clear();
    foreach(Asignatura *a, *m_asignaturas){
        ui->cmbAsignaturas->addItem(a->nombre());
    }
}

void ApunteForm::on_btnAgregarAsignatura_released()
{
    bool ok;
    QString nombre = QInputDialog::getText(this,"Nueva asignatura","Nombre",QLineEdit::Normal,"",&ok);

    if (ok){
        m_asignaturas->append(new Asignatura(nombre));
        cargarAsignaturas();
    }
}

void ApunteForm::on_btnRefAsig_clicked()
{
    cargarAsignaturas();
}

