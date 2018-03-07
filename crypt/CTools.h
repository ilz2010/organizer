/*
	Copyright (c) 2017 by Ilya Barykin
	Released under the MIT License.
	See the provided LICENSE.TXT file for details.
*/

#ifndef ORGANIZER_CTOOLS_H
#define ORGANIZER_CTOOLS_H

#include <Qca-qt5/QtCrypto/QtCrypto>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonArray>


#define select_if(from, to, predicate) std::copy_if((from).begin(), (from).end(), std::back_inserter(to), predicate)


class CTools {
public:
    static QCA::SecureArray fromBase(const QString &str);

    static QString toBase(const QCA::SecureArray &mem);

    static QString hash(const QString &str);

    static QString toJson(QJsonArray ob, QJsonDocument::JsonFormat format = QJsonDocument::Compact);

    static QString toJson(QJsonObject ob, QJsonDocument::JsonFormat format = QJsonDocument::Compact);

    static QJsonObject fromJson(const QString &str);

    static QJsonArray fromJsonA(const QString &str);

    static QString randomStr(int size);

    static QDate dateFromString(const QString &date);

    static QJsonArray arrayToJson(const QStringList &list);

    static QStringList arrayFromJson(const QJsonValue &value);
};


#endif //ORGANIZER_CTOOLS_H
