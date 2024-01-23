#ifndef ASKME_H
#define ASKME_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QFile>

#include "apunteform.h"
#include "cuestionarioform.h"
#include "preguntaform.h"
#include "resultadosform.h"
#include "listaform.h"

#include "asignatura.h"
#include "tema.h"
#include "apunte.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Askme; }
QT_END_NAMESPACE

class Askme : public QMainWindow
{
    Q_OBJECT

public:
    Askme(QWidget *parent = nullptr);
    ~Askme();

public slots:
    void on_apunteTomado(Apunte *apunte);
    void on_cuestionarioCreado(Cuestionario *cuestionario);
    void on_cuestionarioFinalizado(Cuestionario *cuestionario);

private slots:
    void on_actionNuevo_triggered();

    void on_actionGenerar_triggered();

    void on_actionSalir_triggered();

    void on_actionLista_triggered();

private:
    Ui::Askme *ui;
    void cargarSubVentana(QWidget *ventana);
    void cargarDatos();
    void guardarDatos();

    QList<Asignatura*> m_asignaturas;
    const QString ARCHIVO = "apuntes.csv";

};
#endif // ASKME_H
