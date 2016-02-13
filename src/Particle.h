#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>

namespace mac {

struct Particle {

	double m_x;
	double m_y;

	Particle();
	virtual ~Particle();
};

}

#endif
