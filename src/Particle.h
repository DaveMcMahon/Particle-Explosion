#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <Math.h>

namespace mac {

struct Particle {

	double m_speed;
	double m_direction;

	double m_x;
	double m_y;

	Particle();
	virtual ~Particle();

	void update();

};

}

#endif
