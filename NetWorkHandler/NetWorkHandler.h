#pragma once

#include "networkhandler_global.h"
#include <QJsonObject>
#include <QJsonDocument>

#define HostIp "192.168.20.129"

//�Զ���Э���
class NETWORKHANDLER_EXPORT NetWorkHandler
{
public:
	enum dateType {
		none,               //��   0
		regist,             //ע��
		login,              //��¼
		//chat                //����
	};
	
public:
	NetWorkHandler(dateType type = NetWorkHandler::none);

	NetWorkHandler::dateType getType() const { return type; }
	void setType(NetWorkHandler::dateType val) { type = val; }

	QJsonValue operator[](const QString &key) const;
	QJsonValueRef operator[](const QString &key);

	QByteArray pack();	//���
	int unpack(QByteArray byte);	//���
private:
	dateType    type;          //��ͷ
	QJsonObject body;          //����         ��ֵ��
};