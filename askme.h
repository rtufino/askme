#ifndef ASKME_H
#define ASKME_H

#include <QMainWindow>
#include <QMdiSubWindow>

#include "apunteform.h"
#include "cuestionarioform.h"
#include "preguntaform.h"

#include "asignatura.h"


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

private:
    Ui::Askme *ui;
    void cargarSubVentana(QWidget *ventana);
    void cargarDatos();

    QList<Asignatura*> m_asignaturas;

};
#endif // ASKME_H
