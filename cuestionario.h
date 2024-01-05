#ifndef CUESTIONARIO_H
#define CUESTIONARIO_H

#include <tema.h>
#include <pregunta.h>

class Cuestionario
{
public:
    Cuestionario();
    Cuestionario(Tema *tema);

    Pregunta *siguiente();

    const QStringList &terminos() const;

private:
    float score;
    Tema *m_tema;
    QList<Pregunta*> m_preguntas;
    QStringList m_terminos;
};

#endif // CUESTIONARIO_H
