/*
	Copyright (c) 2017-2018 by Ilya Barykin
	Released under the MIT License.
	See the provided LICENSE.TXT file for details.
*/

#ifndef ORGANIZER_SMVER0_H
#define ORGANIZER_SMVER0_H

#include "storage/migrations/SMigration.h"


class SMVer0 : public SMigration {
public:
    std::string getVersion() override;

    void processF(json_o &o) override;

    void processD(json_o &o) override;
};


#endif //ORGANIZER_SMVER0_H
