#include "SMVer1.h"
#include <crypt/CTools.h>

int SMVer1::getVersion() {
    return 1;
}

QJsonObject SMVer1::processF(QJsonObject o) {
    QString d = o["docs"].toString();

    // Collect all docs to one array
    QJsonArray r;
    QJsonObject doc, obj = CTools::fromJson(d);

    doc = obj["documents"].toObject();
    for (const QString &v : doc.keys()) {
        r << doc[v];
    }

    doc = obj["links"].toObject();
    for (const QString &v : doc.keys()) {
        QJsonObject t = doc[v].toObject();

        t["type"] = 2;

        r << t;
    }

    o["docs"] = CTools::toJson(r);
    o["version"] = getVersion();

    return o;
}

QJsonObject SMVer1::processD(QJsonObject o) {
    switch (o["type"].toInt()) {
        case 0:
            o["content"] = o["text"].toString();
            o["type"] = 1;
            o.remove("text");
            break;

        case 1:
            o["content"] = o["lines"].toArray();
            o["type"] = 2;
            o.remove("lines");
            break;

        case 2:
            o["content"] = o["links"].toArray();
            o["type"] = 4;
            o.remove("links");
            break;

        default:;
    }

    o["version"] = getVersion();
    return o;
}