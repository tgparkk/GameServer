#pragma once
#include "NetAddress.h"
#include "IocpCore.h"
#include "Listener.h"
#include <functional>

enum class ServiceType : uint8
{
	Server,
	Client
};

/*-------------
	Service
--------------*/

using SessionFactory = function<std::shared_ptr<Session>(void)>;

class Service : public enable_shared_from_this<Service>
{
public:
	Service(ServiceType type, NetAddress address, std::shared_ptr<IocpCore> core, SessionFactory factory, int32 maxSessionCount = 1);
	virtual ~Service();

	virtual bool		Start() abstract;
	bool				CanStart() { return _sessionFactory != nullptr; }

	virtual void		CloseService();
	void				SetSessionFactory(SessionFactory func) { _sessionFactory = func; }

	void				Broadcast(std::shared_ptr<SendBuffer> sendBuffer);
	std::shared_ptr<Session>			CreateSession();
	void				AddSession(std::shared_ptr<Session> session);
	void				ReleaseSession(std::shared_ptr<Session> session);
	int32				GetCurrentSessionCount() { return _sessionCount; }
	int32				GetMaxSessionCount() { return _maxSessionCount; }

public:
	ServiceType			GetServiceType() { return _type; }
	NetAddress			GetNetAddress() { return _netAddress; }
	std::shared_ptr<IocpCore>& GetIocpCore() { return _iocpCore; }

protected:
	USE_LOCK;
	ServiceType			_type;
	NetAddress			_netAddress = {};
	std::shared_ptr<IocpCore>			_iocpCore;

	std::set<std::shared_ptr<Session>>		_sessions;
	int32				_sessionCount = 0;
	int32				_maxSessionCount = 0;
	SessionFactory		_sessionFactory;
};

/*-----------------
	ClientService
------------------*/

class ClientService : public Service
{
public:
	ClientService(NetAddress targetAddress, std::shared_ptr<IocpCore> core, SessionFactory factory, int32 maxSessionCount = 1);
	virtual ~ClientService() {}

	virtual bool	Start() override;
};


/*-----------------
	ServerService
------------------*/

class ServerService : public Service
{
public:
	ServerService(NetAddress targetAddress, std::shared_ptr<IocpCore> core, SessionFactory factory, int32 maxSessionCount = 1);
	virtual ~ServerService() {}

	virtual bool	Start() override;
	virtual void	CloseService() override;

private:
	std::shared_ptr<Listener>		_listener = nullptr;
};