//This class is meant to contain all functions that push individual particles and increment their velocities in time.
#include "poisson_solver.hpp"
#include "num_density.hpp"
#include "vel_dist.hpp"

#ifndef PARTICLE_MOVER_HPP_
#define PARTICLE_MOVER_HPP_

class ParticleMover
{
private:

	double t = 0.;
    double t_max = 200.; // in terms of 1 / omega = sqrt((m*eps) / (500000*e*e))  ~ 2.506590041516934e-05
    double dt = 0.1; // in terms of 1 / omega = sqrt((m*eps) / (500000*e*e)) ~ 2.506590041516934e-05
    int iter = 0;
    double K = 0.;
    double U = 0.;

public:

    //Constructor
    ParticleMover();
    //Destructor
    ~ParticleMover();


    //Getters
    double getTmax();
    double getDt();
    int getIter();
    double getK();
    double getU();

    //Setters
    void setTmax(double);
    void setDt(double);
    void setIter();
    void setK(VelDist*);
    void setU(PoissonSolver*,VelDist*);

    //General functions.
    void xIncr(NumDensity*,VelDist*);
    void vIncr(PoissonSolver*,VelDist*, int);
    

};

#endif