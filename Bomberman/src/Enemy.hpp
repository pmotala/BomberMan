#pragma once

#include <Swallow.hpp>

class Level;

class Enemy : public Swallow::GameObject
{
public:
	Enemy(const glm::vec3&, Level&);
	Enemy(const Enemy&) = delete;
	Enemy& operator=(const Enemy&) = delete;
	
	void makeDecision();
	glm::vec3& Destination();
	void Update(Swallow::Timestep ts);
	inline bool CanDelete() { return m_Delete; }
	inline void SetDelete(bool b) { m_Delete = b; }

	~Enemy();

private:
	glm::vec3							m_Destination;
	Level								&m_Level;
	Swallow::Ref<Swallow::GameObject>	m_Cube;
	glm::vec3							m_MoveDir;
	bool								m_Delete = false;

protected:
	Enemy() = delete;

};