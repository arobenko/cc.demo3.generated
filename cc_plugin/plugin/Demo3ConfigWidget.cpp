#include "Demo3ConfigWidget.h"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

namespace demo3
{

namespace cc_plugin
{

namespace plugin
{

Demo3ConfigWidget::Demo3ConfigWidget(int version){
    auto* versionLabel = new QLabel("Default Version:");
    auto* versionSpinBox = new QSpinBox;
    versionSpinBox->setMaximum(99999999);
    versionSpinBox->setValue(version);
    auto* versionSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    auto* versionLayoutLayout = new QHBoxLayout();
    versionLayoutLayout->addWidget(versionLabel);
    versionLayoutLayout->addWidget(versionSpinBox);
    versionLayoutLayout->addItem(versionSpacer);

    auto* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    auto* verticalLayout = new QVBoxLayout(this);
    verticalLayout->addLayout(versionLayoutLayout);
    verticalLayout->addItem(verticalSpacer);

    setLayout(verticalLayout);

    connect(
        versionSpinBox, SIGNAL(valueChanged(int)),
        this, SLOT(versionChanged(int)));
}

void Demo3ConfigWidget::versionChanged(int value)
{
    if (m_versionUpdateCb) {
        m_versionUpdateCb(value);
    }
}

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


