/*
 * Copyright (C) 2003-2007  Justin Karneges <justin@affinix.com>
 * Copyright (C) 2004,2005  Brad Hards <bradh@frogmouth.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301  USA
 *
 */

#ifndef SIMPLE_OSSL_HASH_H
#define SIMPLE_OSSL_HASH_H

#include <openssl/ossl_typ.h>
#include <openssl/evp.h>
#include <QtCore/QByteArray>
#include <QtCore/QString>
#include "Utils.h"


namespace SimpleOSSL {
    class Hash {
        const EVP_MD *m_algorithm;
        EVP_MD_CTX m_context;

    public:
        explicit Hash(const EVP_MD *algorithm = EVP_sha256());

        ~Hash();

        void clear();

        void update(const QByteArray &a);

        QByteArray final();

        QByteArray process(const QByteArray &a);

        QString hashToString(const QByteArray &a);
    };
}

#endif //SIMPLE_OSSL_HASH_H