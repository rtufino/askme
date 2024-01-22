#ifndef PREGUNTAFORM_H
#define PREGUNTAFORM_H

#include <QWidget>
#include <QDebug>

#include "cuestionario.h"

namespace Ui {
class PreguntaForm;
}

class PreguntaForm : public QWidget
{
    Q_OBJECT

public:
    explicit PreguntaForm(QWidget *parent = nullptr);
    ~PreguntaForm();

    void setCuestionario(Cuestionario *newCuestionario);

signals:
    void cuestionarioFinalizado(Cuestionario *cuestionario);

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

private:
    Ui::PreguntaForm *ui;
    Cuestionario *m_cuestionario;
    Pregunta *m_pregunta;

    void cargarDatos();
    void siguiente();
    void obtenerPregunta();
    void finalizar();
};

#endif // PREGUNTAFORM_H
