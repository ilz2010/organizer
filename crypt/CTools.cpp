/*
	Copyright (c) 2017 by Ilya Barykin
	Released under the MIT License.
	See the provided LICENSE.TXT file for details.
*/

#include <QtCore/QJsonObject>
#include "CTools.h"

QCA::SecureArray CTools::fromBase(const QString &str) {
    QCA::Base64 base;
    QCA::MemoryRegion reg(str.toUtf8());

    return QCA::SecureArray(base.decode(reg));
}

QString CTools::toBase(const QCA::SecureArray &mem) {
    QCA::Base64 base;

    return QString::fromUtf8(base.encode(mem).toByteArray());
}

QString CTools::hash(const QString &str) {
    QCA::Hash hash("sha256");

    return hash.hashToString(str.toStdString().c_str());
}

QString CTools::toJson(QJsonArray ob, QJsonDocument::JsonFormat format) {
    return QString::fromUtf8(QJsonDocument(ob).toJson(format));
}

QString CTools::toJson(QJsonObject ob, QJsonDocument::JsonFormat format) {
    return QString::fromUtf8(QJsonDocument(ob).toJson(format));
}

QJsonObject CTools::fromJson(const QString &str) {
    return QJsonDocument::fromJson(str.toUtf8()).object();
}

QJsonArray CTools::fromJsonA(const QString &str) {
    return QJsonDocument::fromJson(str.toUtf8()).array();
}

QString CTools::randomStr(int size) {
    QCA::MemoryRegion mem = QCA::Random::randomArray(size);

    return toBase(mem);
}

QDate CTools::dateFromString(const QString &date) {
    return QDateTime::fromSecsSinceEpoch(date.toULongLong()).date();
}

QJsonArray CTools::arrayToJson(const QStringList &list) {
    QJsonArray r;
    for (const QString &s : list) r << s;
    return r;
}

QStringList CTools::arrayFromJson(const QJsonValue &value) {
    QStringList r;
    for (const auto &s : value.toArray()) r << s.toString();
    return r;
}
