#include "property.h"

Property::Property(QObject *parent) : QObject(parent)
{

}

QString Property::mask() const
{
    return m_mask;
}

void Property::setMask(QString mask)
{
    m_mask=mask;
    emit maskChanged(mask);
}
