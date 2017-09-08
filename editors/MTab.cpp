#include <QtCore/QTimer>
#include <QtCore/QDateTime>
#include <storage/Storage.h>
#include "MTab.h"

MTab::MTab(const QJsonObject &o, TabType t) {
    obj = o;
    name = obj["name"].toString();
    type = t;
    u_last = static_cast<qint64>(o["last_updated"].toDouble());
}

void MTab::updated() {
	if (timer_not_started) {
		auto *u_timer = new QTimer();

		connect(u_timer, &QTimer::timeout, this, &MTab::saveStorage);

		u_last = QDateTime::currentMSecsSinceEpoch();
		u_timer->start(400);

		timer_not_started = false;
	}

	u_time = QDateTime::currentMSecsSinceEpoch();
}

void MTab::saveStorage() {
	if (u_time >= u_last && (u_time + 2000 < QDateTime::currentMSecsSinceEpoch())) {
		u_last = QDateTime::currentMSecsSinceEpoch();
		Storage::getInstance()->saveJson();
	}
}

void MTab::load(QJsonObject o) {
//	qint64 n_last = static_cast<qint64>(o["last_updated"].toDouble());
//
//	if (n_last > u_last)

	if (o.empty()) {
		fromJson(obj["content"]);
		loadCustomParams(obj);
	} else {
		fromJson(o["content"]);
		loadCustomParams(o);
	}
}

QJsonObject MTab::save() {
	obj["content"] = toJson();
	obj["last_updated"] = u_last;
    obj["type"] = type;

	QJsonObject cust = saveCustomParams();
	for (QString k : cust.keys()) {
		obj[k] = cust[k];
	}

	return obj;
}