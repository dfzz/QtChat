#pragma once

#include "networkhandler_global.h"
#include <QJsonObject>
#include <QJsonDocument>

#define HostIp "192.168.20.129"
#define Port 12345
#define MainPort 11111

//自定义协议包
class NETWORKHANDLER_EXPORT NetWorkHandler
{
public:
	enum dateType {
		none,               //空   0
		regist,             //注册
		login,              //登录
		offline,			//下线
		online,				//上线
		//chat               //聊天
		createroom,			//创建群聊


		success = 100,
		fail
	};
	
public:
	NetWorkHandler(dateType type = NetWorkHandler::none);

	NetWorkHandler::dateType getType() const { return type; }
	void setType(NetWorkHandler::dateType val) { type = val; }

	QJsonValue operator[](const QString &key) const
	{
		return body[key];
	}
	QJsonValueRef operator[](const QString &key)
	{
		return body[key];
	}

	QByteArray pack();	//封包
	int unpack(QByteArray byte);	//解包
private:
	dateType    type;          //包头
	QJsonObject body;          //包体         键值对
};
