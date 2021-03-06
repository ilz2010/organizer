/*
	Copyright (c) 2017-2018 by Ilya Barykin
	Released under the MIT License.
	See the provided LICENSE.TXT file for details.
*/

#include <vars.h>
#include "PTabFile.h"

PTabFile::PTabFile(const json_o &o) {
    name = o["name"].get<QString>();
    name_enc = o["name_enc"].get<QString>();
    hash = o["hash"].get<QString>();
    size = o["size"].get<QString>();
    type = o["type"].get<QString>();
}

PTabFile::PTabFile(const QFileInfo &f) {
    name = f.fileName();
    hash = processHash(f);
    size = processSize(f);
    type = processType(f);
}

json_o PTabFile::toJson() {
    return json_o{
            {"name",     name},
            {"name_enc", name_enc},
            {"hash",     hash},
            {"size",     size},
            {"type",     type}
    };
}

QString PTabFile::processHash(const QFileInfo &f) {
    return Crypt::hashFile(f.absoluteFilePath());
}

QString PTabFile::processSize(const QFileInfo &f) {
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

QString PTabFile::processType(const QFileInfo &f) {
    return f.completeSuffix();
}

void PTabFile::processName(CAes &aes) {
    name_enc = aes.encrypt(name);
    name_enc = name_enc.replace('/', '-');
}
