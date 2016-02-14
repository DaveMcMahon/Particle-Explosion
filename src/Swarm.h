#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace mac {

class Swarm {

public:
	const static int NPARTICLES = 100000;

private:
	Particle* m_pParticles;

public:
	Swarm();
	virtual ~Swarm();
	void update();

	const Particle* const getParticles() {
		return m_pParticles;
	}
};

}

#endif
