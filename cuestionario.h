#ifndef CUESTIONARIO_H
#define CUESTIONARIO_H

#include <tema.h>
#include <pregunta.h>

class Cuestionario
{
public:
    Cuestionario();
    Cuestionario(QString asignatura, Tema *tema);

    Pregunta *siguiente();
    void terminar();
    const QStringList &terminos() const;

    float score() const;

    const QList<Pregunta *> &preguntas() const;
    const QString nombreTema() const;
    int totalPreguntas();
    bool hayMasPreguntas();

    int mostradas() const;

    const QString &asignatura() const;
    void setAsignatura(const QString &newAsignatura);

private:
    float m_score;
    Tema *m_tema;
    QString m_asignatura;
    QList<Pregunta*> m_preguntas;
    QStringList m_terminos;
    int m_mostradas;
};

#endif // CUESTIONARIO_H
