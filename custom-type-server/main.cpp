#include <QCoreApplication>
#include <QDBusArgument>
#include <QDBusConnection>
#include <QDBusMetaType>

#include "adaptor.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject o;
    new Adaptor(&o);

    auto conn = QDBusConnection::sessionBus();
    conn.registerObject("/", &o);
    conn.registerService("org.customtest");

    return a.exec();
}
