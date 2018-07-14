/*
	Copyright (c) 2017-2018 by Ilya Barykin
	Released under the MIT License.
	See the provided LICENSE.TXT file for details.
*/

#ifndef ORGANIZER_TLINKSGROUP_H
#define ORGANIZER_TLINKSGROUP_H

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QScrollArea>
#include <tabs/links/TLink.h>
#include <tabs/Tab.h>

class TLink;


class TLinksGroup : public Tab {
    QList<TLink *> links;

    QVBoxLayout *list;


public:
    explicit TLinksGroup(const QJsonObject &o);

    void addLink(QJsonObject o = QJsonObject());

    void updateLinks();

    void fromJson(QJsonValue v) override;

    QJsonValue toJson() override;
};


#endif //ORGANIZER_TLINKSGROUP_H