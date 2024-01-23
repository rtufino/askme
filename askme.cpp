#include "askme.h"
#include "ui_askme.h"

Askme::Askme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Askme)
{
    ui->setupUi(this);
    cargarDatos();
}

Askme::~Askme()
{
    delete ui;
}

void Askme::on_apunteTomado(Apunte *apunte)
{
    guardarDatos();
}

void Askme::on_cuestionarioCreado(Cuestionario *cuestionario)
{
    PreguntaForm *w = new PreguntaForm(this);
    w->setCuestionario(cuestionario);

    connect(w,SIGNAL(cuestionarioFinalizado(Cuestionario*)), this, SLOT(on_cuestionarioFinalizado(Cuestionario *)));

    cargarSubVentana(w);
}

void Askme::on_cuestionarioFinalizado(Cuestionario *cuestionario)
{
    ResultadosForm *w = new ResultadosForm(this);
    w->setCuestionario(cuestionario);

    cargarSubVentana(w);
}

void Askme::cargarSubVentana(QWidget *ventana)
{
    auto sub = ui->mdiArea->addSubWindow(ventana);
    sub->show();
}

void Askme::cargarDatos()
{
    // Verificar si el archivo existe
    QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;
    // variables adicionales
    QString asignatura = "";
    QString tema = "";
    int indexA = -1;
    int indexT = -1;
    // cargar datos
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split("\t");
            // Crear asignatura y agregar a la lista
            if (datos[0] != asignatura){
                asignatura = datos[0];
                m_asignaturas.append(new Asignatura(asignatura));
                indexA++;
                indexT = -1;
            }
            // Crear tema y agregar a la asignatura
            if (datos[1] != tema){
                tema = datos[1];
                m_asignaturas.at(indexA)->agregarTema(new Tema(tema));
                indexT++;
            }
            // Agregar apuntes a cada tema
            m_asignaturas.at(indexA)->temas().at(indexT)->agregarApunte(new Apunte(datos[2], datos[3]));
        }
        archivo.close();
    }
}

void Askme::guardarDatos()
{
    // Abrir el archivo y guardar
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        // recorrer la lista de asignaturas
        foreach (Asignatura *a, m_asignaturas) {
            QString asignatura = a->nombre();
            // recorrer la lista de temas por asignatura
            foreach (Tema *t, a->temas()){
                QString tema = t->nombre();
                // recorrer los apuntes por cada tema
                foreach (Apunte *ap, t->apuntes()){
                    salida << asignatura << "\t" << tema << "\t";
                    salida << ap->termino() << "\t" << ap->concepto() << "\n";
                }
            }
        }
        archivo.close();
        QMessageBox::information(this,"Guardar apuntes","Apuntes guardados con éxito");
    }else{
        QMessageBox::critical(this,"Guardar apuntes", "No se puede escribir sobre " + ARCHIVO);
    }
}


void Askme::on_actionNuevo_triggered()
{
    ApunteForm *w = new ApunteForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();

    connect(w, SIGNAL(apunteTomado(Apunte*)), this, SLOT(on_apunteTomado(Apunte*)));

    cargarSubVentana(w);
}


void Askme::on_actionGenerar_triggered()
{
    CuestionarioForm *w = new CuestionarioForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();

    connect(w, SIGNAL(cuestionarioCreado(Cuestionario*)), this, SLOT(on_cuestionarioCreado(Cuestionario*)));

    cargarSubVentana(w);
}


void Askme::on_actionSalir_triggered()
{
    this->close();
}


void Askme::on_actionLista_triggered()
{
    ListaForm *w = new ListaForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();

    cargarSubVentana(w);
}

