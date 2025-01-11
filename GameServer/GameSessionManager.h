#pragma once

class GameSession;

using GameSessionRef = shared_ptr<GameSession>;

class GameSessionManager
{
public:
	void Add(std::shared_ptr<GameSession> session);
	void Remove(std::shared_ptr<GameSession> session);
	void Broadcast(std::shared_ptr<SendBuffer> sendBuffer);

private:
	USE_LOCK;
	std::set<std::shared_ptr<GameSession>> _sessions;
};

extern GameSessionManager GSessionManager;
