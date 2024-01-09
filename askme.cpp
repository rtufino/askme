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

void Askme::cargarSubVentana(QWidget *ventana)
{
    auto sub = ui->mdiArea->addSubWindow(ventana);
    sub->show();
}

void Askme::cargarDatos()
{
    Tema *t1 = new Tema("Electromagnetismo");
    t1->agregarApunte(new Apunte("Campo eléctrico", "Región del espacio alrededor de una carga eléctrica donde actúa una fuerza eléctrica sobre otras cargas."));
    t1->agregarApunte(new Apunte("Ley de Ampère","Relación matemática que describe la circulación de un campo magnético alrededor de un conductor por el cual fluye una corriente eléctrica."));
    t1->agregarApunte(new Apunte("Ley de Faraday","Principio que establece que un cambio en el flujo magnético a través de una espira induce una fuerza electromotriz (EMF) en la espira."));
    t1->agregarApunte(new Apunte("Bobina","Dispositivo formado por varias vueltas de alambre conductor, utilizado para generar un campo magnético o para inducir corriente."));
    t1->agregarApunte(new Apunte("Ley de Gauss","Principio que relaciona el flujo magnético a través de una superficie cerrada con la suma de las corrientes magnéticas que la atraviesan."));

    Tema *t2 = new Tema("Óptica");
    t2->agregarApunte(new Apunte("Luz","Radiación electromagnética visible por el ojo humano, que se propaga en forma de ondas."));
    t2->agregarApunte(new Apunte("Reflexión","Cambio en la dirección de propagación de la luz al pasar de un medio a otro con diferente índice de refracción."));
    t2->agregarApunte(new Apunte("Refracción","Cambio de dirección de un rayo de luz cuando incide sobre una superficie."));
    t2->agregarApunte(new Apunte("Prisma","Objeto óptico transparente con superficies planas que separa la luz en sus componentes de diferentes longitudes de onda."));
    t2->agregarApunte(new Apunte("Lente","Dispositivo óptico que enfoca o dispersa la luz mediante su curvatura, utilizado en cámaras, anteojos, microscopios, y telescopios."));

    Asignatura *a1 = new Asignatura("Fisica");
    a1->agregarTema(t1);
    a1->agregarTema(t2);

    t1 = new Tema("Ecología");
    t1->agregarApunte(new Apunte("Ecosistema", "Sistema formado por seres vivos y su entorno físico, donde interactúan entre sí y con el ambiente."));
    t1->agregarApunte(new Apunte("Biodiversidad", "Variedad de vida en la Tierra, que incluye la diversidad genética, de especies y de ecosistemas."));
    t1->agregarApunte(new Apunte("Cadena alimentaria", "Serie de organismos interconectados, donde cada uno se alimenta del anterior y es alimento para el siguiente."));
    t1->agregarApunte(new Apunte("Ciclo del agua", "Proceso continuo de circulación del agua entre la atmósfera, la tierra y los cuerpos de agua, que incluye evaporación, condensación y precipitación."));
    t1->agregarApunte(new Apunte("Bioma", "Gran área geográfica con características climáticas similares que alberga una comunidad específica de plantas y animales."));

    t2 = new Tema("Genética");
    t2->agregarApunte(new Apunte("ADN","Ácido desoxirribonucleico, la molécula que contiene la información genética hereditaria en los organismos."));
    t2->agregarApunte(new Apunte("Gen","Unidad de información hereditaria que codifica una característica específica, y que se encuentra en el ADN."));
    t2->agregarApunte(new Apunte("Cromosoma","Estructura compuesta por ADN y proteínas que transporta genes y se encuentra en el núcleo de las células."));
    t2->agregarApunte(new Apunte("Mutación","Cambio en la secuencia de ADN que puede dar lugar a variaciones genéticas."));
    t2->agregarApunte(new Apunte("Herencia","Transmisión de características genéticas de padres a descendencia a través de la reproducción."));

    Asignatura *a2 = new Asignatura("Ciencias naturales");
    a2->agregarTema(t1);
    a2->agregarTema(t2);

    m_asignaturas.append(a1);
    m_asignaturas.append(a2);
}


void Askme::on_actionNuevo_triggered()
{
    ApunteForm *w = new ApunteForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();

    cargarSubVentana(w);
}

