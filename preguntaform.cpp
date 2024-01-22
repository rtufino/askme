#include "preguntaform.h"
#include "ui_preguntaform.h"

PreguntaForm::PreguntaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreguntaForm)
{
    ui->setupUi(this);
}

PreguntaForm::~PreguntaForm()
{
    delete ui;
}

void PreguntaForm::setCuestionario(Cuestionario *newCuestionario)
{
    m_cuestionario = newCuestionario;
    cargarDatos();
}

void PreguntaForm::cargarDatos()
{
    ui->lblTema->setText(m_cuestionario->nombreTema());
    ui->cmbTerminos->addItems(m_cuestionario->terminos());
    obtenerPregunta();
}

void PreguntaForm::siguiente()
{
    QString termino = ui->cmbTerminos->currentText();
    m_pregunta->responder(termino);
    obtenerPregunta();
}

void PreguntaForm::obtenerPregunta()
{
    if (m_cuestionario->hayMasPreguntas()){
        m_pregunta = m_cuestionario->siguiente();
        ui->txtConcepto->setText(m_pregunta->apunte()->concepto());
        int actual = m_cuestionario->mostradas();
        int total = m_cuestionario->totalPreguntas();
        ui->lblContador->setText(QString::number(actual) + " / " + QString::number(total));
        ui->cmbTerminos->setCurrentIndex(0);
    }else{
        finalizar();
    }

}

void PreguntaForm::finalizar()
{
    m_cuestionario->terminar();
    emit cuestionarioFinalizado(m_cuestionario);
    // Cerrar la ventana
    this->parentWidget()->close();
}

void PreguntaForm::on_buttonBox_rejected()
{
    finalizar();
}


void PreguntaForm::on_buttonBox_accepted()
{
    siguiente();
}

