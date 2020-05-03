#pragma once

#include <QDBusArgument>
#include <QDBusAbstractAdaptor>
#include <QDBusMetaType>
#include <QDBusReply>

struct Person {
    QString name;
    int age;
    friend QDBusArgument &operator<<(QDBusArgument &a, const Person p) {
        a.beginStructure();
        a << p.name << p.age;
        a.endStructure();
        return a;
    }
    friend const QDBusArgument &operator>>(const QDBusArgument &a, Person p) {
        a.beginStructure();
        a >> p.name >> p.age;
        a.endStructure();
        return a;
    }
};

Q_DECLARE_METATYPE(Person)

class Adaptor : public QDBusAbstractAdaptor {
private:
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.customtest")
public:
    Adaptor(QObject *obj);
public Q_SLOTS:
    Person person();
};
