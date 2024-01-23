#include "listaform.h"
#include "ui_listaform.h"

ListaForm::ListaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListaForm)
{
    ui->setupUi(this);
    // Configurar la tabla
    ui->tblTemas->setColumnCount(3);
    QStringList titulo;
    titulo << "Tema" << "Termino" << "Concepto";
    ui->tblTemas->setHorizontalHeaderLabels(titulo);
}

ListaForm::~ListaForm()
{
    delete ui;
}

void ListaForm::setAsignaturas(QList<Asignatura*> &newAsignaturas)
{
    m_asignaturas = &newAsignaturas;
}

void ListaForm::cargarAsignaturas()
{
    ui->cmbAsignaturas->clear();
    foreach(Asignatura *a, *m_asignaturas){
        ui->cmbAsignaturas->addItem(a->nombre());
    }
}

void ListaForm::on_cmbAsignaturas_currentIndexChanged(int index)
{
    Asignatura *a = m_asignaturas->at(index);
    ui->tblTemas->clearContents();
    int fila = 0;
    foreach(Tema *t, a->temas()){
        QString tema = t->nombre();
        foreach(Apunte *ap, t->apuntes()){
            ui->tblTemas->insertRow(fila);
            ui->tblTemas->setItem(fila, TEMA, new QTableWidgetItem(tema));
            ui->tblTemas->setItem(fila, TERMINO, new QTableWidgetItem(ap->termino()));
            ui->tblTemas->setItem(fila, CONCEPTO, new QTableWidgetItem(ap->concepto()));
            fila++;
        }
    }
}

