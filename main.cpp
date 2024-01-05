#include "askme.h"

#include <QApplication>
#include <QDebug>

#include "asignatura.h"
#include "cuestionario.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Askme w;
    w.show();

    Apunte *ap1 = new Apunte ("Función", "Una función de dependencia entre A y B");
    Apunte *ap2 = new Apunte ("Derivada", "Correspondencia entre el signo y el crecimiento o decrecimiento de una la función original");

    Tema t("Ecuaciones de primer grado");
    t.agregarApunte(ap1);
    t.agregarApunte(ap2);

    //qDebug().noquote() << t.toString();

    Tema *t2 = new Tema("Electromagnetismo");
    t2->agregarApunte(new Apunte("Campo eléctrico", "Región del espacio alrededor de una carga eléctrica donde actúa una fuerza eléctrica sobre otras cargas."));
    t2->agregarApunte(new Apunte("Ley de Ampère","Relación matemática que describe la circulación de un campo magnético alrededor de un conductor por el cual fluye una corriente eléctrica."));

    //qDebug().noquote() << t2->toString();

    Tema *t3 = new Tema("Óptica");
    t3->agregarApunte(new Apunte("Luz","Radiación electromagnética visible por el ojo humano, que se propaga en forma de ondas."));
    t3->agregarApunte(new Apunte("Reflexión","Cambio de dirección de un rayo de luz cuando incide sobre una superficie."));

    //qDebug().noquote() << t3->toString();

    Asignatura asignatura1("Fisica");
    asignatura1.agregarTema(t2);
    asignatura1.agregarTema(t3);

    //qDebug().noquote() << asignatura1.toString();
    // Crear cuestionario
    Cuestionario quiz(t2);
    // Imprimir lista de terminos
    qDebug() << quiz.terminos();

    // Obtener una pregunta
    Pregunta *p = quiz.siguiente();
    // imprimir
    qDebug().noquote() << p->toString();
    // responder
    p->responder("Campo eléctrico");
    // volver a imprinir
    qDebug().noquote() << p->toString();

    // Obtener otra pregunta e imprimir
    p = quiz.siguiente();
    qDebug().noquote() << p->toString();


    return a.exec();
}














