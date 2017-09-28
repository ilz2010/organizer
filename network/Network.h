#ifndef ORGANIZER_NETWORK_H
#define ORGANIZER_NETWORK_H

#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QMap>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <network/NCrypt.h>

class NCrypt;

class Network : public QObject {
	NCrypt *crypt;

	QNetworkAccessManager manager;

	QJsonObject lastReply;
	int lastTime, lastCode;
	QNetworkReply::NetworkError lastError;


	QUrl prepareReq(QString path);

	QJsonValue processReq(QNetworkReply *rep);

	QJsonValue req_POST(QString path, QMap<QString, QString> params);

	QJsonValue req_POST(QString path, QHttpMultiPart *part);

//	QString req_GET(QString path, QMap<QString, QString> params);

public:
	Network();

	void uploadFile(QString path, QString file);

	QJsonValue request(QString path, QMap<QString, QString> params = {});


	QString getLastTime();

	QString getLastCode();

//	QString getParameter(QString par);

	void checkEncryption();

	friend class NAuth;

	void writeToLog(QString qString, QMap<QString, QString> map, QString type, QJsonArray tries = QJsonArray());
};


#endif //ORGANIZER_NETWORK_H
