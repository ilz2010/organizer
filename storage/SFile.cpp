#include <vars.h>
#include <Qca-qt5/QtCrypto/QtCrypto>
#include "SFile.h"

SFile::SFile(const QJsonObject &o) {
    name = o["name"].toString();
    name_enc = o["name_enc"].toString();
    hash = o["hash"].toString();
    size = o["size"].toString();
    type = o["type"].toString();
}

SFile::SFile(const QFileInfo &f) {
    name = f.fileName();
    hash = processHash(f);
    size = processSize(f);
    type = processType(f);
}

QJsonObject SFile::toJson() {
    return QJsonObject{
            {"name",     name},
            {"name_enc", name_enc},
            {"hash",     hash},
            {"size",     size},
            {"type",     type}
    };
}

QString SFile::processHash(const QFileInfo &f) {
    QCA::Hash hash(FILE_HASH);

    QFile f_in(f.absoluteFilePath());
    f_in.open(QFile::ReadOnly);

    QByteArray data;
    do {
        data = f_in.read(FILES_BUFFER_SIZE);
        hash.update(data);
    } while (data.size() != 0);

    return hash.final().toByteArray().toHex();
}

QString SFile::processSize(const QFileInfo &f) {
    double size = f.size();
    QString suffix;

    if (size < FILE_KILOBYTE) {
        suffix = "B";

    } else if (size < FILE_MEGABYTE) {
        suffix = "KB";
        size /= FILE_KILOBYTE;

    } else if (size < FILE_GIGABYTE) {
        suffix = "MB";
        size /= FILE_MEGABYTE;

    } else {
        suffix = "GB";
        size /= FILE_GIGABYTE;
    }

    return QString("%1 %2").arg(size, 6, 'f', 2, ' ').arg(suffix);
}

QString SFile::processType(const QFileInfo &f) {
    return f.completeSuffix();
}

void SFile::processName(CAes &aes) {
    name_enc = aes.encrypt(name);
}
