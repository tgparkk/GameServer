#pragma once

class Session;

enum class EventType : uint8
{
	Connect,
	Accept,
	//PreRecv, // 0 byte recv
	Recv,
	Send
};

/*--------------
	IocpEvent
---------------*/

class IocpEvent : public OVERLAPPED // 이렇게 하면 OVERLAPPED 의 
{									// 포인터 주소와 
public:								// 내가 만든 IocpEvent 포인터 주소
	IocpEvent(EventType type);		// 동일

	void		Init();

public:
	EventType		eventType;
	IocpObjectRef	owner;
};

/*----------------
	ConnectEvent
-----------------*/

class ConnectEvent : public IocpEvent
{
public:
	ConnectEvent() : IocpEvent(EventType::Connect) {}
};

/*----------------
	AcceptEvent
-----------------*/

class AcceptEvent : public IocpEvent
{
public:
	AcceptEvent() : IocpEvent(EventType::Accept) {}

public:
	SessionRef  session = nullptr;
};

/*----------------
	RecvEvent
-----------------*/

class RecvEvent : public IocpEvent
{
public:
	RecvEvent() : IocpEvent(EventType::Recv) {}
};

/*----------------
	SendEvent
-----------------*/

class SendEvent : public IocpEvent
{
public:
	SendEvent() : IocpEvent(EventType::Send) {}
};