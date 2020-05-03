#include <QCoreApplication>
#include <QDBusArgument>
#include <QDBusInterface>
#include <QDBusMetaType>
#include <QDBusReply>
#include <QDebug>

#include "../custom-type-server/adaptor.hpp"

int main(int argc, char *argv[])
{
    qDBusRegisterMetaType<Person>();
    QCoreApplication a(argc, argv);

    auto server = new QDBusInterface("org.customtest", "/", "org.customtest",
        QDBusConnection::sessionBus());

    QDBusReply<Person> reply = server->call("person");

    if (reply.isValid()) {
        qDebug() << reply.value().name << reply.value().age;
    }

    return a.exec();
}
