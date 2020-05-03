#include "adaptor.hpp"

Adaptor::Adaptor(QObject *obj) : QDBusAbstractAdaptor(obj) {
    qRegisterMetaType<Person>("Person");
    qDBusRegisterMetaType<Person>();
}

Person Adaptor::person() {
    return Person{"Gordon", 30};
}
